/*
 ============================================================================

 Nombre: Trabajo Practico 1 - Agencia de Viajes
 Autor: Matias Polzella
 Comision: 1H

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "costos.h"

int main()
{
	setbuf(stdout,NULL);

    int opcion;
    int respuesta; //aca guardo lo que utn_getNumeroEntero() me va a retornar
    int respuestaKM;
    float kilometrosIngresados;


    //vamos a hacer esto de manera repetitiva, hasta tanto y en cuanto el usuario ingrese la opcion de salida que es la 6
    do{
        respuesta = utn_getNumeroEntero(&opcion,"\n*************** MENU PRINCIPAL ***************\n "
        										"\n\n1. Ingresar Kilometros: "
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
        										"\n       Latam: "
        										"\n       a) Precio con Tarjeta de Debito: "
        										"\n       b) Precio con Tarjeta de Credito: "
        										"\n       c) Precio pagando con Bitcoin: "
        										"\n       d) Precio unitario: "
        										"\n       Aerolineas: "
        										"\n       a) Precio con Tarjeta de Debito: "
        		        						"\n       b) Precio con Tarjeta de Credito: "
        		        						"\n       c) Precio pagando con Bitcoin: "
        		        						"\n       d) Precio unitario: "
        										"\n       La diferencia de precio es: "
        										"\n\n5. Carga forzada de datos"
        										"\n\n6. Salir\n"
        										"\nPor favor, ingrese que accion desea realizar: ", "No es una opcion valida\n",1,6,3);

    if(respuesta == 0) //si estoy en este caso, quiere decir que el usuario ingres� una respuesta valida
    {
        switch(opcion)
        {
            case 1: /*INGRESAR KILOMETROS*/

            	respuestaKM = utn_getNumeroFloat(&kilometrosIngresados,"\nIngrese cantidad de kilometros\n","\nError, vuelva a ingresar los kilometros\n",1,13000,3);
            	if(respuestaKM == 0)
            	   {
            	       printf("\nUsted ha ingresado: %.3f Kilometros",kilometrosIngresados);
            	    }
            	    else
            	    {
            	    	printf("Error");
            	    }

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
