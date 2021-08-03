//Programa Tablero de ajedrez
// Marco Araya Villalobos
#include <stdio.h> // libreria base para printf entre otras
#include <ctype.h> //para utilizar tupper
#include <stdlib.h> // systen entre otras
#include "movida.h"

//Estos 2 arreglos sirven para contabilizar si es el primer movimiento del peon
//Para verificar si puede hacer los 2 movimientos o si ya se movió, entonces solo 1 movimiento.
int peon_inicial1[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int peon_inicial2[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;

//Prototipos de funciones de comprobación de ficha
int check(int x , int y, char tab[8][8]);
int check2(int x , int y, char tab[8][8]);


void peonB( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno)
{
    peon_inicial1[*c1]++; // condicion inicial para saber si es el primer mov para que pueda moverse 2 casillas.

if (peon_inicial1[*c1] == 1) // If si peon inicial es el primer movimiento
{      
                if (*f2 == *f1-1 && *c2 == *c1 && tab[*f1-1][*c1]=='.')
                    {printf("ok1\n");}
    
                else if (*f2 == *f1-2 && *c2 == *c1 && tab[*f1-1][*c1]== '.' && tab[*f1-2][*c1]== '.')
                    {printf("ok2\n");}

                else if (*f2 == *f1-1 && (*c2 == *c1 -1 || *c2 == *c1 + 1 ))
                    {
                    if (check(*f2,*c2,tab)==1)
                       {printf("ok3\n");}
                    else{
                      printf("Movimiento invalido no puede comer una propia ficha\n");
                      *f2=99;
                      peon_inicial1[*c1]--;
                    }
                    }
        
                else {
                      printf("Movimiento invalido, fuera de rango permitido\n");
                      *f2=99;
                      peon_inicial1[*c1]--;
                      } 
}

else
    {
                if (*f2 == *f1-1 && *c2 == *c1 && tab[*f2][*c2]== '.')
                    {printf("ok2\n");}

                else if (*f2 == *f1-1 && (*c2 == *c1 -1 || *c2 == *c1 + 1 ) )
                    {
                      if (check(*f2,*c2,tab)==1)
                           {printf("ok3\n");}
                      else{
                          printf("Movimiento invalido no puede comer una propia ficha\n");
                          *f2=99;
                          peon_inicial1[*c1]--; }
                    }
        
                else {
                      printf("Movimiento invalido, fuera de rango permitido\n");
                      *f2=99;
                      } 
      }//fin else

}//fin peon blanco


void peonN( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
    peon_inicial2[*c1]++; // condicion inicial para saber si es el primer mov para que pueda moverse 2 casillas.

if (peon_inicial2[*c1] == 1) 
{      
                if (*f2 == *f1+1 && *c2 == *c1 && tab[*f1+1][*c1]=='.')
                    {printf("ok1\n");}
    
                else if (*f2 == *f1+2 && *c2 == *c1 && tab[*f1+1][*c1]== '.' && tab[*f1+2][*c1]== '.')
                    {printf("ok2\n");}

                else if (*f2 == *f1+1 && (*c2 == *c1 -1 || *c2 == *c1 + 1 ))
                    {
                    if (check2(*f2,*c2,tab)==1)
                       {printf("ok3\n");}
                    else{
                      printf("Movimiento invalido no puede comer una propia ficha\n");
                      *f2=99;
                      peon_inicial2[*c1]--;
                    }
                    }
        
                else {
                      printf("Movimiento invalido, fuera de rango permitido\n");
                      *f2=99;
                      peon_inicial2[*c1]--;
                      } 
}

else
    {
                if (*f2 == *f1+1 && *c2 == *c1 && tab[*f2][*c2]== '.')
                      {printf("ok2\n");}

                else if (*f2 == *f1+1 && (*c2 == *c1 - 1 || *c2 == *c1 + 1 ) )
                    {
                      if (check2(*f2,*c2,tab)==1)
                           {printf("ok3\n");}
                      else{
                          printf("Movimiento invalido no puede comer una propia ficha\n");
                          *f2=99;
                          peon_inicial2[*c1]--; }
                    }
        
                else {
                      printf("Movimiento invalido, fuera de rango permitido\n");
                      *f2=99;
                      } 
      }//fin else

}//fin peon Negro


void rey( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
    if(*f2 ==*f1 && *c2==*c1+1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   

          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro        
    }//fin condición 1


    else if(*f2 ==*f1 && *c2==*c1-1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }//Fin condicion 2


    else if(*f2 ==*f1+1 && *c2==*c1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 3


    else if(*f2 ==*f1-1 && *c2==*c1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 4

    else if(*f2 ==*f1+1 && *c2==*c1+1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 5


    else if(*f2 ==*f1-1 && *c2==*c1-1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 6

    else if(*f2 ==*f1-1 && *c2==*c1+1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 7


    else if(*f2 ==*f1+1 && *c2==*c1-1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// condicion 8

    else
    {
      printf("Movimiento invalido, fuera de rango permitido\n");
      *f2=99;
    }// Error
}//Fin rey


void caballo( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
  if(*f2 ==*f1+1 && *c2==*c1+2)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   

          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro        
    }//fin condición 1


    else if(*f2 ==*f1+2 && *c2==*c1+1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }//Fin condicion 2


    else if(*f2 ==*f1+2 && *c2==*c1-1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 3


    else if(*f2 ==*f1+1 && *c2==*c1-2)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 4

    else if(*f2 ==*f1-1 && *c2==*c1-2)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 5


    else if(*f2 ==*f1-2 && *c2==*c1-1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 6

    else if(*f2 ==*f1-2 && *c2==*c1+1)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// fin condicion 7


    else if(*f2 ==*f1-1 && *c2==*c1+2)
    {
          if (turno==0)
               {
                if (check(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n"); 
                  }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }              
               }//fin turno blanco   
               
          else{
                if (check2(*f2,*c2,tab)==1 || tab[*f2][*c2]=='.')
                 {
                   printf("ok\n");
                 }
                 else{
                   printf("Movimiento invalido no puede comer una propia ficha\n");
                   *f2=99; }
               }//fin turno negro 
    }// condicion 8

    else
    {
      printf("Movimiento invalido, fuera de rango permitido\n");
      *f2=99;
    }// Error

}//Fin caballo


void torre( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
  int tr = 0;
  if(turno == 0)
  {
    if (check(*f2,*c2,tab) == 0 && tab[*f2][*c2]!= '.')
    {
      printf("Movimiento invalido no puede comer una propia ficha\n");
      tr = 99;
      *f2=99;
    } 

  }
  if(turno == 1)
  {
    if (check(*f2,*c2,tab) == 1 && tab[*f2][*c2]!= '.')
    {
      printf("Movimiento invalido no puede comer una propia ficha\n");
      tr = 99;
      *f2=99;
    } 

  }
  if(*f2 ==*f1 && tr == 0)
  {
  
    if(*c1 < *c2)
    {
      for (int i = *c1+1; i<*c2; i++)
      {
        if(tab[*f1][i] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido\n");
          *f2 = 99;
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  
    if(*c1 > *c2)
    {
      int g;
      for (int i = *c1-1; i>*c2; i--)
      {
        if(tab[*f1][i] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido\n");
          *f2 = 99; 
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  

  }

  else if (*c2 ==*c1 && tr == 0)
  {
    if(*f1 < *f2)
    {

      for (int i = *f1+1; i<*f2; i++)
      {
        if(tab[i][*c1] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido\n");
          *f2=99; 
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  
    else if(*f1 > *f2)
    {

      for (int i = *f1-1; i>*f2; i--)
      {
        if(tab[i][*c1] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido\n");
           *f2 = 99;
          break; 
          
        }
      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  

  }
  else
  {
    printf("Movimiento invalido, fuera de rango permitido\n");
    *f2=99; 
  } 

}


void alfil( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
  

  if(turno == 0 && check2(*f2,*c2,tab) == 1)
  {
      printf("Movimiento invalido no puede comer una propia ficha\n");
      *f2=99;
  }
  
  else if(turno == 1 && check(*f2,*c2,tab) == 1 )
  {
      printf("Movimiento invalido no puede comer una propia ficha\n");
      *f2=99;
    
  }


  else if(*f1<*f2 &&*c1 < *c2)
  { int k=1;
    while (tab[*f1+k][*c1+k] == '.' && *f1+k <*f2 &&*c1+k < *c2 )
    {
      k++;
    }

    if( (*f1+k) == *f2 && (*c1+k) == *c2) 
      {printf("ok");}
      
    else{
        printf("Movimiento 1 invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1<*f2 &&*c1 > *c2)
  { int k=1;
    while (tab[*f1+k][*c1-k]=='.' && *f1+k <*f2 &&*c1 -k > *c2)
    {
      k++;
    }
      if( (*f1+k) == *f2 && (*c1-k) == *c2) 
       {printf("ok");}
      
      else{
        printf("Movimiento 2 invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1>*f2 &&*c1 > *c2)
  { int k=1;
    while (tab[*f1-k][*c1-k]=='.' && *f1-k>*f2 &&*c1-k > *c2)
    {
      k++;
    }
      if( (*f1-k) == *f2 && (*c1-k) == *c2) 
      {printf("ok");}
      
      else{
        printf("Movimiento 3 invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1>*f2 &&*c1 < *c2)
  { int k=1;
  
    while (tab[*f1-k][*c1+k]=='.' && *f1-k>*f2 &&*c1+k < *c2)
    {
      k++;
    }
        if( (*f1-k) == *f2 && (*c1+k) == *c2) 
            {printf("ok");}

        else{
                 printf("Movimiento 4 invalido, fuera de rango permitido\n");
                 *f2 = 99;
            }
  }

else{
       printf("Movimiento invalido, fuera de rango permitido\n");
       *f2 = 99;
    }

}//Fin alfil


void reina( int *f1 , int *c1, int *f2, int *c2, char tab[8][8], int turno )
{
    int tr = 0;
  if(turno == 0)
  {
    if (check2(*f2,*c2,tab) == 1)
    {
      printf("Movimiento invalido no puede comer propia ficha \n");
      tr = 99;
      *f2=99;
    } 

  }
  if(turno == 1)
  {
    if (check(*f2,*c2,tab) == 1)
    {
      printf("Movimiento invalido no puede comer propia ficha\n");
      tr = 99;
      *f2=99;
    } 
  }

  if(*f2 ==*f1 && tr == 0)
  {
  
    if(*c1 < *c2)
    {
      for (int i = *c1+1; i<*c2; i++)
      {
        if(tab[*f1][i] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido\n");
          *f2 = 99;
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  
    if(*c1 > *c2)
    {
      int g;
      for (int i = *c1-1; i>*c2; i--)
      {
        if(tab[*f1][i] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido2\n");
          *f2 = 99; 
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  

  }

  else if (*c2 ==*c1 && tr == 0)
  {
    if(*f1 < *f2)
    {

      for (int i = *f1+1; i<*f2; i++)
      {
        if(tab[i][*c1] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido3\n");
          *f2=99; 
          break;
        }

      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  
    else if(*f1 > *f2)
    {

      for (int i = *f1-1; i>*f2; i--)
      {
        if(tab[i][*c1] != '.') 
        {
          printf("Movimiento invalido, fuera de rango permitido4\n");
           *f2 = 99;
          break; 
          
        }
      }
      if (*f2 != 99)
      {
        printf("okay\n");
      }
    }  

  }

    else if(*f1<*f2 &&*c1 < *c2)
  { int k=1;
    while (tab[*f1+k][*c1+k] == '.' && *f1+k <*f2 &&*c1+k < *c2 )
    {
      k++;
    }

    if( (*f1+k) == *f2 && (*c1+k) == *c2) 
      {printf("ok");}
      
    else{
        printf("Movimiento invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1<*f2 &&*c1 > *c2)
  { int k=1;
    while (tab[*f1+k][*c1-k]=='.' && *f1+k <*f2 &&*c1 -k > *c2)
    {
      k++;
    }
      if( (*f1+k) == *f2 && (*c1-k) == *c2) 
       {printf("ok");}
      
      else{
        printf("Movimiento invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1>*f2 &&*c1 > *c2)
  { int k=1;
    while (tab[*f1-k][*c1-k]=='.' && *f1-k>*f2 &&*c1-k > *c2)
    {
      k++;
    }
      if( (*f1-k) == *f2 && (*c1-k) == *c2) 
      {printf("ok");}
      
      else{
        printf("Movimiento invalido, fuera de rango permitido\n");
        *f2 = 99;
      }
  }

  else if(*f1>*f2 &&*c1 < *c2)
  { int k=1;
  
    while (tab[*f1-k][*c1+k]=='.' && *f1-k>*f2 &&*c1+k < *c2)
    {
      k++;
    }
        if( (*f1-k) == *f2 && (*c1+k) == *c2) 
            {printf("ok");}

        else{
                 printf("Movimiento invalido, fuera de rango permitido\n");
                 *f2 = 99;
            }
  }

else{
       printf("Movimiento invalido, fuera de rango permitido\n");
       *f2 = 99;
    }

  
}//fin reina


int check(int x , int y, char tab[8][8] )
{/*
Devolvemos un 1 si la posición del tab corresponde a una ficha negra
caso contrario devolvemos un 0
*/
    switch( tab[x][y] )
    {
    case 'p':
    case 'r':
    case 'a':
    case 'c':
    case 'd':
    case 't': return 1 ; break ;
    default: return 0 ;
    }
}//Fin check

int check2(int x , int y, char tab[8][8] )
{/*
Devolvemos un 1 si la posición del tab corresponde a una ficha blanca
caso contrario devolvemos un 0
*/
    switch( tab[x][y] )
    {
    case 'P':
    case 'R':
    case 'A':
    case 'C':
    case 'D':
    case 'T': return 1 ; break ;
    default: return 0 ;
    }
}//Fin check2
