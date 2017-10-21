#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 10

int main()
{
    eMovie pelis[TAM], *Peliculas;
    char seguir='s';
    char archi[50];
    int nro;
    int flag=0;
    int opcion=0;
    int contpelis=0;

    Peliculas = pelis;

    while(seguir=='s')
    {
        contpelis=PermitirOpciones(Peliculas, TAM);

        system("cls");
        printf("La cantidad de Peliculas Ingresadas son: %d\n",contpelis);
        printf("1- Agregar Pelicula\n");
        printf("2- Borrar Pelicula\n");
        printf("3- Modificar Pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        if(opcion<1||opcion>5)
        {
            printf("ERROR!!!La opcion ingresada no existe\n");
            system("pause");
        }
        else
        {
            switch(opcion)
            {
            case 1:
                system("cls");
                AltaPeli(Peliculas, TAM);
                break;
            case 2:
                system("cls");
                if((PermitirOpciones(Peliculas, TAM))!=0)
                {
                    BorrarPeli(Peliculas, TAM);
                }
                else
                {
                    printf("\nNo se puede ingresar esta opcion.\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if((PermitirOpciones(Peliculas, TAM))!=0)
                {
                    ModificarPeli(Peliculas, TAM);
                }
                else
                {
                    printf("\nNo se puede ingresar esta opcion.\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                if((PermitirOpciones(Peliculas, TAM))!=0)
                {
                    printf("Ingrese el nombre de archivo a crear,Rango[2-50]:\n");
                    fflush(stdin);
                    gets(archi);
                    nro=strlen(archi);
                    while(flag==0)
                    {
                        if(nro<2||nro>50)
                        {
                            printf("ERROR!!!El nombre ingresado no entra en el rango disponible");
                            printf("Ingrese el nombre de archivo a crear,Rango[2-50]:\n");
                            fflush(stdin);
                            gets(archi);
                            nro=strlen(archi);
                        }
                        else
                        {
                            flag=1;
                            GenerarWeb(Peliculas,archi,contpelis);
                        }
                    }
                }
                else
                {
                    printf("\nNo se puede ingresar esta opcion.\n");
                }
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            }
        }


    }

    return 0;
}
