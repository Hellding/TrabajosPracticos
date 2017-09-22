#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 20

int main()
{
    ePersona people[TAM];
    char seguir='s';
    int opcion=0;

    InicializarEstructura(people,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("Ingrese su Opcion:\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                AltaPeople(people,TAM);
                break;
            case 2:
                system("cls");
                BajaProgramador(people,TAM);
                break;
            case 3:
                system("cls");
                MostrarOrden(people,TAM);
                break;
            case 4:
                system("cls");
                GraficoEDAD(people,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
