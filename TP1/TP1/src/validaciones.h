

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @fn
/// @brief Solicita un numero entero al usuario, lo valida, verifica y devuelve el resultado
/// @param pResultado Puntero al resultado, alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje mostrado en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor maximo aceptado
/// @param reintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);

/// @fn
/// @brief Solicita un numero entero al usuario, lo valida, verifica y devuelve el resultado
/// @param pResultado Puntero al resultado, alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje mostrado en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor maximo aceptado
/// @param reintentos reintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);

#endif /* VALIDACIONES_H_ */


