# ProyectoAjedrez
Proyecto final del curso de Programación bajo plataformas abiertas
Esta versión contiene una estructura simplificada para presentar el juego.
Existe otra rama con la implementación de un modelo cliente-servidor.

### Instrucciones
Se compila `gcc main.c movida.c -o juego`. Se ingresan los comando de acuerdo a la colunma y fila de la ficha que se desea mover y su destino, `a6 a4` o comandos como `retirar` o `finalizar`.

Nota: Este programa se optimizó para replit, pero puede ejecutarse para cualquier entorno GNU/Linux además de Windows, solo cambiar el valor para limpiar la consola de acuerdo al SO `system("cls")` o `system("clear")` en la línea 40.
