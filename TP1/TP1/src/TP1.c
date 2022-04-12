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
#include "validaciones.h"

int main()
{
	setbuf(stdout,NULL);

    int opcion;
    int respuesta; //aca guardo lo que utn_getNumeroEntero() me va a retornar


    //la funcion devuelve un numero negativo (-1) para indicar que no pudo obtener un numero, y un cero para indicar que si lo obtuvo
    do{
        respuesta = utn_getNumeroEntero(&opcion,"\n\n1. Ingresar Kilometros: "
                          	  	        "\n\n2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)"
        					"\n     	-Precio vuelo Aerolineas: "
        					"\n     	-Precio vuelo Latam: "
                          	  	  	"\n\n3. Calcular todos los costos: "
                          	  	  	"\n      	a) Tarjeta de Debito (Descuento 10%)"
                          	  	  	"\n     	b) Tarjeta de Credito (Interes 25%)"
        					"\n      	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)"
        					"\n      	d) Mostrar precio por Km (precio unitario)"
        					"\n      	e) Mostrar diferencia de precio ingresada (Latam - Aerolineas"
        					"\n\n4. Informar resultados"
        					"\n         Latam: "
        					"\n       	a) Precio con Tarjeta de Debito: "
        					"\n             b) Precio con Tarjeta de Credito: "
        					"\n       	c) Precio pagando con Bitcoin: "
        					"\n       	d) Precio unitario: "
        					"\n       	e) La diferencia de precio es: "
        					"\n\n5. Carga forzada de datos"
        					"\n\n6. Salir\n"
        					"\nPor favor, ingrese que accion desea realizar: ", "No es una opcion valida\n",1,6,3);

    if(!respuesta) //si es cero es cuando yo tengo que entrar, al hacerlo negado se transforma en 1, que seria verdadero (otra opcion: respues == 0)
    {
        switch(opcion)
        {
            case 1: /*INGRESAR KILOMETROS*/

            printf("Entre al caso 1\n");

            break;

            case 2: /*INGRESAR PRECIO DE VUELOS*/

            printf("Entre al caso 2\n");

            break;

            case 3: /*CALCULAR COSTOS*/

            break;

            case 4: /*INFORMAR RESULTADOS*/

            break;

            case 5: /*CARGA FORZADA DE DATOS*/

            break;

            case 6: /*SALIR*/

            break;

        }
    }
    }while(opcion != 6);

    return 0;
}
