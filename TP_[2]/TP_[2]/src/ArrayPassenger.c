
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"


int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len >0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}


int addPassengers(Passenger* list, int len, int id, char* name,char* lastName,float price,int typePassenger, char* flyCode)
{
	int retorno = -1;
	int indice;

	indice = getEmptyIndex(list,len);
	if(	list != NULL && len >0 && id > -1 && name != NULL && lastName != NULL && price > 0 && indice > -1)
	{
		retorno = 0;
		strncpy(list[indice].name,name,NAME_LEN);
		strncpy(list[indice].lastName,lastName,LASTNAME_LEN);
		list[indice].price = price;
		list[indice].typePassenger = typePassenger;
		list[indice].isEmpty = 0;
		list[indice].id = id;
	}
	return retorno;
}


int getEmptyIndex(Passenger* list, int len) //will look the first empty position.
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int findPassengerById(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)
	{
		for(i=0;i<len;i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				retorno = 0;
				list[i].isEmpty = 1;
				break;
			}
		}
	}
	return retorno;
}


int printPassenger(Passenger* list, int lenght)
{
	int retorno = -1;
	int i;

	if(list != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("%s, %s - Precio: %.2f - Tipo pasajero: %s - ID: %d\n",list[i].lastName,list[i].name,list[i].price,list[i].typePassenger,list[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int contPassenger(Passenger* list, int len) //it will count the number of existing passengers.
{
	int i;
	int contador = 0;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
			}
		}
	}
	return contador;
}


int modifPassenger(Passenger* list, int len, int id, int option)
{
	int retorno = -1;
	int i;
	Passenger auxiliar;

	if(list != NULL && len > 0 && id > -1 && option > 0 && option < 5)
	{
		for(i=0;i<len;i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				if( option == 1 &&
					!utn_getNameSurname(auxiliar.name,NAME_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2))
				{
					retorno = 0;
					strncpy(list[i].name,auxiliar.name,NAME_LEN);
					break;
				}
				else if( option == 2 &&
						 !utn_getNameSurname(auxiliar.lastName,LASTNAME_LEN,"Ingrese un apellido: \n","Apellido invalido.\n",2))
				{
					retorno = 0;
					strncpy(list[i].lastName,auxiliar.lastName,NAME_LEN);
					break;
				}
				else if( option == 3 &&
						!utn_getNumberFloat(&auxiliar.price,"Ingrese precio: \n","Precio invalido.\n",0,100000,2))
				{
					retorno = 0;
					list[i].price = auxiliar.price;
					break;
				}
				else if(option == 4 &&
						!utn_getNumberInt(&auxiliar.typePassenger,"Ingrese un sector (1 a 10): \n","Sector invalido.\n",1,10,2))
				{
					retorno = 0;
					list[i].typePassenger = auxiliar.typePassenger;
					break;
				}
			}
		}
	}
	return retorno;
}

