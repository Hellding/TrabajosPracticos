#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void InicializarEstructura(ePersona usuario[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        usuario[i].estado=0;
    }
}

int ObtenerEspacioLibre(ePersona usuario[],int tam)
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(usuario[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int BuscarPorDni(ePersona usuario[], int auxDNI, int tam)
{
    int i;
    int indice=-1;

    for(i=0; i<tam; i++)
    {
        if(usuario[i].dni==auxDNI&&usuario[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void AltaPeople(ePersona usuario[],int tam)
{
    ePersona newusuario;

    int i;
    int ind;
    int auxDNI;
    int auxEDAD;
    int contEdad[3]= {0,0,0};
    int largob;
    char buffer[100];

    for(i=0; i<tam; i++)
    {
        ind=ObtenerEspacioLibre(usuario,tam);

        if(ind<tam)
        {
            system("cls");
            printf("Ingrese su DNI: ");
            scanf("%d",&auxDNI);
            if(BuscarPorDni(usuario,auxDNI,tam)!=-1)
            {
                printf("El ID ya fue ingresado");
            }
            else
            {
                newusuario.dni=auxDNI;
                printf("\nIngrse su Nombre:");
                fflush(stdin);
                gets(buffer);
                largob=strlen(buffer);
                if(largob>20&&largob<2)
                {
                    printf("\nERROR!!!Lo que escribio es mayor a la cantidad disponible de espacio para guardar.");
                    printf("\nReingrese su nombre: ");
                    fflush(stdin);
                    gets(buffer);
                }
                else
                {
                    strcpy(newusuario.nombre,buffer);
                    printf("\nIngrese su edad:");
                    scanf("%d",&auxEDAD);
                    if(auxEDAD<1&&auxEDAD>100)
                    {
                        printf("\nERROR!!!Reingrese su edad:");
                        scanf("%d",&auxEDAD);
                    }
                    else
                    {
                        newusuario.edad=auxEDAD;
                        newusuario.estado=1;
                        usuario[ind]=newusuario;
                    }

                }
            }
        }
        else
        {
            printf("\nNo hay espacio libre para agregar informacion");
            break;
        }
    }
}

void BajaProgramador(ePersona usuario[],int tam)
{
    int i;
    int auxDNI;
    char resp;

    printf("\nIngrese el DNI:");
    scanf("%d",&auxDNI);
    for(i=0; i<tam; i++)
    {

        if(BuscarPorDni(usuario,auxDNI,tam)<0)
        {
            printf("El DNI no se encuentra");
            break;
        }
        else
        {
            MostrarDNI(usuario,auxDNI,tam);
            printf("\nDesea eliminar los datos de esta persona?");
            printf("\n  s-SI    n-NO\n");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp=='s'||resp=='n')
            {
                if(resp=='s')
                {
                    usuario[i].estado=0;
                    printf("\nLa persona se elimino satisfactoriamente");
                    break;
                }
                else
                {
                    printf("\nNo se elimino los datos de la persona");
                    break;
                }

            }
            else
            {
                printf("\nERROR!!!Reingrese su respuesta:");
                printf("\n  s-SI    n-NO");
                fflush(stdin);
                scanf("%c",&resp);
            }

        }
    }
}

void MostrarDNI(ePersona usuario[],int auxDNI,int tam)
{
    int pos;

    pos=BuscarPorDni(usuario,auxDNI,tam);

    printf("    %d | %s | %d\n",usuario[pos].dni,usuario[pos].nombre,usuario[pos].edad);

}

void MostrarOrden(ePersona usuario[], int tam)
{
    ePersona auxuser;

    int i,j;

    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if((strcmp(usuario[i].nombre,usuario[j].nombre))>0)
            {
                auxuser=usuario[i];
                usuario[i]=usuario[j];
                usuario[j]=auxuser;
            }
        }
    }
    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado==1)
        {
            printf("    %d | %s | %d\n",usuario[i].dni,usuario[i].nombre,usuario[i].edad);
        }

    }
    system("\npause");
}

void GraficoEDAD(ePersona usuario[],int tam)
{
    int i,j;
    int cont[]={0,0,0};
    int max=0;

    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado==1)
        {
            if(usuario[i].edad<18)
            {
                cont[0]++;
            }
            else if(usuario[i].edad>17&&usuario[i].edad<36)
            {
                cont[1]++;
            }
            else if(usuario[i].edad>35)
            {
                cont[2]++;
            }
        }

    }

    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(usuario[i].estado==1)
            {
                if(cont[i]>max)
                {
                    max=cont[i];
                }
            }

        }

    }

    for(i=max;i>0;i--)
    {
        for(j=0;j<tam;j++)
        {
            if(usuario[i].estado==1)
            {
                if(cont[j]>=i)
                {
                    printf("    *");
                }
                else
                {
                    printf("    ");
                }
            }

        }
        printf("\n");
    }
    printf("\n  <18     18-35   >35\n");
    system("\npause");
}
