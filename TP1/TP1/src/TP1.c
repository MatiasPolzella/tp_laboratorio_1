/*
 ============================================================================

  	  Trabajo Practico N?1 - Agencia de Viajes

 Nombre: Matias Polzella
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
	float forcedDataUploadAA = 162965 ;
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
			                                      " son entre 3000 y 15000km): \n", "Valor inv?lido. Intente nuevamente\n", 3000, 15000, 2))
			{
				ok = 0; // 0 =  que los datos ingresados son correctoss. != 0 no se pudo realizar la operacion
			}
			else
			{
				ok = 1;
			}
			break;

		case 2: /*INGRESAR PRECIO DE VUELOS*/

			if(!getNumberFloat(&valueAA, "Precio vuelo Aerolineas:\n" , "Valor inv?lido. Intente nuevamente\n", 2500, 1500000, 2))
			{
				ok = 0;
			}
			else
			{
				ok = 2;
			}
			if(!getNumberFloat(&valueLatam, "Precio vuelo Latam:\n" , "Valor inv?lido. Intente nuevamente\n", 2500, 1500000, 2))
			{
				ok = 0;
			}
			else
			{
				ok = 3;
			}
			break;

		case 3: /*CALCULAR COSTOS*/

			switch (ok)
			{
				case 0:

					if(!getPrice(valueAA ,DEBIT ,&debitAA, BTCPRICE) && !getPrice(valueAA,CREDIT , &creditAA, BTCPRICE)
					   && !getPrice(valueAA,BTC, &bitcoinAA, BTCPRICE))
					{
						priceUnitAA =valueAA / numberOfKilometers;
					}

					if(!getPrice(valueLatam ,DEBIT ,&debitLatam, BTCPRICE) && !getPrice(valueLatam,CREDIT , &creditLatam, BTCPRICE)
					   && !getPrice(valueLatam,BTC, &bitcoinLatam, BTCPRICE))
					{
						priceUnitLatam = valueLatam / numberOfKilometers;
					}
					break;

				case 1:

					printf("Se ha producido un error al ingresar los KM. Volver? al menu principal\n");
					break;

				case 2:

					printf("se ha producido un error al intentar cargar el precio de Aerolineas. Volver? al menu principal\n");
					break;

				case 3:

					printf("se ha producido un error al intentar cargar el precio de Latam. Volver? al menu principal\n");
					break;
			}
			break;

		case 4: /*INFORMAR RESULTADOS*/

			if (ok==0) //es decir, validamos si el usuario carg? los datos previamente
			{
				reportOfResults(numberOfKilometers,valueAA, valueLatam, debitAA, creditAA, bitcoinAA, priceUnitAA, debitLatam, creditLatam, bitcoinLatam, priceUnitLatam);
			}
			else
			{
				printf("No podemos informar los resultados si no ha cargado los valores anteriormente. Volver? al menu principal\n");
			}
			break;

		case 5: /*CARGA FORZADA DE DATOS*/

			getPrice(forcedDataUploadAA ,DEBIT ,&debitAA, BTCPRICE);
			getPrice(forcedDataUploadAA,CREDIT , &creditAA, BTCPRICE);
			getPrice(forcedDataUploadAA,BTC, &bitcoinAA, BTCPRICE);
			priceUnitAA = forcedDataUploadAA / forcedKMLoad;

			getPrice(forcedDataUploadLatam ,DEBIT ,&debitLatam, BTCPRICE);
			getPrice(forcedDataUploadLatam,CREDIT , &creditLatam, BTCPRICE);
			getPrice(forcedDataUploadLatam,BTC, &bitcoinLatam, BTCPRICE);
			priceUnitLatam = forcedDataUploadLatam/ forcedKMLoad;

		    reportOfResults(forcedKMLoad,forcedDataUploadAA, forcedDataUploadLatam, debitAA, creditAA,
			bitcoinAA, priceUnitAA, debitLatam, creditLatam, bitcoinLatam, priceUnitLatam);
			break;

			case 6: /*SALIR*/

			break;
		}

	}while(option != 6);

	return 0;
}

