#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nombre[50];
    long int edad;
    int estado;
    int dni;
    int contEDAD[3];

}ePersona;

/** \brief Inicializa la estructura para su futuro uso.
 *
 * \param usuario el array se pasa como parametro.
 * \param tam tamaño del array que se pasa como paramaetro.
 * \return
 *
 */
void InicializarEstructura(ePersona usuario[], int tam);

/** \brief Obtiene el primer indice libre del array.
 *
 * \param usuario el array se pasa como parametro.
 * \param tam tamaño del array que se pasa como parmetro.
 * \return el primer indice disponible.
 */
int ObtenerEspacioLibre(ePersona usuario[], int tam);

/** \brief Obtiene el indice que coincide con el dni pasado por parametro.
 *
 * \param usuario el array se pasa como parametro.
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int BuscarPorDni(ePersona usuario[], long int dni, int tam);

/** \brief Pide la informacion de la persona y la guarda en el sistema.
 *
 * \param usuario el array se pasa como parametro.
 * \param tam tamaño del array que se pasa como paramaetro.
 * \return
 *
 */
void AltaPeople(ePersona usuario[], int tam);

/** \brief Da de baja toda la informacion de la persona solicitada por dni.
 *
 * \param usuario el array se pasa como parametro.
 * \param tam tamaño del array que se pasa como paramaetro.
 * \return
 *
 */
void BajaProgramador(ePersona usuario[],int tam);

/** \brief Muestra la informacion de la persona en base a su DNI.
 *
 * \param usuario el array se pasa como parametro.
 * \param auxDNI el dni a buscar por comparacion.
 * \param tam tamaño del array que se pasa como paramaetro.
 * \return
 *
 */
 void MostrarDNI(ePersona usuario[], long int auxDNI,int tam);

 /** \brief Ordena por Nombre la mustra de datos.
  *
  * \param usuario el array se pasa como parametro.
  * \param tam tamaño del array que se pasa como paramaetro.
  * \return
  *
  */
void MostrarOrden(ePersona usuario[], int tam);

/** \brief Diseña un grafico de barra que se categoriza segun una edad estandar.
 *
 * \param usuario el array se pasa como parametro.
 * \param tam tamaño del array que se pasa como paramaetro.
 * \return
 *
 */
void GraficoEDAD(ePersona usuario[],int tam);
#endif // FUNCIONES_H_INCLUDED

