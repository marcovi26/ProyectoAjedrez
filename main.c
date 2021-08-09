//Programa Tablero de ajedrez
//Marco Araya Villalobos

#include <stdio.h>  // Libreria base para printf entre otras
#include <ctype.h>  // Para utilizar tupper
#include <stdlib.h> // Para system entre otras
#include "movida.h" // Archivo de cabecera para las funciones de movimientos

//Librerias para programación de sockets
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


struct Ajedrez
{
  char tab[8][8]; //Definimos el tablero de ajedrez como una matriz 8x8
};
struct Ajedrez tablero;

int fin = 0;    //Una variable para terminar un bucle de juego que cambia entre jugador 1 y 2
enum color {BLANCO, NEGRO};
enum color turno;

//Prototipos de funciones
void tab_inicializado();
void tab_lleno();
void leer_jugada(int *i_inicial, int *j_inicial, int *i_final,   int *j_final);
void jugador_blanco();
void jugador_negro();
void cambio_pieza( int f1 , int c1 , int f2 , int c2 );
int finjuego(void);

//variables para la parte de red
int comunicacion=0;
int receptor = 0;
int read_size;
char buffer_entrada[500]="\0";
char buffer_salida[500];


struct sockaddr_in info_servidor;

void EnviarMensaje(char *mensaje) //Función para enviar mensajes al cliente
{
  strcpy(buffer_salida, mensaje);
  write(comunicacion, buffer_salida, strlen(buffer_salida));
}


int main() {

  receptor = socket(AF_INET, SOCK_STREAM, 0);
  info_servidor.sin_family = AF_INET;    
  info_servidor.sin_addr.s_addr = htonl(INADDR_ANY);
  info_servidor.sin_port = htons(8080);   //Puerto de red, se puede cambiar para usar otro distinto, al igual que en el cliente.
  info_servidor.sin_addr.s_addr = inet_addr("127.0.0.1"); //Dirreccion IPv4 de la red, se utiliza la de loopback.

  bind(receptor, (struct sockaddr*)&info_servidor,  sizeof(info_servidor));

  if(listen(receptor, 10) == -1)
  {
      printf("Error en receptor.\n");
      return -1;
  }

  while(1)
  {
    comunicacion = accept(receptor, (struct sockaddr*)NULL, NULL);

    if((read_size = recv(comunicacion , buffer_entrada , 500 , 0)) > 0)
    {
      tab_inicializado(); // Iniciamos el tablero con la posición de las fichas
      
      turno= BLANCO; //Definimos un turno de inicio

      do
      {
        
        tab_lleno(); // imprimimos un display del tablero lleno

        if( (turno) == 0 )
        {
            jugador_blanco();
        }
        else
        {
            jugador_negro();
        }
        turno = 1-turno;   //Con esta operacion hacemos el cambio de turno entre blanco y negro
      }while(fin==0);
    }//fin if
    close(comunicacion);
  }//fin while red

return 0;
}//Final Main


void tab_inicializado(){ //creamos tablero vacío

  char fichas[] = "tcadract";    // Un pequeño arreglo para llenar la fila 0 y 7 del tablero

  for(int i = 0; i<8 ;i++){
    for(int j = 0; j< 8; j++){
      tablero.tab[0][j] = fichas[j];
      
      if(i == 1){
          tablero.tab[i][j] = 'p';
      }
      else if(i == 6){
          tablero.tab[i][j] = 'P';
      }
      else{
        tablero.tab[i][j] = '.';
      }
      tablero.tab[7][j] = toupper(fichas[j]);
  }
}
}//FInal funcion tab_inicializado

void tab_lleno(){
  //Parte del display del tablero
  EnviarMensaje("    a  b  c  d  e  f  g  h \n");
  EnviarMensaje(" +-----------------------+\n");
  for(int i = 0; i<8 ;i++){
      switch(i){
        case 0: EnviarMensaje("0 |");
                      break;
        case 1: EnviarMensaje("1 |");
                      break;
        case 2: EnviarMensaje("2 |");
                      break;
        case 3: EnviarMensaje("3 |");
                      break;
        case 4: EnviarMensaje("4 |");
                      break;
        case 5: EnviarMensaje("5 |");
                      break;
        case 6: EnviarMensaje("6 |");
                      break;
        case 7: EnviarMensaje("7 |");
                      break;
      }
      for(int j = 0; j< 8; j++){

          switch(tablero.tab[i][j])
          {
            case '.': EnviarMensaje(" . ");
                      break;
            case 'p': EnviarMensaje(" p ");
                      break;
            case 'P': EnviarMensaje(" P ");
                      break;
            case 't': EnviarMensaje(" t ");
                      break;
            case 'T': EnviarMensaje(" T ");
                      break;
            case 'a': EnviarMensaje(" a ");
                      break;
            case 'A': EnviarMensaje(" A ");
                      break;
            case 'c': EnviarMensaje(" c ");
                      break;
            case 'C': EnviarMensaje(" C ");
                      break;
            case 'd': EnviarMensaje(" d ");
                      break;
            case 'D': EnviarMensaje(" D ");
                      break;
            case 'r': EnviarMensaje(" r ");
                      break;
            case 'R': EnviarMensaje(" R ");
                      break;
          }
      }
      EnviarMensaje("\n");
    }
}//final tablleno


