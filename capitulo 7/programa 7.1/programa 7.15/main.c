#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void interpretar(char *);

void main (void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    interpretar(cad);
}

void interpretar(char *cad)
{
    int i = 0, j, k;
    while(cad[i] != '\0')
    {
        if (isalpha (cad[i]))
        {
            k = cad[i - 1] - 48;
            for (j = 0; j < k; j++)
                putchar(cad[i]);
        }
        i++;
    }
}
