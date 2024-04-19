#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float gasolina_premium;
    float gasolina_regular;
    float gasoil_regular;
    float gasoil_optimo;
    float avtur;
    float kerosene;
    float fuel_oil_6;
    float fuel_oil_1S;
    float glp;
    float gas_natural;
} gasolina;

typedef struct
{
    float kilometros;
} datos;

void todo(FILE *);

int main()
{
    FILE *costo;
    int res;
    printf("\nHola!");
    printf("\n\nPara utlizar los datos existente presione 0 o 1 para actualizarlos \n", res);
    scanf("%d", &res);
    if (res == 1)
    {
        costo = fopen("Costos de viaje.txt", "w+");
        if(costo != NULL)
        {
            todo(costo);
            fclose(costo);
        }
        else
            printf("\nNo se pudo realizar la operacion");
    }
    return 0;
}

void todo(FILE *cul)
{
    gasolina as;
    datos bu;
    int gas;
    char tipo[20];
    float cam;

    as.gasolina_premium = 290.1;
    as.gasolina_regular = 272.5;
    as.gasoil_regular = 221.6;
    as.gasoil_optimo = 239.10;
    as.avtur = 194.89;
    as.kerosene = 225.40;
    as.fuel_oil_6 = 159.87;
    as.fuel_oil_1S = 173.72;
    as.glp = 132.60;
    as.gas_natural = 43.97;


    printf("\n\nCuantos kilometros recorridos quieres calcular? ");
    scanf("%f", &bu.kilometros);
    printf("\nQue tipo de gasolina usaste para ese viaje...? ");
    printf("\n1. Gasolina Premium \n2. Gasolina Regular \n3. Gasoil Regular \
           \n4. Gasoil Optimo \n5. Avtur \n6.Kerosene \n7. Fuel Oil #6\n8. Fuel Oil 1S \
           \n9. Gas Licuado de petroleo (GLP) \n10. Gas Natural");
    printf("\nIngrese el numero: ");
    scanf("%d", &gas);



    switch (gas)
    {
    case 1 :
        strcpy(tipo, "Gasolina Premium");
        cam = as.gasolina_premium;
        break;
    case 2 :
        strcpy(tipo, "Gasolina Regular");
        cam = as.gasolina_regular;
        break;
    case 3 :
        strcpy(tipo, "Gasoil Regular");
        cam = as.gasoil_regular;
        break;
    case 4 :
        strcpy(tipo, "Gasoil Optimo");
        cam = as.gasoil_optimo;
        break;
    case 5 :
        strcpy(tipo, "Avtur");
        cam = as.avtur;
        break;
    case 6 :
        strcpy(tipo, "Kerosene");
        cam = as.kerosene;
        break;
    case 7 :
        strcpy(tipo, "Fuel Oil #6");
        cam = as.fuel_oil_6;
        break;
    case 8 :
        strcpy(tipo, "Fuel Oil 1S");
        cam = as.fuel_oil_1S;
        break;
    case 9 :
        strcpy(tipo, "Gasolina Licuada de petroleo(GLP)");
        cam = as.glp;
        break;
    case 10 :
        strcpy(tipo, "Gas Natural");
        cam = as.gas_natural;
        break;
    default:
        printf("\nEse valor no es admitido");
        break;
    }
    fprintf(cul, "|---------------------------------------------------------------------------|\n");
    fprintf(cul, "| Kilometros recorridos: %f |\tTipo de gasolina: %s|\n", bu.kilometros, tipo);
    fprintf(cul, "|---------------------------------------------------------------------------|\n");

    int likm;
    float gal = 0.264172;

    fprintf(cul, "\n|---------------------------------------------------------------------------|\n");
    fprintf(cul, "|\t        Km por galon \tCosto por km \tTotal del viaje           |");

    for(likm = 8; likm <= 16; likm++)
    {
        float gal2 = likm * gal;
        float r = 100 / gal2;
        float kmga = bu.kilometros / r;

        float ami = kmga / bu.kilometros;
        float cokm = ami * cam;

        float total_viaje = cokm * bu.kilometros;

        fprintf(cul, "|---------------------------------------------------------------------------|\n");
        fprintf(cul, "| %dl / 100 km  \t%.3f gal \tRD$%.3f  \tRD$%.3f                ", likm, kmga, cokm, total_viaje);
        fprintf(cul, "\n|---------------------------------------------------------------------------|\n");

    }
}

