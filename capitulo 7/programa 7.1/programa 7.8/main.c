#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void minymay(char cadena[]);

void main(void)
{
    int i, n;
    char FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nIngrese la linea %d de texto: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);
    }

    printf("\n\n");

    for (i = 0; i < n; i++)
        minymay(FRA[i]);
}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;
    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }
    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayuscula: %d", ma);
}