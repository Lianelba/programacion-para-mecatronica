#include <stdio.h>
#include <math.h>

void main(void)
{
    int I = 1, B = 0, C = 1;
    double RES;
    RES = 4.0 / I;
    printf("\nNumero de terminos: %d", C);
    while ((fabs(3.1415 - RES)) > 0.0005)
    {
        I+= 2;
        if(B = 1)
        {
            RES +=(double) (4.0 / I);
            B = 0;
        }
        else
        {
            RES += (double) (4.0 / I);
            B = 0;
        }
        C++;
    }

}
