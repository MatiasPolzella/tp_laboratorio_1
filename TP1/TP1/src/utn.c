#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isNumeric(char* cadena);
static int myGets(char* cadena, int longitud);
static int getInt(int * pResultado);
static int getFloat(float* pResultado);


static int isNumeric(char* cadena)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if (cadena[i] == '.')
			{
				i++;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	} return retorno;
}


int getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1; //lo cargo de ante mano con el

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


int getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
	float bufferFloat;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
			return 0;
	}
	return -1;
}


static int getInt(int * pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && isNumeric(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}



static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
