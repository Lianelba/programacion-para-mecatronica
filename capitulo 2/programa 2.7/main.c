#include <stdio.h>
#include <stdlib.h>

void main (void)
{
    float P, S, R;
    printf("Ingrese los tres salarios: ");
    scanf("%f %f %f", &P, &S, &R);
    if (P>S)
        if (P>R)
            if (S>R)
                printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", P, S, R);
            else
                printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", P, R, S);
        else
            printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", R, P, S);
    else if (S>R)
        if (P>R)
            printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", S, P, R);
        else
            printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", S, R, P);
    else
        printf("\nEl orden de los valores es: %8.2f %8.2f %8.2f", R, S, P);

}
