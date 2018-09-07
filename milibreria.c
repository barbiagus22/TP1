#include <stdio.h>
#include "milibreria.h"

/** \brief Solicita un primer numero.
* \param operando1 es el primer numero a pedir para ejecutar operaciones.
* \return devuelve el valor ingresado  para ejeccion las operaciones necesarias.
*
*/
float ingresarOperando1 ( float operando1)
{
    printf( " \n Ingrese 1er operando ( A = x ):   \n\n ");
    scanf( "%f", &operando1);
    return operando1;

}

/** \brief Solicita un segundo numero, y se valida que no se igual a 0.
* \param operando1 es el primer numero a pedir para ejecutar operaciones.
* \return Devuelve el valor ingresado  para ejeccion las operaciones necesarias.
*
*/
float ingresarOperando2 ( float operando2)
{
    printf( " \n Ingrese 2do operando ( B = y ):   \n\n ");
    scanf( "%f", &operando2);
    return operando2;

}


/** \brief Ejecuta la suma de dos numeros.
* \param op1 es el 1er numero a sumar y op2 segundo a sumar.
* \return Devuelve el resultado de la suma.
*
*/
float suma( float operando1, float operando2)
{
    float suma;
    suma= operando1 +operando2;
    return suma;

}

/** \brief Ejecuta la resta de dos numeros.
* \param op1 es el 1er numero a restar y op2 segundo a restar.
* \return Devuelve el resultado de la resta.
*
*/
float resta(float operando1, float operando2)
{
    float resta;
    resta= operando1-operando2;
    return resta;

}

/** \brief Ejecuta la division de dos numeros.
* \param op1 es el 1er numero a dividir y op2 segundo a dividir.
* \return Devuelve el resultado de la division.
*
*/
float division(float operando1, float operando2)
{
    float division=0;
    division= operando1/operando2;
    return division;

}

/** \brief Ejecuta la multiplicacion de dos numeros.
* \param op1 es el 1er multiplicaciones y op2 segundo a multiplicar.
* \return Devuelve el resultado de la multiplicacion.
*
*/

float multiplicacion(float operando1, float operando2)
{
    float multiplicacion;
    multiplicacion= operando1*operando2;
    return multiplicacion;
}

/** \brief La funcion calcula el factorial del primer operando ingresado.
 * \param operando1 es el numero ingresado por el usuario a la cual se va ejecutar la funcion.
 * \param x Es la variable creada para ejecutar el bucle for.
 * \return retorna el factorial del primer operando ingresado.
 *
 */

float factorialUno (float operando1)
{
    float x,factorialUno=1;

    for (x = operando1; x>1 ; x--)
    {
        factorialUno*=x;
    }
    return factorialUno;
}

/** \brief La funcion calcula el factorial del segundo operando ingresado.
 * \param operando2 es el numero ingresado por el usuario a la cual se va ejecutar la funcion.
 * \param x Es la variable creada para ejecutar el bucle for.
 * \return retorna el factorial del segundo operando ingresado.
 *
 */

float factorialDos (float operando2)
{
    float x,factorialDos=1;

    for (x = operando2; x>1 ; x--)
    {
        factorialDos*=x;
    }
    return factorialDos;
}





