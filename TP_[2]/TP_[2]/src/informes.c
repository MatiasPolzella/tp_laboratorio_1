
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "informes.h"


int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1;
	int swap;
	int i;
	int auxComparison;
	Passenger auxiliar;

	if(list != NULL && len > 0)
	{
		do
		{
			swap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxComparison = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if(order == 1 && (auxComparison > 0 || (auxComparison == 0 && list[i].typePassenger > list[i+1].typePassenger)))
				{
					swap = 1;
					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]=auxiliar;
				}
				else if( order == 2 && (auxComparison < 0 || (auxComparison == 0 && list[i].typePassenger > list[i+1].typePassenger)))
				{
					swap = 1;
					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]=auxiliar;
				}
			}
			len--;
		}while(swap);
		if(!printPassenger(list,len))
		{
			printf("Lista de pasajeros ordenada correctamente.\n");
		}
	}
	return retorno;
}


int averagePassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	int contPassenger = 0;
	int contSupAverage = 0;
	float acumPrice = 0;
	float averagePrice;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumPrice += list[i].price;
				contPassenger++;
			}
		}

		if(contPassenger > 0)
		{
			averagePrice = acumPrice / (float)contPassenger;
		}

		for(i=0;i<len;i++)
		{
			if( list[i].isEmpty == 0 && list[i].price > averagePrice)
			{
				contSupAverage++; //count of passengers who exceed the average flight price.
			}
		}
		retorno = 0;
	}

	printf("El total de precios de los pasajes es: %.2f - Y el promedio es: %.2f\n",acumPrice,averagePrice);
	printf("La cantidad de pasajeros que superan el precio promedio es: %d\n",contSupAverage);
	return retorno;
}

