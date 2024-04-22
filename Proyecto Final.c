#include <stdio.h>
#include <math.h>
#include <string.h>

/******************************************************/
/** Nombre: Lianelba Ovalle Gil                      **/
/** Matrícula: 2023-1758                             **/
/** Descripcion del programa: Este programa consigue **/
/** datos sobre un carro, los guarda en un archivo   **/
/** y hace unos calculos con ellos.                  **/
/******************************************************/


struct precio              //En este struct tengo guardados los datos que el programa va a pedir sobre el carro
{
    int mantenimiento;
    int seguro;
    int gomas;
    float gomakm;
    int carro;
    char nombrecar[50];
    int timmant;
    int timcar;
};

struct gasolina     // Este es para los tipos de gasolina. No era necesario, pero me pareció interesante agregarlo
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
};

float klm;      //Este float es para la cantidad de km que recorrio el carro para hacer los calculos

void grabapara(FILE *);     //Como indica el nombre, esta es una funcion encargada de grabar los datos en un archivo
void todo_lo_demas(FILE *, FILE *, FILE *);     //Y como se puede da cuenta, esta funcion hace todo lo demas

int main()
{
    FILE *archivo;
    FILE *cos;
    FILE *par;
    char nom[50] = "";
    char l;
    int res;
    do
    {
        printf("\n\nHola!");
        printf("\n\nQue quieres hacer?\n1. Calcular el costo de viaje \n2. Introducir datos sobre tu vehiculo\n3. Salir\
               \n\nIntroduce el numero corresponiente: "); // mi menu
        scanf("%d", &res);
        switch (res)
        {
        case 2:
            archivo = fopen("Datos sobre el vehiculo.txt", "w");        //En este switch se graban los datos, solo de ser pedido
            if (archivo != NULL)
            {
                grabapara(archivo);
                fclose(archivo);
            }
            else
            {
                printf("Error al abrir el archivo");
                return 0;
            }
            break;

        case 1:
            printf("\nQue nombre le quieres poner al archivo(No puedes usar espacios): ");           //Aqui abri tres archivos, cos para tener un archivo con la tabla de calculos,
            scanf("%s", &nom);                                           //par es para guardar los parametros y archivo es el archivo que se va a leer en la funcion mas adelante
            cos = fopen(nom, "w");
            par = fopen("Detalles sobre el vehiculo.txt", "w+");
            archivo = fopen("Datos sobre el vehiculo.txt", "r");
            if ((archivo != NULL) && (cos != NULL) && (par != NULL))
            {
                todo_lo_demas(cos, archivo, par);
                fclose(archivo);
                fclose(cos);
                fclose(par);
            }
            else
            {
                printf("Error al abrir el archivo");
                return 1;
            }


            break;

        case 3:
            res = 0;
            break;

        default:
            printf("\nEse valor no esta permitido");
            break;
        }
    }
    while (res < 3 && res >= 1); //Mientras la respuesta sea 1 o dos, el do-while va a continuar

    return 0;
}

void grabapara(FILE *archivo)
{
    struct precio pr;       //Lo que hice aquí basicamente fue declarar a la struct dentro de la función
    printf("Cuanto pagas de..?");
    printf("\n\t\tMantenimiento: ");
    scanf("%d", &pr.mantenimiento);
    printf("\n\t\tCuantas veces al ano llevas el vehiculo a mantenimiento: ");
    scanf("%d", &pr.timmant);
    printf("\n\tSeguro: ");
    scanf("%d", &pr.seguro);
    printf("\n\t\tPrecio de las gomas: ");
    scanf("%d", &pr.gomas);
    printf("\n\t\tCada cuantos kilometros tienes que cambiar las gomas: ");
    scanf("%f", &pr.gomakm);
    printf("\n\t\tVehiculo: ");
    scanf("%d", &pr.carro);
    printf("\n\t\tCual es el modelo de tu vehiculo: ");
    scanf("%s", pr.nombrecar);
    printf("\n\t\tEn cuantos anos terminas de pagar el vehiculo: ");
    scanf("%d", &pr.timcar);

    fwrite(&pr, sizeof(struct precio), 1, archivo);
    /*fwrite toma todos los datos que pide y los guarda en un archivo txt codificado.
    Lo usé porque así puedo pasar los datos de esta función a la otra.*/
}

