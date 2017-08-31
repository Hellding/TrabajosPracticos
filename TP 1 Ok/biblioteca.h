#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un numero al usuario del programa.
 *
 * \return Retorna el numero ingresado.
 *
 */
float pedirNUM();

/** \brief Suma los dos operadores ingresados.
 *
 * \param Primer Operador.
 * \param Segundo Operador.
 * \return Retorna la suma de los operadores.
 *
 */
float SUMA(float num1,float num2);

/** \brief Resta el segundo operador al primer operador.
 *
 * \param Primer Operador.
 * \param Segundo Operador.
 * \return Retorna el producto de la resta del segundo operador al primer operador.
 *
 */
float RESTA(float num1,float num2);

/** \brief Multiplica al primer operador por el segundo operador.
 *
 * \param Primer Operador.
 * \param Segundo Operador.
 * \return Retorna el producto de multiplicar el primer operador por el segundo operador.
 *
 */
float MULTIPLICACION(float num1,float num2);

/** \brief Divide al primer operador por el segundo operador.
 *
 * \param Primer Operador.
 * \param Segundo Operador.
 * \return Retorna el producto de dividir el primer operador por el segundo operador.
 *
 */
float DIVISION(float num1,float num2);

/** \brief Calcula el Factorial de primer operador.
 *
 * \param Primer Operador.
 * \return Retorna el Factorial de primer operador.
 *
 */
long long int FACTORIAL(float num1);

/** \brief Verifica si se puede factorizar el primer operador.
 *
 * \param Primer Operador.
 * \return Retorna 0 si se puede realizar el factorial, y 1 si no se puede.
 *
 */
int VALFACT(float num1);
