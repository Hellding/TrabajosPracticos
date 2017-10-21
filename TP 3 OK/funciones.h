#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char linkImagen[500];
    int estado;
} eMovie;

void AltaPeli(eMovie *Peliculas, int tam);
void BorrarPeli(eMovie *Peliculas, int tam);
void ModificarPeli(eMovie *Peliculas, int tam);
int PermitirOpciones(eMovie *Peliculas, int tam);
void GenerarWeb(eMovie *Peliculas,char name[], int tam);

