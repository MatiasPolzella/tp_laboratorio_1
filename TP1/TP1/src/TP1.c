/*
 ============================================================================
 Name        : Trabajo Practico 1 - Agencia de Viajes
 Author      : Matias Polzella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int opcion;




	do{
		printf("\n\n            BIENVENIDOS     \n\n");
		printf("\n     Por favor, ingrese una de las siguientes opciones: ");
		printf("\n\n1. Ingresar Kilometros: ");
		printf("\n\n2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)");
		printf("\n     		-Precio vuelo Aerolineas: ");
		printf("\n     		-Precio vuelo Latam: ");
		printf("\n\n3. Calcular todos los costos: ");
		printf("\n      	a) Tarjeta de Debito (Descuento 10%)");
		printf("\n     		b) Tarjeta de Credito (Interes 25%)");
		printf("\n      	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		printf("\n      	d) Mostrar precio por Km (precio unitario)");
		printf("\n      	e) Mostrar diferencia de precio ingresada (Latam - Aerolineas");
		printf("\n\n4. Informar resultados");
		printf("\n         	 Latam: ");
		printf("\n          a) Precio con Tarjeta de Debito: ");
		printf("\n          b) Precio con Tarjeta de Credito: ");
		printf("\n          c) Precio pagando con Bitcoin: ");
		printf("\n          d) Precio unitario: ");
		printf("\n          e) La diferencia de precio es: ");
		printf("\n\n5. Carga forzada de datos");
		printf("\n\n6. Salir\n\n");
		scanf("%d",&opcion);


		switch(opcion)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			break;

		case 6:

			break;



		}








	}
	while(opcion != 6);







	return 0;
}
