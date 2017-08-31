#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

float pedirNUM()
{
    float num;

    printf("Ingrese un numero: \n");
    scanf("%f",&num);

    return num;
}
float SUMA(float num1,float num2)
{
    float num;
    num=num1+num2;
    return num;
}
float RESTA(float num1,float num2)
{
    float num;
    num=num1-num2;
    return num;
}
float MULTIPLICACION(float num1,float num2)
{
    int num;
    num=num1*num2;
    return num;
}
float DIVISION(float num1,float num2)
{
    float num;
    while(num2==0)
    {
        printf("ERROR!!!Si el segundo operador es cero no realizara la division\n");
        printf("Reingrese el segundo operador: \n");
        scanf("%f",&num2);
    }
    num=num1/num2;
    return num;
}
long long int FACTORIAL(float num1)
{
    long long int fac;
    if(num1==0)
    {
        return 1;
    }
    else
    {
        fac=num1*FACTORIAL(num1-1);
    }
    return fac;
}
int VALFACT(float num1)
{
    int ent=(int) num1;
    float probar;

    probar=num1-ent;

    if(probar==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

