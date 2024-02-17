/*
   BubbleSort C
*/
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10

int i;
int change;
int n;
int a[ARRAY_SIZE];
int buf;
time_t seed;

int main(int argc, char* argv[])
{
    seed = 0;
    srand(time(&seed));
    n = sizeof(a) / sizeof(*a);
    for (i = 0; i <= n-1; i++)
    {
        a[i] = rand() % 1000;
    }

    for (i = 0; i <= n-1; i++)
    {
        printf("Element a[%d]: %d\n", i, a[i]);
    }
    change = 1;
    while (change == 1)/* Este while tiene un change == 1, que es una manera de verificar la variable change es
        verdadera. Mientras sea verdadera, este while va a ejecutarse.*/
    {
        change = 0;/*Aqui le estamos dando a change el valor de 0*/
        for (i = 0; i <= n-2; i++)/*Este for sirve para organizar los valores del array, de menor a mayor.*/
        {
            if (a[i] > a[i+1])/*Si el valor dentro de a[i] es mayor que el valor que le sigue, se ejecuta lo de abajo*/
            {
                buf = a[i];
                a[i] = a[i+1];
                a[i+1] = buf;
                change = 1;/* Lo que esta pasando en las lineas 39-42 es lo siguiente: el valor de a[i] se pone en una
    casilla aparte, llamada buf. El valor de la casilla que le sigue(a[i+1]) ocupa su lugar y el valor que hemos puesto en buf
    pasa a la casilla de a[i+1]*/
            }
        }
    }
    printf("\n----------------\n");
    for (i = 0; i <= n-1; i++)
    {
        printf("Element a[%d]: %d\n", i, a[i]);
    }
    return 0;
}
