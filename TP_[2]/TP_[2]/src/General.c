#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <ctype.h>
#include "General.h"
                                        			/********** UTN **********/

static int isNumeric(char* cadena, int limite);
static int getInt(int* pResultado);
static int isFloat(char* cadena);
static int getFloat(float* pResultado);
static int getName(char* pResultado, int longitud);

//----------------------------------------------- NUMEROS ENTEROS Y FLOTANTES------------------------------------------------------------

/*independientemente de lo que queremos obtener con esta funcion es un numero, vamos a poder leer lo que el usuario nos ingresa como texto(que es texto lo que el usuario nos ingresa)
//vamos a poder verifica lo que el usuario nos ingresa y darnos cuenta si eso que el usuario nos acaba de dar lo podemos o no convertir a un numero. Y despues de que lo convertimos a un numero
vamos a validar si esta entre el minimo y el maximo*/ //CHAU SCANF() xq aca voy a utilizar una funcion para obtener informacion desde el teclado --> myGets()
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{

	int retorno = -1; //lo cargo con el error
	int buffer;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do //el do me asegura que la primera vez se va a cumplir
			{
				printf("%s",mensaje);
				if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) //si getInt devuelve cero, es porque me obtuvo un entero. Si se da esta condicion, esta todo ok.
				{
					*pResultado = buffer;
					retorno = 0; //para indicar el exito
					break; //si esta todo ok, hago un break y eso hace que deje de reintentar
				}
				else
				{
					reintentos--;
					printf("%s",mensajeError);
				}
			}while(reintentos >= 0);
		}


	return retorno; //me aseguro que devuelva el error, excepto que yo haga algo distinto
}

/// @fn int getInt(int*)
/// @brief obtiene un numero entero desde la terminal (busca como resultado un entero)
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
static int getInt(int* pResultado) // getInt = para obtener el numero
{
	int retorno=-1;
	char bufferString[4096]; //buffer de texto grande para que el usuario pueda ingresar muchos caracteres

	 //le paso el tamaño del que no quiero desbordar con sizeof()
	if(pResultado != NULL && myGets(bufferString,sizeof(bufferString))==0 && isNumeric(bufferString,sizeof(bufferString))) //osea, que me devuelve verdado. isNumeric me dice si lo que hay dentro de buffer son numeros. Si son numeros, los puedo convertir. Sino, va a devolver -1 (error)
	{
		retorno = 0; //recien cuando se cumplan esas 2 condiciones, voy a retornar un cero y voy a convertir el numero
		*pResultado = atoi(bufferString);//si buffer tiene solamente numeros, mediante atoi() yo lo puedo convertir en un integer, osea un texto en un int. (Aca debo estar seguro que dentro de ese texto SOLAMENTE hay numeros)
	}
	return retorno;
}


/// @fn int isNumeric
/// @brief verifica si la cadena ingresada es numerica
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (verdadero) si la cadena es numerica, retorna 0 (falso) si no lo es y -1 en caso de error
static int isNumeric(char* cadena, int limite) //esta es una funcion de validacion
{
	int retorno = -1; // Error
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // si pude validar la condicion del if, puedo decir que retorno es verdadero
		for(i=0; i<limite && cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @fn int myGets(char*, int)
/// @brief lee de stdin hasta que encuentra un salto de linea '\n' o hasta que se haya copiado en cadena
/// un maximo de 'longitud - 1' en caracteres
/// @param cadena
/// @param longitud Define el tamaño de cadena (es lo que el usuario me da como limite)
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int myGets(char* cadena, int longitud)
{//todo esto es la forma correcta de usar fgets()
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0) //
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL) //si sale todo bien me devuelve un puntero a bufferString, si sale todo mal me devuelve NULL. Llamo a fgets() y pregunto si la respuesta fue distinta de NULL
		{															//Basicamente llamo a fgets() y pregunto si la respuesta fue distinto a NULL
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n') //me pregunto si lo que estoy por pisar es un '\n', si es un '\n' lo piso
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';//si no es un '\n' no lo piso, no hago nada. Esto es para ubicar la ultima posicon '\0', debo usar strlen()
			}// el -1 para ir una posicion anterior

			if(strnlen(bufferString,sizeof(bufferString)) <= longitud) //para preguntar cuanto mide la cadena resultante (osea lo que acabamos de leer)
			{
				strncpy(cadena,bufferString,longitud);//para copiar un string en otro
				retorno = 0;//recien aca, cuando pude copiar la cadena, me aseguro que esta todo bien
			}
		}
	}
	return retorno;
}



int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos)
{
	int retorno = -1; //lo cargo con el error
	float bufferFloat;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do //el do me asegura que la primera vez se va a cumplir
			{
				printf("%s",mensaje);
				if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo) //si getInt devuelve cero, es porque me obtuvo un entero. Si se da esta condicion, esta todo ok.
				{
					*pResultado = bufferFloat;
					retorno = 0; //para indicar el exito
					break; //si esta todo ok, hago un break y eso hace que deje de reintentar
				}
				else
				{
					reintentos--;
					printf("%s",mensajeError);
				}
			}while(reintentos >= 0);
		}


	return retorno; //me aseguro que devuelva el error, excepto que yo haga algo distinto
}

static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && isFloat(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

static int isFloat(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


//-----------------------------------------------PARA TEXTOS Y CARACTERES------------------------------------------------------------

int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getName(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

static int getName(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && isName(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int isName(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getCharacter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
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
				retorno = 0;  //para indicar el exito
				break; //si esta todo ok, hago un break y hago que deje de reintentar
			}
			printf("%s",mensajeError);
			reintentos--; //decremento en 1 los reintentos
		}while(reintentos>=0);

	}
	return retorno;
}

/// @fn unsigned int verifica(void)
/// @brief Verifica el ingreso de caracteres.Chequea para que solo sean admitidas las letras S o N.
/// @return  0 si se ingreso la N, 1 si se ingreso la S

/*unsigned int verifica(void)
{
	char letra;

	printf("\nIngrese opcion...S/N?");
	letra=toupper(getche());
	while(!((letra=='S')||(letra=='N')))
	{
		printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
		letra=toupper(getche());
	}
	return (letra=='S');
}
*/

