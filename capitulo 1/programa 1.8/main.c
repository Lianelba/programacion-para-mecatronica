#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    float RAD, ALT, VOL, ARE;
    int M_PI = 3.14159265359;
    printf("Ingrese el radio y la altura del cilindro: ");
    scanf("%f %f", &RAD, &ALT);
    VOL = M_PI* pow (RAD, 2)* ALT;
    ARE = (2 * M_PI * RAD * ALT);
    printf("\nEl volumen es: %6.2f \t El area es : %6.2f", VOL, ARE);
}
