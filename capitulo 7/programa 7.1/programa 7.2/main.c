#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char p1;
    printf("\ningrese un caracter para analizar si este es un numero: ");
    p1 = getchar();
    if(isdigit(p1))
        printf("%c es un numero \n", p1);
    else
        printf("%c no es un numero \n", p1);

    fflush(stdin);
    printf("\nIngrese un caracter para examinar si este es una letra: ");
    p1 = getchar();
    if (isalpha(p1))
        printf("\n%c es una letra \n", p1);
    else
        printf("%c no es una letra \n");

    fflush(stdin);
    printf("\nIngrese un caracter para verificar si esta letra es minuscula: ");
    p1 = getchar();
    if(isalpha(p1))
        if(islower(p1))
            printf("\nc% es una letra minuscula");
        else
            printf("\n%c no es una letra minuscula", p1);
    else
        printf("\n%c no es una letra", p1);

    fflush(stdin);
    printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
    p1 = getchar();
    if(isalpha(p1))
        if(isupper(p1))
            printf("\n%c fue convertida de mayuscula a minuscula", tolower(p1));
        else
            printf("\n%c es una letra minuscula", p1);
    else
        printf("\n%c no es una letra", p1);
}
