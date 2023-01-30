#include"centroComercial.h"
#include"parqueadero.h"

// NOMBRE:  JUAN JOSE RESTREPO ROSERO
// PROYECTO FINAL DE TECNICAS Y PRACTICAS DE PROGRAMACION
// CALI, COLOMBIA. DICIEMBRE 4 DEL 2020
// PONTIFICIA UNIVERSIDAD JAVERIANA CALI

void menuGeneral(){
	int opcion;
	
	do{
		system("cls");
		printf("1. Parqueadero\n");
		printf("2. Centro Comercial\n");
		printf("0. Terminar Programa\n");
		printf("Que quieres: ");
		scanf("%d", &opcion);
		fflush(stdin);
		switch(opcion){
			
			case 0:
				break;
				
			case 1:
				
				crearParqueadero();
				break;
				
			case 2:
				
				cargarONoDatosCentroComercial();
				//crearCentroComercial();
				break;
				
			default:
				printf("\nOpcion no valida. Intente de nuevo\n");
				system("pause");
		}
		
	}while(opcion != 0);
}

int main(){

	menuGeneral();

	printf("\nMemoria Liberada\n");
	
	return 0;	
}
