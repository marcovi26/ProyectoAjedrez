#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#define MAX 13

int main()
{
  int entrada = 0;
  int receptor = 0;
  int comunicacion = 0;
  int bytes_recibidos = 0;
  char buffer_salida[500];
  int read_size=0;

  char buffer_entrada[500];

  struct sockaddr_in info_servidor;

  memset(buffer_entrada, '0', sizeof(buffer_entrada));
  memset(buffer_salida, '0', sizeof(buffer_salida));
  bind(receptor, (struct sockaddr*)&info_servidor,  sizeof(info_servidor));
  if((entrada = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("Error al crear socket de entrada.\n");
      return 1;
  }

  info_servidor.sin_family = AF_INET;
  info_servidor.sin_port = htons(8080); //Puerto tiene que ser el mismo del servidor
  info_servidor.sin_addr.s_addr = inet_addr("127.0.0.1");  //Direccion ip del servidor

  if(connect(entrada, (struct sockaddr *)&info_servidor, sizeof(info_servidor)) < 0)
  {
      printf("Error de conexion con el servidor.\n");
      return 1;
  }

  char input[MAX];
	while(1)
	{
		printf("\nIngrese comando: ");
    fgets(input, MAX, stdin);
		fflush(stdin);
		
    //enviar datos
		if( send(entrada , input , strlen(input) , 0) < 0)
		{
			puts("fallo de envio");
			return 1;
		}
		
    sleep(1);

		//recibir datos     
		if((read_size = recv(entrada , buffer_entrada ,500, 0)) > 0)
    		{
      			fputs(buffer_entrada, stdout);
		    }

    //close(entrada);
  }


  return 0;
}