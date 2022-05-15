#ifndef UTN_H_
#define UTN_H_


/// @brief utn_getNumberInt Asks the user for a number and after verification returns the result
/// @param pResultado Pointer to the memory space, where the result of the function will be stored
/// @param mensaje Message to show the user to enter the number
/// @param mensajeError Error message, in case the number entered by the user is wrong
/// @param minimo It is the maximum number to be accepted
/// @param maximo It is the minimum number to be accepted
/// @param reintentos It is the amount of retries that the user will have
/// @return It returns zero if it obtained the first or last name and -1 if it had an error.
int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief utn_getNumberFloat Asks the user for a number and after verification returns the result
/// @param pResultado Pointer to the memory space, where the result of the function will be stored
/// @param mensaje Message to show the user to enter the number
/// @param mensajeError Error message, in case the number entered by the user is wrong
/// @param minimo It is the minimum number to be accepted
/// @param maximo It is the maximum number to be accepted
/// @param reintentos It is the amount of retries that the user will have
/// @return It returns zero if it got the float number and -1 if it had an error.
int utn_getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief utn_getNameSurname Requests a name and / or surname from the user
/// @param pResultado  Pointer to the memory space, where the result of the function will be stored
/// @param len Array length
/// @param mensaje Message to show the user to enter the number
/// @param mensajeError Error message, in case the number entered by the user is wrong
/// @param reintentos It is the amount of retries that the user will have
/// @return It returns zero if it obtained the first or last name and -1 if it had an error
int utn_getNameSurname(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

/// @brief utn_getCuit Requests a CUIT from the user, after verification returns the result
/// @param pResultado pResultado Pointer to the memory space, where the result of the function will be stored
/// @param len Array length
/// @param mensaje Message to show the user to enter the CUIT
/// @param mensajeError Error message in case the CUIT entered by the user is wrong
/// @param reintentos It is the amount of retries that the user will have
/// @return It returns zero if it obtained the first or last name and -1 if it had an error
int utn_getCuit(char* pResultado,char mensaje[],char eMensaje[],int reintentos);

/// @brief utn_getDescription It requests a description from the user, after verification it returns the result
/// @param pResultado Pointer to the memory space, where the result of the function will be stored
/// @param len Array length
/// @param mensaje Message to show the user to enter the description
/// @param mensajeError Error message, in case the description entered by the user is wrong
/// @param reintentos It is the amount of retries that the user will have
/// @return It returns zero if it got the description correctly and -1 if it had an error
int utn_getDescription(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

int esCuit(char* cadena);
int utn_getAlfanumeric(char* input, char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos);
int isValidAlphanumeric(char* stringRecibido);
int getString(char* cadena, int longitud);

#endif /* UTN_H_ */
