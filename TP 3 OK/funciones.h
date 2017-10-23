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

/** \brief Crea un puntero a estructura.
 *
 * \return Puntero a eMovie.
 *
 */
eMovie* CreaStruct();

/** \brief Inicializa los estados de las estructuras a 0.
 *
 * \param *Peliculas es el puntero a la estructura
 * \param tam es la cantidad de estructuras a inicializar.
 *
 *
 */
void InicializarEstructura(eMovie* Peliculas, int tam);

/** \brief Modifica el tamaño de la estructura.
 *
 * \param **fron es el puntero a la estructutura.
 * \param tam tamaño del puntero modificado.
 * \return retorna 0 si se modifico o -1 si no se modifico.
 *
 */
int ModificoStruct(eMovie** fron, int tam);

/** \brief Pide y guarda los datos para la pelicula.
 *
 * \param *Peliculas puntero a la estructura.
 * \param tam cantidad de peliculas ingresadas.
 * \return La cantidad de peliculas ingresadas.
 *
 */
int AltaPeli(eMovie* Peliculas, int tam);

/** \brief Borra los datos de la pelicula en la memoria
 *
 * \param *Peliculas puntero a la estructura.
 * \param tam cantidad de peliculas ingresadas.
 *
 *
 */
int BorrarPeli(eMovie* Peliculas, int tam);

/** \brief Modifica los datos de la pelicula en la memoria.
 *
 * \param *Peliculas puntero a la estructura.
 * \param tam cantidad de peliculas ingresadas.
 * \return la cantidad de peliculas-1.
 *
 */
void ModificarPeli(eMovie *Peliculas, int tam);

/** \brief Valida si puede ingrersar a opciones especificas.
 *
 * \param *Peliculas puntero a la estructura.
 * \param tam cantidad de peliculas ingresadas.
 * \return un numero>0 si hay peliculas o 0 si no hay peliculas ingresadas.
 *
 */
int PermitirOpciones(eMovie *Peliculas, int tam);

/** \brief Tonma la informacion sobre peliculas del archivo.dat.
 *
 * \param **Pelis puntero donde se guarda la informacion de peliculas.
 * \param *cantPelis puntero donde se guarda la cantidad de peliculas.
 * \return 0 si se tomaron las peliculas o -1 si no se tomaron.
 *
 */
int TomarPeliArchivada(eMovie** Pelis, int* cantPelis);

/** \brief Agrega una pelicula al archivo binario
 *
 * \param *Peliculas la estructura que se agrega al archivo.
 * \param tam tamaño del puntero.
 * \return 1 si se agrego la pelicula o 0 si no.
 *
 */
int AgregoPeli(eMovie* Peliculas, int tam);

/** \brief Genera un archivo .html a partir de la informacion de peliculas.
 *
 * \param *Peliculas contiene la informacion de las peliculas.
 * \param name es el nombre que se le pondra al archivo html.
 * \param tam es la cantidad de peliculas ingresadas.
 *
 */
void GenerarWeb(eMovie *Peliculas,char name[], int tam);

