#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    eMovie *Peliculas=NULL;
    char seguir='s';
    char archi[]= {"CineVAM"};
    int opcion=0;
    int contpelis=0;
    int nro,auxint;
    int flag=0;

    auxint=TomarPeliArchivada(&Peliculas, &contpelis);
    if(auxint==-1)
    {
        exit(0);
    }

    while(seguir=='s')
    {

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
                contpelis=AltaPeli(Peliculas, contpelis);
                break;
            case 2:
                system("cls");
                if((PermitirOpciones(Peliculas, contpelis))>0)
                {
                    contpelis=BorrarPeli(Peliculas, contpelis);
                }
                else
                {
                    printf("\nNo se puede ingresar esta opcion.\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if((PermitirOpciones(Peliculas, contpelis))>0)
                {
                    ModificarPeli(Peliculas, contpelis);
                }
                else
                {
                    printf("\nNo se puede ingresar esta opcion.\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                if((PermitirOpciones(Peliculas, contpelis))>0)
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
