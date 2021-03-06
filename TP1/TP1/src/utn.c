#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


/// @fn int isNumeric
/// @brief Recibe una cadena, recorre todos los caracteres de la cadena, y si alguno no es numerico, el bucle termina y la varable retorno quedara cargada en -1
/// y devuelve 1 en el caso de que el texto este compuesto solo por numeros
/// @param cadena
/// @return Devuelve 1 en el caso que los caracteres sean todos numericos
static int isNumeric(char* cadena);

/// @fn int myGets
/// @brief Valida desde​ stdin​ hasta​​ que​ encuentra​ ​un​ '\n' o hasta​​ que​​ haya​​ copiado​ en​ ​cadena un​ máximo​ de longitud de caracteres
/// @param cadena
/// @param longitud Tamaño de la cadena
/// @return En caso de exito (0), en caso de error (-1)
static int myGets(char* cadena, int longitud);

/// @fn int getInt
/// @brief Valida si la cadena es numerica
/// @param pResultado Puntero donde se alojara el resultado de la funcion
/// @return En caso de exito (0), en caso de error (-1)
static int getInt(int * pResultado);

/// @fn int getFloat(float*)
/// @brief Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como float
/// @param pResultado pResultado Puntero donde se alojara el resultado de la funcion
/// @return En caso de exito (0), en caso de error (-1
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

/// @fn getNumberInt
/// @brief Solicita un numero entero al usuario, lo valida, verifica y devuelve el resultado
/// @param pResultado Puntero al resultado, alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje mostrado en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor maximo aceptado
/// @param reintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1; //lo cargo de ante mano con el error

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

/// @fn getNumberFloat
/// @brief Solicita un numero decimal al usuario, lo valida, verifica y devuelve el resultado
/// @param pResultado Puntero al resultado, alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje mostrado en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor maximo aceptado
/// @param reintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)

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
