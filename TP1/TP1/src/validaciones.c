
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
	int retorno = -1; //lo cargo con el error
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do //el do me asegura que la primera vez se va a cumplir
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo) //si se da esta condicion, esta todo ok. sino, imprimira el mensaje de error y decrementará reintentos
			{
				*pResultado = bufferInt;
				retorno = 0; //para indicar el exito
				break; //si esta todo ok, hago un break y eso hace que deje de reintentar
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno; //me aseguro que devuelva el error, excepto que yo haga algo distinto
}


int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos)
{
		float retorno = -1;
		float bufferFloat;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				scanf("%f",&bufferFloat);
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}while(reintentos >= 0);
		}

		return retorno;
	}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int reintentos)
{
	int retorno = -1; //lo cargo con el error
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do //el do me asegura que la primera vez se va a cumplir
		{
			printf("%s",mensaje);
			fflush(stdin); //va arriba del scanf para poder limpiar el buffer
			scanf("%c",&bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo) //si se da esta condicion, esta todo ok
			{
				*pResultado = bufferChar;
				retorno = 0; //para indicar el exito
				 break;//si esta todo ok, hago un break y eso hace que deje de reintentar
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; //decremento en 1 los reintentos
			}

		}while(reintentos >= 0);
	}

	return retorno; //me aseguro que devuelva el error, excepto que yo haga algo distinto
}
