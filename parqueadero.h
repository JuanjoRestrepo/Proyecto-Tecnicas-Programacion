#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{ 
	Libre, //0
	Ocupado //1 
}estadoParqueadero;

typedef struct parking{
	int IDParqueadero;
	char tipoVehiculo[10];
	estadoParqueadero estado;
	
}Parqueadero;

// PARQUEADERO

void mostrarEstadosParqueadero(Parqueadero *parqueadero, int cantParqueaderos);

void ingresarVehiculo(Parqueadero *parqueadero, int cantParqueaderos);

void advertirPorcentajeCapacidad(Parqueadero *parqueadero, int cantParqueaderos, int porcentajeOcupacion);

void adicionarEspacios(Parqueadero *parqueadero, int *cantParqueaderos);

int porcentajeOcupacion(Parqueadero *parqueadero, int cantParqueaderos);

void menuParqueadero(Parqueadero *parqueadero, int cantParqueaderos);

void crearParqueadero();
