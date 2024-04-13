#include <stdio.h>
#include <stdlib.h>

void sumypro(FILE *);

void main(void)
{
    FILE *ap;
    if((ap = fopen("arc4.txt", "r")) != NULL)
    {
        sumypro(ap);
    }
    fclose(ap);
    else
        printf("\nNo se puede abrir el archivo");
}

void sumypro(FILE *ap1)
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;
    while(!feof(ap1))
    {
        fgets(cad, 30, ap1);
        r = atof(cad);
        if(r)
        {
            i++;
            sum += r;
        }
    }
    printf("\nSuma: %.2f", sum);
    if (i)
        printf("\nPromedio: %.2f", sum/i);
}
