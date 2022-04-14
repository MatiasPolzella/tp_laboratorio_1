#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "submenu.h"


void ingresoPrecios(float *precioAerolineas, float *precioLatam)
{
	float precioAerolineasLocal;
	float precioLatamLocal;
	int estadoInput;

	estadoInput = utn_getNumeroFloat(&precioAerolineasLocal,"\nIngrese precio de vuelo de aerolineas: \n","\nError, vuelva a ingresar el precio\n", 1500, 150000,2);
	if (estadoInput == EXITO)
	{
		printf("\nUsted ha ingresado $ %.2f",precioAerolineasLocal);
	}
	else
	{
		printf("Error");
		return;
	}

	estadoInput = utn_getNumeroFloat(&precioLatamLocal,"\nIngrese precio de vuelo de Latam:  \n","\nError, vuelva a ingresar el precio\n", 1500, 150000,2);
	if (estadoInput == EXITO)
	{
		printf("\nUsted ha ingresado $ %.2f",precioLatamLocal);
	}
	else
	{
		printf("Error");
		return;
	}

	*precioAerolineas = precioAerolineasLocal;
	*precioLatam = precioLatamLocal;
}

void ingresoKilometros(float *kilometrosIngresados)
{
	float KMIngresadoLocal;

	int estadoInput = utn_getNumeroFloat(&KMIngresadoLocal,"\nIngrese cantidad de kilometros: \n","\nError, vuelva a ingresar los kilometros\n", 1, 13000,2);
	if (estadoInput == EXITO)
	{
		printf("\nUsted ha ingresado: %.2f Kilometros",KMIngresadoLocal);
	}
	else
	{
		printf("Error");
	}
	*kilometrosIngresados = KMIngresadoLocal;


}



