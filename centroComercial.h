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

void guardar(Local **mall, int pisos, int locales);

void menuCentroComercial();

void crearCentroComercial();


// PARQUEADERO

void crearParqueadero();

void menuParqueadero(Parqueadero *parqueadero, int cantParqueaderos);

void mostrarDatosParqueadero(Parqueadero *parqueadero, int cantParqueaderos);

void ingresarVehiculo(Parqueadero *parqueadero, int cantParqueaderos);

