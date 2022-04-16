

#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @fn  getPrice
/// @brief Realizar� los calculos necesarios para obtener el valor del viaje en: debito, credito y Bitcoin
/// @param cost Precio del vuelo para calcular los descuentos
/// @param payment Recibe 0 pago con D�bito, 1 para cr�dito y 2 con BTC
/// @param price Puntero que recibe el precio con los descuentos (o recargos) segun la forma de pago
/// @param BTCPrice Es el valor del Bitcoin para poder realizar el calculo
/// @return En caso de exito (0), en caso de error (-1)
int getPrice(float cost, int payment, float *price, float BTCPrice);

/// @fn int reportOfResults(int, float, float, float, float, float, float, float, float, float, float)
/// @brief Nos muestra el informe de resultados con los precios ya cargados
/// @param distance
/// @param priceAA
/// @param debitAA
/// @param creditAA
/// @param BTCAA
/// @param priceUnitAA
/// @param priceLatam
/// @param debitLatam
/// @param creditLatam
/// @param BTCLatam
/// @param priceUnitLatam
/// @return el informe con los resultados
int reportOfResults(int distance, float priceAA, float debitAA, float creditAA, float BTCAA, float priceUnitAA, float priceLatam,float debitLatam,float creditLatam,float BTCLatam, float priceUnitLatam);

/// @fn getPriceDifference
/// @brief Esta funcion nos permitir� calcular la diferencia de precios entre Aerolineas Argentinas y Latam
/// @param operator1
/// @param operator2
/// @return La direrencia de precios mediante una resta
float getPriceDifference(float operator1, float operator2);


#endif /* CALCULOS_H_ */
