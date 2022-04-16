#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"


/**
 * @fn float calculoDiferencia(float, float)
 * @brief Funcion que devuleve la diferencia entre dos n�meros, tomando el de mayor valor como munuendo
 * y el de menor valor al sustraendo
 * @pre
 * @post
 * @param valor1 uno de los valores a restar
 * @param valor2 otro de los valores a restar
 * @return devuleve la resta de los numeros, dando valor positivo
 */
static float calculoDiferencia(float operator1, float operator2);



static float calculoDiferencia(float operator1, float operator2)
{
	float buffer;
	if (operator1 > operator2)
	{
		buffer = operator1-operator2;
	}
	else
	{
		buffer = operator2-operator1;
	}
	return buffer;
}


int calculoPrecio(float cost, int payment, float *price, float BTCPrice)
{
	int retorno;
	retorno = -1;
	float buffer;

	switch (payment)
	{
		case 0:

			buffer = cost - cost * 10 / 100 ;
			retorno = 0;
			break;

		case 1:

			buffer = cost + cost * 25 / 100 ;
			retorno = 0;
			break;
		case 2:

			buffer = cost/BTCPrice ;

			retorno = 0;
			break;
	}
	*price = buffer;
	return retorno;
}

//submenu para la opcion 4

int reportOfResults(int distancia,float precio1, float precio2, float debito1, float credito1, float btc1, float unitario1, float debito2, float credito2, float btc2, float unitario2)
{
	int retorno;
	retorno = -1;
	printf("KMs Ingresados: %d km\n\n", distancia);
	printf("Precio Aerolineas: $ %.2f\n", precio1);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", debito1);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", credito1);
	printf("c) Precio pagando con bitcoin: %.5f BTC\n", btc1);
	printf("d) Mostrar precio unitario: %.2f\n\n", unitario1);
	printf("Precio Latam: $ %.2f\n", precio2);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", debito2);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", credito2);
	printf("c) Precio pagando con bitcoin: %.5f BTC\n", btc2);
	printf("d) Mostrar precio unitario: %.2f\n\n", unitario2);
	printf("La diferencia de precio es: %.2f\n\n", calculoDiferencia(precio1, precio2));
	printf("Presiones cualquier para continuar");
	getchar();

	return retorno;
}


