#include <stdio.h>
#include <stdlib.h>

const int F = 8, C = 2, P = 5;

void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);

int main(void)
{
    int UNI[F][C][P];
    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, F, C, P);
}

void Lectura(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J;
    for(K = 0; K < FI; K++)
        for (I = 0; I < CO; I++)
            for (J = 0; J < PR; J++)
            {
                printf("Año: %d\tCarrera: %d\tSemestre: %d ", K+1, I+1, J+1);
                scanf("%d", &A[K][I][J]);
            }
}

void Funcion1(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J, MAY = 0, AO = -1, SUM;
    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (I = 0; I < CO; I++)
            for (J = 0; J < FI; J++)
                SUM += A[J][I][K];
        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso de alumnos: %d Alumnos: %d", AO+1, MAY);
}

void Funcion2(int A[][C][P], int FI, int CO, int PR)
{
    int I, J, MAY = 0, CAR = -1, SUM;
    for (I = 0; I < CO; I++)
    {
        SUM = 0;
        for (J = 0; J < PR; J++)
            SUM += A[FI - 1][I][J];
        if (SUM > MAY)
        {
            MAY = SUM;
            CAR = I;
        }
    }
    printf("\n\nCarrera con mayor numero de alumnos el ultimo año: %d Alumnos: %d", CAR+1, MAY);
}

void Funcion3(int A[][C][P], int FI, int CO, int PR)
{
    int K, J, MAY = 0, AO = -1, SUM;
    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (J = 0; J < CO; J++)
            SUM += A[J][FI - 1][K];
        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso de alumnos para Ingeniería en Computación: %d Alumnos: %d", AO+1, MAY);
}
