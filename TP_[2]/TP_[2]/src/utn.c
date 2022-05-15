#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getDescription(char* cadena, int len);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getNameSurname(char* cadena, int len);
static int isNameSurname(char* cadena, int len);
static int isNumericInt(char* cadena, int len);
static int isNumericFloat(char* cadena, int len);
static int isDescription(char* cadena, int len);


int utn_getNameSurname(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)
	{
		do{
			printf("%s", mensaje);
			if(!getNameSurname(bufferString,sizeof(bufferString))) //Call my internal function static int getNameSurname which contains the validation
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


static int getNameSurname(char* cadena, int len) //gets a valid string such a name or last name.
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && len > 0 && !getString(bufferString,sizeof(bufferString)) && isNameSurname(bufferString,sizeof(bufferString)) && strnlen(bufferString,sizeof(bufferString)) < len)
    	{
    		strncpy(cadena,bufferString,len);
			retorno = 0;
		}
    return retorno;
}

static int getString(char* cadena, int len) //requests a string of characters from the user and validates it
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno = 0;
			}
		}
	}
	return retorno;
}


static int isNameSurname(char* cadena, int len) //check if the string entered is a valid name or last name.
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esCuit(char* cadena)
{
	int ret;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					ret=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			ret=0;
		}
	}
	return ret;
}

int utn_getCuit(char* pResultado,char mensaje[],char eMensaje[],int reintentos)
{
	int ret;
	char buffer[14];
	int i;
	int aux;

		if(pResultado!=NULL && mensaje!= NULL && eMensaje!= NULL && reintentos>0)
		{
			for(i=reintentos;i>0;i--)
			{
				printf("\n %s",mensaje);
				fflush(stdin);
				fgets(buffer,14,stdin);
				aux=esCuit(buffer);
				if(aux==0)
				{
					if(buffer[2]=='-' && buffer[11]=='-')
					{
						strcpy(pResultado,buffer);
						ret=0;
						break;
					}
				}
				else
				{
					printf("\n %s\n",eMensaje);
				}
			}
		}
		if(reintentos==0)
		{
			ret=-1;
		}
	return ret;
}



int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)
	{
		do
		{
			printf("%s",mensaje);
			if(!getInt(&bufferInt) && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


static int getInt(int* pResultado) //gets a valid string as an integer number.
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL && !getString(bufferString,sizeof(bufferString)) &&
	   isNumericInt(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString);
	}
    return retorno;
}


static int isNumericInt(char* cadena, int len) //it will check if the string entered is a valid a integer.
{
	int retorno = 0;
	int i;
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getDescription(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)
	{
		do{
			printf("%s", mensaje);
			if(!getDescription(bufferString,sizeof(bufferString)))
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


static int getDescription(char* cadena, int len) //gets a valid string as a description.
{
    int retorno=-1;
    char bufferString[4096];

    if( cadena != NULL && len > 0 && !getString(bufferString,sizeof(bufferString)) &&
		isDescription(bufferString,sizeof(bufferString)) && strnlen(bufferString,sizeof(bufferString)) < len)
    	{
    		strncpy(cadena,bufferString,len);
			retorno = 0;
		}
    return retorno;
}


static int isDescription(char* cadena, int len) //It will check if the string entered is a description.
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if( cadena[i] != '.' &&
				cadena[i] != ',' &&
				cadena[i] != ' ' &&
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
				(cadena[i] < 'a' || cadena[i] > 'z' ) &&
				(cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)
	{
		do
		{
			printf("%s",mensaje);
			if(!getFloat(&bufferFloat) && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


static int getFloat(float* pResultado) //gets a valid string as a floating number.
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL && !getString(bufferString,sizeof(bufferString)) &&
	   isNumericFloat(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atof(bufferString);
	}
    return retorno;
}


static int isNumericFloat(char* cadena, int len) //check if the string entered is a valid floating number.
{
	int retorno = 0;
	int i;
	int contadorPuntos = 0;
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
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

int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getAlfanumeric(char* input, char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos)
{
	int retorno=-1;
	char bufferStr[maxSize];

	if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
	{
		do
		{
			if(!getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr))
			{
				if(isValidAlphanumeric(bufferStr)==1)
				{
					strncpy(input,bufferStr,maxSize);
					retorno=0;
					break;
				}
				else
				{
					printf("%s 2",mensajeError);
					reintentos--;
				}
			}
		}
		while(reintentos>=0);
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



