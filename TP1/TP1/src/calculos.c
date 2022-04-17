#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"


/// @fn getPriceDifference
/// @brief Esta funcion nos permitirá calcular la diferencia de precios entre Aerolineas Argentinas y Latam
/// @param operator1
/// @param operator2
/// @return La direrencia de precios mediante una resta
static float getPriceDifference(float operator1, float operator2);



static float getPriceDifference(float operator1, float operator2)
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

/// @fn  getPrice
/// @brief Realizará los calculos necesarios para obtener el valor del viaje en: debito, credito y Bitcoin
/// @param cost Precio del vuelo para calcular los descuentos
/// @param payment Recibe 0 pago con Débito, 1 para crédito y 2 con BTC
/// @param price Puntero que recibe el precio con los descuentos (o recargos) segun la forma de pago
/// @param BTCPrice Es el valor del Bitcoin para poder realizar el calculo
/// @return En caso de exito (0), en caso de error (-1)
int getPrice(float cost, int payment, float * price, float BTCPrice)
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
			buffer = cost/BTCPrice;

			retorno = 0;
			break;
	}
	*price = buffer;
	return retorno;
}

/// @fn int reportOfResults
/// @brief Nos muestra el informe de resultados con los precios ya cargados
/// @param distance
/// @param priceAA
/// @param debitAA
/// @param creditAA
/// @param BTCAA
/// @param priceUnitAA
/// @param priceLatam
/// @param debitLatam
/// @param creditLatam
/// @param BTCLatam
/// @param priceUnitLatam
/// @return el informe con los resultados
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
	printf("La diferencia de precio es: %.2f\n\n", getPriceDifference(precio1, precio2));
	printf("Presiones una tecla para continuar");
	getchar();

	return retorno;
}
