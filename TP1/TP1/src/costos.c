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

/*float pagoConCredito(float valorVuelo, float interes)
{
    float retorno;
    float acumulador;


    return retorno;
}
*/