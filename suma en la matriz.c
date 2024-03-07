#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int matriz[TAM][TAM]=
{
    {4, 6, 5, 2, 3},
    {5, 1, 9, 8, 5},
    {4, 5, 6, 2, 3},
    {8, 6, 8, 3, 6},
    {9, 3, 4, 1, 7}
};
int dar( int matriz[][TAM], int t)
{
    int i,  f;
    for(i = 0; i < t; i++)
        for(f = 0; f < t; f++)
            if(f == i)
            {
                printf("\nEstas en la fila %d, columna %d, que tiene el valor: %d\t(dp)",i, f, matriz[i][f]);
            }
}

int dar2(int matriz [][TAM], int t)
{
    int i, f;
    for(i = 0; i < t; i++)
        for(f = 0; f < t; f++)
        {
            if(i + f == t - 1)
        {
            printf("\nEstas en la fila %d, columna %d, que tiene el valor: %d\t(ds)",i, f, matriz[i][f]);
        }
        }
}

int suma(int matriz[][TAM], int t)
{
  int i, f;
  int sum = 0;
  for(i = 0; i < t; i++)
  {
        for(f = 0; f < t; f++)
            if(f == i)
        {
            sum = sum + matriz [i][f];

        }
  }
   printf("\nLa suma de la diagonal principal es: %d", sum);
}
int suma2(int matriz[][TAM], int t)
{
    int i, f;
    int sum = 0;
    for(i = 0; i < t; i++)
    {
        for(f = 0; f < t; f++)
        {
            if(i + f == t - 1)
        {
           sum = sum + matriz[i][f];
        }
        }
    }
    printf("\nLa suma de la diagonal secundaria es: %d", sum);
}

int main()
{
    int sumat = 0;
    dar (matriz, TAM);
    printf("\n");
    dar2(matriz, TAM);
    printf("\n");
    suma(matriz, TAM);
    printf("\n");
    suma2(matriz, TAM);
    return 0;
}

