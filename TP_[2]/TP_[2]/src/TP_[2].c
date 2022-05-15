/*
 ============================================================================
  	  	  	  Trabajo Practico N°2 - ABM para Aerolinea

 Nombre: Matias Polzella
 Comision: 1H
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "informes.h"

#define PASSENGER_LEN 2000

int main(void) {

	setbuf(stdout, NULL);

	int option;
	int idPassenger = 0;
	int auxAlphaNumeric;
	int auxId;
	int auxModif;
	int auxInform;
	char auxName[NAME_LEN];
	char auxLastName[LASTNAME_LEN];
	float auxCuit;
	char auxFlyCode;

	Passenger arrayPassengers[PASSENGER_LEN];


	if(!initPassengers(arrayPassengers,PASSENGER_LEN))
	{
		printf("\n**********************************************");
		printf("\n            MENU PRINCIPAL                \n");
		printf("**********************************************\n");
	}

	do
	{
		if(!utn_getNumberInt(&option,"\n 1. ALTA"
								     "\n 2. MODIFICAR"
								     "\n 3. BAJA"
								     "\n 4. INFORMAR:"
									 "\n a. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
									 "\n b. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
								     "\n 5. Salir.\n"
									 "\nPor favor, ingrese que accion desea realizar:\n","La opcion ingresada es invalida.\n",1,5,3))
		{
			switch(option)
			{

			case 1: /*ALTA PASAJERO */

				if (!utn_getNameSurname(auxName,NAME_LEN,"Ingrese un nombre: \n","Error. Nombre invalido\n",2) &&
					!utn_getNameSurname(auxLastName,LASTNAME_LEN,"Ingrese un apellido: \n","Error. Apellido invalido\n",2) &&
					!utn_getCuit(auxCuit,"Ingrese su numero de CUIT: \n","Error. CUIT invalido\n",2) &&
					!utn_getAlfanumeric(auxAlphaNumeric,"Ingrese : \n","Sector invalido.\n",1,10,2) &&
					!addPassengers(arrayPassengers,PASSENGER_LEN,idPassenger,auxName,auxLastName,auxCuit,auxAlphaNumeric,auxFlyCode))
				{
					idPassenger++;
					printf("\nAlta de pasajero cargada con exito \n\n");
				}
				else
				{
					printf("\nError al dar de alta un nuevo pasajero. Intente nuevamente \n");
				}
				break;

			case 2: /*MODIFICAR PASAJERO*/

				if(contPassenger(arrayPassengers,PASSENGER_LEN) > 0 &&
				   !utn_getNumberInt(&auxId,"Por favor, ingrese el ID del pasajero: \n","ID invalido. Intente nuevamente",0,idPassenger,2) &&
				   findPassengerById(arrayPassengers,PASSENGER_LEN,auxId) > -1 &&
				   !utn_getNumberInt(&auxModif,"Por favor, ingrese el campo que desea modificar: \n"
												"\n1. Nombre\n"
												"\n2. Apellido\n"
												"\n3. Precio\n"
												"\n4. Tipo de pasajero\n"
						   	   	   	   	   	   	"\n5. Codigo de vuelo\n","Opcion invalida.\n",1,4,2) && !modifPassenger(arrayPassengers,PASSENGER_LEN,auxId,auxModif))
				{
					printf("Modificacion de empleado con exito \n");
				}
				else
				{
					printf("Error al modificar empleado. Intente nuevamente\n");
				}
				break;

			case 3: /*BAJA PASAJERO*/

				if(contPassenger(arrayPassengers,PASSENGER_LEN) > 0 &&
				   !utn_getNumberInt(&auxId,"Ingrese el ID del pasajero: \n","ID invalido",0,idPassenger,2) &&
				   findPassengerById(arrayPassengers,PASSENGER_LEN,auxId) > -1 &&
				   !removePassenger(arrayPassengers,PASSENGER_LEN,auxId))
				{
					printf("Baja de pasajero realizada con exito \n");
				}
				else
				{
					printf("Error al dar de baja un pasajero. Intente nuevamente \n");
				}
				break;

			case 4: /*INFORMES*/

				if(contPassenger(arrayPassengers,PASSENGER_LEN) > 0 &&
				   !utn_getNumberInt(&auxInform,"Por favor, ingrese la opcion que desee: \n"
												"\n1. Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n"
												"\n2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio\n"
						   	   	   	   	   	   	"\n3. Listado de los pasajeros por Codigo de vuelo y estados de vuelo 'ACTIVO'"
												,"Opcion invalida.\n",1,2,2))
				{
					if(auxInform == 1 && !utn_getNumberInt(&auxModif,"ingrese el orden que desee: \n"
																		"\n1. Ascendente.\n"
																		"\n2. Descendente.\n","Opcion invalida.\n",1,2,2) &&
						!sortPassengers(arrayPassengers,PASSENGER_LEN,auxModif))
					{
						printf("Ordenamiento con exito \n");
					}
					else if(auxInform == 2 && !averagePassengers(arrayPassengers,PASSENGER_LEN))
					{
						printf("Promedio e informes exitoso \n\n");
					}
				}
				else
				{
					printf("Error al calcular promedio e informes. Intente nuevamente.\n");
				}
				break;

			case 5:/*SALIR*/

				break;
			}
		}
	}while(option != 5);

	return EXIT_SUCCESS;
}

