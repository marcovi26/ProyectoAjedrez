# ProyectoAjedrez
Proyecto final del curso de Programación bajo plataformas abiertas
Esta versión contiene una estructura cliente-servidor por medio de la creación de un socket que se abre en el puerto 8080.

Está versión aun no está terminada, presenta un error a la hora de terminar el juego ya que el cliente se mantiene abierto y no se cierra

### Instrucciones
Se compila `gcc main.c movida.c -o servidor` y `gcc cliente.c -o cliente`. Se ejecuta en ventanas aparte `./servidor` y `./cliente`. Se ingresan los comando de acuerdo a la colunma y fila de la ficha que se desea mover y su destino, `a6 a4` o comandos como `retirar` o `finalizar`.

Nota: Este programa se optimizó para replit, pero puede ejecutarse para cualquier entorno GNU/Linux.
