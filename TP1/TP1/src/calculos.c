#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"



float getPriceDifference(float operator1, float operator2)
{
	float buffer;

	if (operator1 > operator2)
	{
		buffer = operator1 - operator2;
	}
	else
	{
		buffer = operator2 - operator1;
	}
	return buffer;
}


int getPrice(float cost, int payment, float *price, float BTCPrice)
{
	int retorno;
	retorno = -1; //lo cargo con el error, caso contrario devuelve cero
	float buffer;

	switch (payment)
	{
		case 0:

			buffer = cost - cost * 10 / 100 ; // para calcular el Debito
			retorno = 0;
			break;

		case 1:

			buffer = cost + cost * 25 / 100 ; // para calcular el Credito
			retorno = 0;
			break;

		case 2:

			buffer = cost/BTCPrice ; // para calcular btc

			retorno = 0;
			break;
	}

	*price = buffer;
	return retorno;
}


//submenu para la opcion 4
int reportOfResults(int distance, float priceAA, float debitAA, float creditAA, float BTCAA, float priceUnitAA, float priceLatam,float debitLatam,
					float creditLatam,float BTCLatam, float priceUnitLatam)
{
	int retorno;
	retorno = -1;

	printf("KMs Ingresados: %d km\n\n", distance);
	printf("Precio Aerolineas: $ %.2f\n", priceAA);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", debitAA);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", creditAA);
	printf("c) Precio pagando con bitcoin: %.5f BTC\n", BTCAA);
	printf("d) Mostrar precio unitario: %.2f\n\n", priceUnitAA);
	printf("Precio Latam: $ %.2f\n", priceLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", debitLatam);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", creditLatam);
	printf("c) Precio pagando con bitcoin: %.5f BTC\n",BTCLatam );
	printf("d) Mostrar precio unitario: %.2f\n\n", priceUnitLatam);
	printf("La diferencia de precio es: %.2f\n\n", getPriceDifference(priceAA, priceLatam));
	printf("Presione cualquier tecla para continuar:\n");
	getchar();

	return retorno;
}



