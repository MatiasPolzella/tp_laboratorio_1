#include <stdio.h>
#include <stdlib.h>
#include "costos.h"

float pagoConDebito(float valorVuelo)
{
    float retorno;
    float acumulador;

    acumulador=valorVuelo * 10 / 100;
    retorno = valorVuelo - acumulador;

    return retorno;
}

/*


	FUNCION PARA CALCULAR BTC:

precioXBitcoin/ValorVuelo


	FUNCION PARA CALCULAR INTERES:

(conviene tener una funcion de multiplicacion,ej. Multiplicacion(valorVuelo, 0*25) y eso guardarlo
en una variable auxiliar, ese auxiliar sumarlo al valor de vuelo en otra variable de nombre, por ejemplo,
valorConInteres, y devolver ese valor


	FUNCION PARA MOSTRAR PRECIO POR KILOMETRO (PRECIO UNITARIO):

importeIngresado * kmIngresado

	FUNCION PARA MOSTRAR DIFERENCIA DE PRECIO INGRESADA (LATAM - AEROLINEAS):



*/