void todo_lo_demas(FILE *im, FILE *lee, FILE *para)
{
    struct precio pr;
    int likm;
    float gal = 0.264172;
    float depreciacion = 700000;
    float kman = 20000;         //estos son los km al año por promedio
    fread(&pr, sizeof(struct precio), 1, lee);
    /*fread lee el archivo codificado de fwrite, por eso en el main, ambos archivos se llaman iguales
    y uno tiene la opcion de escribir, mientras que el otro lee y trae los datos a esta funcion*/

    printf("\n\n\tUsted paga %d de mantenimiento %d veces al ano", pr.mantenimiento, pr.timmant);
    printf("\n\n\tUsted paga %d de seguro", pr.seguro);
    printf("\n\n\tUsted paga %d en sus gomas cada %.1f kilometros", pr.gomas, pr.gomakm);
    printf("\n\n\tSu %s cuesta %d", pr.nombrecar, pr.carro);
    printf("\n\n\tUsted termina de pagar su vehiculo en %d anos", pr.timcar);

    fprintf(para, "\n\n\tUsted paga %d de mantenimiento %d veces al ano", pr.mantenimiento, pr.timmant);
    fprintf(para, "\n\n\tUsted paga %d de seguro", pr.seguro);
    fprintf(para, "\n\n\tUsted paga %d en sus gomas cada %.1f kilometros", pr.gomas, pr.gomakm);
    fprintf(para, "\n\n\tSu %s cuesta %d", pr.nombrecar, pr.carro);
    fprintf(para, "\n\n\tUsted termina de pagar su vehiculo en %d anos", pr.timcar);

    //Mientras que un printf pone los datos en pantalla, el otro los pone en un archivo.txt llamado Detalles
    //sobre el vehiculo.

    struct gasolina as;

    int gas;
    char tipo[50];
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
    as.gas_natural = 43.97; // estos son los precios de las gasolinas, pero para mis calculos, usé la Premium

    printf("\n\nCuantos kilometros recorridos quieres calcular? ");
    scanf("%f", &klm);
    printf("\nQue tipo de gasolina usaste para ese viaje...? ");
    printf("\n1. Gasolina Premium \n2. Gasolina Regular \n3. Gasoil Regular \
           \n4. Gasoil Optimo \n5. Avtur \n6.Kerosene \n7. Fuel Oil #6\n8. Fuel Oil 1S \
           \n9. Gas Licuado de petroleo (GLP) \n10. Gas Natural");
    printf("\nIngrese el numero: ");
    scanf("%d", &gas);

    switch (gas)        //Este switch lo que hace es cambiar el valor de gas y lo convierte en un tipo de gasolina
        //dependiendo de su valor y lo selecciona como la opcion a usar mas adelante
    {
    case 1:
        strcpy(tipo, "Gasolina Premium");
        cam = as.gasolina_premium;
        break;
    case 2:
        strcpy(tipo, "Gasolina Regular");
        cam = as.gasolina_regular;
        break;
    case 3:
        strcpy(tipo, "Gasoil Regular");
        cam = as.gasoil_regular;
        break;
    case 4:
        strcpy(tipo, "Gasoil Optimo");
        cam = as.gasoil_optimo;
        break;
    case 5:
        strcpy(tipo, "Avtur");
        cam = as.avtur;
        break;
    case 6:
        strcpy(tipo, "Kerosene");
        cam = as.kerosene;
        break;
    case 7:
        strcpy(tipo, "Fuel Oil #6");
        cam = as.fuel_oil_6;
        break;
    case 8:
        strcpy(tipo, "Fuel Oil 1S");
        cam = as.fuel_oil_1S;
        break;
    case 9:
        strcpy(tipo, "Gasolina Licuada de petroleo(GLP)");
        cam = as.glp;
        break;
    case 10:
        strcpy(tipo, "Gas Natural");
        cam = as.gas_natural;
        break;
    default:
        printf("\nEse valor no es admitido");
        return;
    }


    fprintf(im, "|---------------------------------------------------------------------------|\n");
    fprintf(im, "| Kilometros recorridos: %.2f    |\tTipo de gasolina: %s\n", klm, tipo);
    fprintf(im, "|---------------------------------------------------------------------------|\n");

    //Aquí se impremen los kilometros y tipo de gasolina que pidió el programa

    fprintf(im, "\n|---------------------------------------------------------------------------|\n");
    fprintf(im, "|Consumo         Costo por km \t km por galon  \tTotal del viaje           |\n");


    printf("\n|---------------------------------------------------------------------------|\n");
    printf("\n|Consumo     Costo por km  \tkm por galon \tTotal del viaje           |\n");

    for (likm = 8; likm <= 16; likm++)          //likm empiza el 8 y llega a 16, en cada vuelta, likm sube uno
    {
        float gal2 = likm * gal;                //Aquí estoy pasando de litros/100 km a galones/100km
        float r = gal2 / 100;
        float kmga = cam * r;                   //multiplicamos el resultado de gal/100 por el precio de la gasolina que se selecionó anteriormente

        float carto = pr.carro - depreciacion;      //Este es el precio final del carro
        carto = carto / pr.timcar;                  //Y lo dividimos entre la cantidad de años en que se paga el carro, para saber cuanto es en un año
        float manto = pr.mantenimiento * pr.timmant;  //Multiplicamos el costo del mantenimineto por la cantidad de veces que lo llevamos al año

        float len = kman / pr.gomakm;          //Para saber cuantas veces tenemos que cambiar las gomas al año, usamos el promedio de km entre la cantidad de km que duran las gomas
        float goma = ceil(len);                 //ceil(len) es unan función para redondear el numero obtenido hacia arriba
        float gomas = pr.gomas * goma;             //multiplico la cantidad de gomas que voy a usar por el precio de un set

        float tot = (carto + manto + pr.seguro + gomas);   //esto es por el costo por kilometro, en el programa se ve igual en todas las lineas, eso es
        float tot2 = tot / kman;                                 //porque esto bien se puede hacer fuera for, pero está qui adentro porque me gusta como se ve
        float cokm = tot2 + kmga;                                 //sumamos el costo por la cantidad de dinero que gastamos en kilometro

        float total_viaje = cokm * klm;                     //Para calcular el total, multiplicamos el costo por km por la cantidad de kilomentros

        printf("|---------------------------------------------------------------------------|\n");
        printf("  %dL / 100 km    \tRD$%.3f  \t%.3f  \tRD$%.3f                \n", likm, cokm, kmga, total_viaje);
        printf("|---------------------------------------------------------------------------|\n");

        fprintf(im, "|---------------------------------------------------------------------------|\n");
        fprintf(im, "  %dL / 100 km     \t%.3f    \t%.3f  \tRD$%.3f                \n", likm, cokm, kmga, total_viaje);
        fprintf(im, "|---------------------------------------------------------------------------|\n");
    }
}
