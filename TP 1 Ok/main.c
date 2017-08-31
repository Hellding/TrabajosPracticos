#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int banda=0,bandb=0;
    float a=0,b=0;
    float suma,resta,multi,divi;
    long int fact;

    while(seguir=='s')
    {
        if(banda==0)
        {
            printf("1-Ingrese el Primer Operador(A=%.0f)\n",a);
        }
        else
        {
            printf("1-Ingrese el Primer Operador(A=%.2f)\n",a);
        }
        if(bandb==0)
        {
            printf("2-Ingrese el Segundo Operador(B=%.0f)\n",b);
        }
        else
        {
            printf("2-Ingrese el Segundo Operador(B=%.2f)\n",b);
        }
        printf("3-Calcular la Suma (A+B)\n");
        printf("4-Calcular la Resta (A-B)\n");
        printf("5-Calcular la Multiplicacion(A*B)\n");
        printf("6-Calcalar la Division(A/B)\n");
        printf("7-Calcular el Factorial(A!)\n");
        printf("8-Calcular todas las operaciones\n");
        printf("9-Salir\n");

        printf("Ingrese su opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://PEDIR1ºNUMERO
        {
            a=pedirNUM();
            banda=1;
            system("cls");
        }
        break;
        case 2://PEDIR2ºNUMERO
        {
            b=pedirNUM();
            bandb=1;
            system("cls");
        }
        break;
        case 3://SUMA
        {
            suma=SUMA(a,b);
            system("cls");
            printf("La suma de A(%.0f) + B(%.0f) es =  a %.2f\n",a,b,suma);
        }
        break;
        case 4://RESTA
        {
            resta=RESTA(a,b);
            system("cls");
            printf("La resta de A(%.0f)- B(%.0f) es =  a %.2f\n",a,b,resta);
        }
        break;
        case 5://MULTIPLICACION
        {
            multi=MULTIPLICACION(a,b);
            system("cls");
            printf("La multiplicacion de A(%.0f) * B(%.0f) es =  a %.2f\n",a,b,multi);
        }
        break;
        case 6://DIVISION
        {
            divi=DIVISION(a,b);
            system("cls");
            printf("La division de A(%.0f) / B(%.0f) es =  a %.2f\n",a,b,divi);
        }
        break;
        case 7://FACTORIZACION
        {
            if(VALFACT(a)==0)
            {
                if(a>0)
                {
                    fact=FACTORIAL(a);
                    system("cls");
                    printf("El Factorial de A(%.0f) es =  a %ld\n",a,fact);
                }
                else
                {
                    printf("ERROR!!!No se puede realizar el Factorial de un numero negativo.\n");
                }

            }
            else
            {
                printf("ERROR!!!No se puede realizar el Factorial de un numero decimal.\n");

            }

        }
        break;
        case 8:
        {
            suma=SUMA(a,b);
            printf("La suma de A(%.0f) + B(%.0f) es =  a %.2f\n",a,b,suma);
            resta=RESTA(a,b);
            printf("La resta de A(%.0f)- B(%.0f) es =  a %.2f\n",a,b,resta);
            multi=MULTIPLICACION(a,b);
            printf("La multiplicacion de A(%.0f) * B(%.0f) es =  a %.2f\n",a,b,multi);
            divi=DIVISION(a,b);
            printf("La division de A(%.0f) / B(%.0f) es =  a %.2f\n",a,b,divi);
            if(VALFACT(a)==0)
            {
                if(a>0)
                {
                    fact=FACTORIAL(a);
                    printf("El Factorial de A(%.0f) es =  a %ld\n",a,fact);
                }
                else
                {
                    printf("ERROR!!!No se puede realizar el Factorial de un numero negativo.\n");
                }

            }
            else
            {
                printf("ERROR!!!No se puede realizar el Factorial de un numero decimal.\n");

            }

        }
        break;
        case 9:
        {
            seguir='n';
            printf("THE END\n");
        }
        break;
        }
    }

    return 0;
}
