#ifndef GENERAL_H_
#define GENERAL_H_

										/********** UTN **********/

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);
int isName(char* cadena,int longitud);
int getString(char* cadena, int longitud);
int utn_getChararcter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);
int myGets(char* cadena, int longitud);
unsigned int verifica(void);

#endif /* GENERAL_H_ */