void jugador_blanco()   //Existen una función para cada jugador
{   int f1, c1;         //Coordenadas posicion inicial de la pieza
    int f2, c2;         //Coordenadas posicion final de la pieza

    EnviarMensaje(" \n Siguiente: Jugador 1 - Blancas - Mayuscula\n" ) ;
    again1:
    again2:
    leer_jugada(&f1, &c1, &f2, &c2); //Leemos la jugada por teclado

    switch( tablero.tab[f1][c1] )
    {/*Con este switch verificamos cual pieza se selecciono para
        Estudiar los movimientos permitidos de cada pieza*/
        case 'P': peonB(&f1,&c1,&f2,&c2, tablero.tab, turno);  
                  if (f2==99)                               // en las funciones de movimientos si algo sale
                  { EnviarMensaje("Error de movimiento");    //mal cambiamos el valor de f2 a numero magico 99
                    goto again2;                            // Y comparamos para ver si salio algo mal y devolvernos.  
                  }
                  break ;
        case 'R': rey(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        case 'C': caballo(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        case 'T': torre(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        case 'A': alfil(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        case 'D': reina(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        default: EnviarMensaje("Posicion invalida ") ; goto again1 ;
    }

//Con esta funcion hacemos el cambio de pieza y verificamos si hay ganador
    cambio_pieza(f1,c1,f2,c2) ;
}//Fin jugador_blanco

void jugador_negro()
{   int f1, c1;  //Coordenadas posicion inicial de la pieza
    int f2, c2;  //Coordenadas posicion final de la pieza


    EnviarMensaje(" \n  Siguiente: Jugador 2 - Negras - minusculas\n" ) ;
    again1:
    again2:
    
    leer_jugada(&f1, &c1, &f2, &c2); //Leemos la jugada por teclado

    switch( tablero.tab[f1][c1] )
    {
        case 'p': peonN(&f1,&c1,&f2,&c2, tablero.tab, turno);
                  if (f2==99)   
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }       
                  break ;
        case 'r': rey(&f1,&c1,&f2,&c2, tablero.tab, turno) ;
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  } 
                  break ;
        case 'c': caballo(&f1,&c1,&f2,&c2, tablero.tab, turno );
                  if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  } 
                  break ;
        case 't': torre(&f1,&c1,&f2,&c2, tablero.tab, turno);
                 if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  } 
                  break ;
        case 'a': alfil(&f1,&c1,&f2,&c2, tablero.tab, turno);
                 if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  } 
                  break ;
        case 'd': reina(&f1,&c1,&f2,&c2, tablero.tab, turno);
                 if (f2==99)
                  { EnviarMensaje("Error de movimiento");
                    goto again2;
                  }
                  break ;
        default: EnviarMensaje("Posicion invalida ") ; goto again1 ;
    }

    cambio_pieza(f1,c1,f2,c2); //Hacemos el cambio de posición de la pieza seleccionada
}//Fin jugador_negro

void leer_jugada(int *f_inicial, int *c_inicial, int *f_final, int *c_final) {
    
    char movida[15];
    inic:
    EnviarMensaje("Indique su movida en formato [cf cf] inicial y final respectivamente o comando de parada (retirar o finalizar):\n");
    read_size = recv(comunicacion , buffer_entrada , 20 , 0); //Obtenemos la movida leyendola del teclado


if (buffer_entrada[3]=='i')   //Verificamos si corresponde al comando retirar
{
  turno=1-turno;  //hacemos cambio de turno para indicar que gana jugador contrario.  
  finjuego();
  exit(-1);
}

else if (buffer_entrada[1]=='i')    //Verificamos si corresponde al comando finalizar
{
  EnviarMensaje("\nPartida finalizada, gracias por jugar y hasta pronto\n");
  exit(-1);
}

else{     //Lectura de movimiento de pieza
        *c_inicial = buffer_entrada[0] - 'a';     //Calculamos un valor numerico para las casillas 
        *f_inicial = buffer_entrada[1] - '0';     // restandole valores ascii a dato de entrada
        *c_final   = buffer_entrada[3] - 'a';
        *f_final   = buffer_entrada[4] - '0';

        //Este if consiste en verificar que la eleccion de casillas corresponda a un valor del rango del tablero
        if (-1<*c_inicial && *c_inicial <8 && -1<*f_inicial && *f_inicial <8 && -1<*c_final && *c_final<8 && -1<*c_final && *c_final <8);
        else{
              EnviarMensaje("Posición fuera de rango\n");
              goto inic;
            }
}
}// fin leer jugada

void cambio_pieza( int f1 , int c1 , int f2 , int c2 ){

    char temp; // para guardar casilla de inicio y cambiarla a la de llegada

    // Verificamos si la casilla de llegada corresponde al rey para finalizar el juego
    if (tablero.tab[f2][c2]== 'r' || tablero.tab[f2][c2]=='R') 
          {
             finjuego();
          }

    temp = tablero.tab[f1][c1];    //Hacemos el cambio de pieza
    tablero.tab[f2][c2] = temp;
    tablero.tab[f1][c1] = '.' ;
}//Fin cambio_pieza

int finjuego(void)
{
/*
Con el turno vemos cual es el ganador y con la variable fin la incrementamos para
salirnos del bucle del main.
*/
    if (turno==0)
        { 
          fin++;
          EnviarMensaje("\n Felicidades!! El jugador 1 (blancas) ha ganado la partida.\n");
        }

    else {
          fin++;
          EnviarMensaje("\n Felicidades!! El jugador 2 (negras) ha ganado la partida.\n");
         }
return 0;
}// Fin función terminar juego
