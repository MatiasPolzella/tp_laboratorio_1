/*
 ============================================================================

 Nombre: Trabajo Practico N�1 - Agencia de Viajes
 Autor: Matias Polzella
 Comision: 1H

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"

#define DEBIT 0
#define CREDIT 1
#define BTC 2
#define BTCPRICE 4606954.55


int main(void) {

	setbuf(stdout,NULL);

	int option;
	int ok; //  para validar que tengo todos los valores cargados antes de calcular
	int numberOfKilometers = 0;
	float valueAA = 0;
	float valueLatam = 0;
	float debitAA;
	float debitLatam;
	float creditAA;
	float creditLatam;
	float bitcoinAA;
	float bitcoinLatam;
	float priceUnitAA;
	float priceUnitLatam;
	//Carga Forzada
	float forcedDataUploadAA = 162965;
	float forcedDataUploadLatam = 159339;
	float forcedKMLoad = 7090;


	do
	{
	    printf("**********************************************");
		printf("\n            MENU PRINCIPAL                \n");
	    printf("**********************************************\n");
		printf("1. Ingresar Kilometros: (km=%d)\n",numberOfKilometers);
		printf("2. Ingresar Precio de Vuelos: (\n   Aerolineas=$ %.2f $, Latam=$ %.2f\n", valueAA, valueLatam);
		printf("3. Calcular todos los costos:\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		fflush(stdin);

		getNumberInt(&option,"\nPor favor, ingrese que accion desea realizar:\n","La opcion ingresada no es valida. Intente nuevamente\n", 1, 6, 2);

		switch (option)
		{
		case 1: /*INGRESAR KILOMETROS*/

			if(!getNumberInt(&numberOfKilometers, "Ingrese la cantidad de Km del viaje que desea realizar (recuerde que las opciones validas"
			                                      " son entre 3000 y 15000km): \n", "Valor inv�lido. Intente nuevamente\n", 3000, 15000, 2))
			{
				ok = 0; //si salio bien la validacion
			}
			else
			{
				ok = 1;
			}
			break;

		case 2: /*INGRESAR PRECIO DE VUELOS*/

			if(!getNumberFloat(&valueAA, "Precio vuelo Aerolineas:\n" , "Error. El Rango de precios disponibles ronda los 2500 a 150000\n", 2500, 1500000, 2))
			{
				ok = 0; //si salio bien la validacion
			}
			else
			{
				ok = 2; //si salio mal la validacion
			}
			if(!getNumberFloat(&valueLatam, "Precio vuelo Latam:\n" , "Error. El Rango de precios disponibles ronda los 2500 a 150000\n", 2500, 1500000, 3))
			{
				ok = 0; //si salio bien la validacion
			}
			else
			{
				ok = 3; //si salio mal la validacion
			}
			break;

		case 3: /*CALCULAR COSTOS*/

			switch (ok)
			{
				case 0:
					//realizo los calculos para aerolineas
					if(!calculoPrecio(valueAA ,DEBIT ,&debitAA, BTCPRICE) && !calculoPrecio(valueAA,CREDIT , &creditAA, BTCPRICE)
					   && !calculoPrecio(valueAA,BTC, &bitcoinAA, BTCPRICE))
					{
						priceUnitAA=valueAA/numberOfKilometers;
					}
					//realizo los calculos para latam
					if(!calculoPrecio(valueLatam ,DEBIT ,&debitLatam, BTCPRICE) && !calculoPrecio(valueLatam,CREDIT , &creditLatam, BTCPRICE)
					   && !calculoPrecio(valueLatam,BTC, &bitcoinLatam, BTCPRICE))
					{
						priceUnitLatam=valueLatam/numberOfKilometers;
					}
					break;
				case 1:
					//mensaje de error si hay un dato no valido en los km del vuelo
					printf("Se ha producido un error al ingresar los KM. Volver� al menu principal\n");
					break;
				case 2:
					//mensaje de error si hay dificultades con el precio de AA
					printf("se ha producido un error al intentar cargar el precio de Aerolineas. Volver� al menu principal\n");
					break;
				case 3:
					//mensaje de error si hay dificultades con el precio de LA
					printf("se ha producido un error al intentar cargar el precio de Latam. Volver� al menu principal\n");
					break;
			}
			break;

		case 4: /*INFORMAR RESULTADOS*/

			if (ok==0)
			{
				reportOfResults(numberOfKilometers,valueAA, valueLatam, debitAA, creditAA, bitcoinAA, priceUnitAA, debitLatam, creditLatam, bitcoinLatam, priceUnitLatam);
			}
			else
			{
				printf("No podemos informar los resultados si no ha cargado los valores anteriormente. Volver� al menu principal\n");
			}
			break;

		case 5: /*CARGA FORZADA DE DATOS*/

			calculoPrecio(forcedDataUploadAA ,DEBIT ,&debitAA, BTCPRICE);
			calculoPrecio(forcedDataUploadAA,CREDIT , &creditAA, BTCPRICE);
			calculoPrecio(forcedDataUploadAA,BTC, &bitcoinAA, BTCPRICE);
			priceUnitAA = forcedDataUploadAA /forcedKMLoad;

			calculoPrecio(forcedDataUploadLatam ,DEBIT ,&debitLatam, BTCPRICE);
			calculoPrecio(forcedDataUploadLatam,CREDIT , &creditLatam, BTCPRICE);
			calculoPrecio(forcedDataUploadLatam,BTC, &bitcoinLatam, BTCPRICE);
			priceUnitLatam = forcedDataUploadLatam/forcedKMLoad;

			reportOfResults(forcedKMLoad,forcedDataUploadAA, forcedDataUploadLatam, debitAA, creditAA,
			bitcoinAA, priceUnitAA, debitLatam, creditLatam, bitcoinLatam, priceUnitLatam);
			break;

			case 6: /*SALIR*/

			break;
		}

	}while(option != 6);

	return 0;
}


