

#ifndef CALCULOS_H_
#define CALCULOS_H_


/**
 * @fn int calculoPrecio(float, int, float*, float)
 * @brief Funcion que realiza los c�lculos para los viajes
 *
 * @pre
 * @post
 * @param costo Es el precio del vuelo a calcular los descuentos
 * @param formaPago Se recibe 0 pago con D�bito, 1 con cr�dito y 2 con BTC
 * @param precio puntero que recibe el precio con los descuentos o recargos segun la forma de pago
 * @param cotizacionBtc Valor del BTC para poder realizar el c�lculo
 * @return Devuleve 0 si pudo realizar el c�lculo y -1 en caso de error
 */
int calculoPrecio(float costo,int formaPago, float * precio, float cotBtc);


int reportOfResults(int distancia,float precio1, float precio2, float debito1, float credito1, float btc1, float unitario1, float debito2, float credito2, float btc2, float unitario2);


#endif /* CALCULOS_H_ */
