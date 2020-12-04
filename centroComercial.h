#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{ 
	LIBRE, //0
	OCUPADO //1 
}estadoLocal, estadoParqueadero;

typedef struct Local{
	char nombre[30];
	int codigoPostal;
	int piso;
	estadoLocal estado;
	int costoArriendo;
	
}Local;

typedef struct parking{
	int IDParqueadero;
	char tipoVehiculo[10];
	estadoParqueadero estado;
	
}Parqueadero;

void menuGeneral();

//				MALL

void mostrarDatosCentroComercial(Local **mall, int pisos, int locales);

void inicializarCostoArriendo(Local **mall, int pisos, int locales);

void alquilarLocal(Local **mall, int pisos, int locales);

void mostrarCostosArriendoDescendentemente(Local **mall, int pisos, int locales, int pisoElegido);

void ordenarPiso(Local **centroComercial, int pisos, int locales);

void modificarInformacionLocales(Local **mall, int pisos, int locales);

void modificarEstadoLocales(Local **mall, int pisos, int locales);

void guardarArchivo(Local **mall, int pisos, int locales);

void cargarArchivo(Local **mall, int pisos, int locales);

void menuCentroComercial();

void crearCentroComercial();


// PARQUEADERO

void mostrarEstados(Parqueadero *parqueadero, int cantParqueaderos);

void ingresarVehiculo(Parqueadero *parqueadero, int cantParqueaderos);

void advertirPorcentajeCapacidad(Parqueadero *parqueadero, int cantParqueaderos, int porcentajeOcupacion);

int porcentajeOcupacion(Parqueadero *parqueadero, int cantParqueaderos);

void menuParqueadero(Parqueadero *parqueadero, int cantParqueaderos);

void crearParqueadero();

printf("\njaja\n");
