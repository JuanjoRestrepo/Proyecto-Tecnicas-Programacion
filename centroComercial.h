#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{ 
	LIBRE, //0
	OCUPADO //1 
}estadoLocal;

typedef struct Local{
	char nombre[30];
	int codigoPostal;
	int piso;
	estadoLocal estado;
	int costoArriendo;
	
}Local;

// 	================================	CENTRO COMERCIAL		================================

void mostrarDatosCentroComercial(Local **mall, int pisos, int locales);

void inicializarCostoArriendo(Local **mall, int pisos, int locales);

void alquilarLocal(Local **mall, int pisos, int locales);

void mostrarCostosArriendoDescendentemente(Local **mall, int pisos, int locales, int pisoElegido);

void swap(Local **mall, int pos1, int pos2, int piso);

void ordenarPiso(Local **centroComercial, int pisos, int locales);

void modificarInformacionLocales(Local **mall, int pisos, int locales);

void modificarEstadoLocales(Local **mall, int pisos, int locales);

void crearReporteGeneral(Local **mall, int pisos, int locales);

void reporteLocalesDisponibles(Local **mall, int pisos, int locales);

void menuCentroComercial();

void guardarArchivo(Local **mall, int pisos, int locales);

void cargarONoDatosCentroComercial();

void llenarDatosCentroComercial(Local **centroComercial, int pisos, int locales);


