#include"parqueadero.h"

// 	================================	PARQUEADERO 	================================

void mostrarEstadosParqueadero(Parqueadero *parqueadero, int cantParqueaderos){
	int i;
	fflush(stdin);
	if(parqueadero != NULL){
		printf("ESTADOS\nLIBRE = 0  OCUPADO = 1\nPares: CARROS   IMPARES: MOTOS");
		for(i = 0; i < cantParqueaderos; i++){
			printf("\n\nID: %d", parqueadero[i].IDParqueadero);
			printf("\nTipo de vehiculo: %s", parqueadero[i].tipoVehiculo);
			printf("\nEstado: %d", parqueadero[i].estado);
			
		}
		printf("\n");
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}
}

void ingresarVehiculo(Parqueadero *parqueadero, int cantParqueaderos){
	int elegirParqueo, i, lugarDisponible, porcentajeOcupados;
	int tipo = 0;	
	
	fflush(stdin);
	do{
		printf("\nQue clase de vehiculo tiene?\n");
		printf("CARRO = 1,	MOTO = 2");
		printf("\nTipo de vehiculo: ");
		scanf("%d", &tipo);
		
		if(tipo != 1 && tipo != 2){
			printf("\nLo sentimos, solo puede ingresar esos dos tipos de vehiculos\n");
			system("pause");
			system("cls");
		}
		
	}while(tipo != 1 && tipo != 2);
	
	fflush(stdin);
	do{
			
		printf("\nTotal de parqueaderos: %d", cantParqueaderos);
		printf("\nCarros ->Pares		Motos ->Impares\n");
		printf("\nLos parqueadero inician desde el numero 0");
		printf("\n\nParqueadero en el que desea ubicarse: ");
		scanf("%d", &elegirParqueo);
		
		if(elegirParqueo >= cantParqueaderos || elegirParqueo < 0){
			printf("\nNumero de parqueadero no valido. Intente nuevamente\n");
			system("pause");
			system("cls");
		}
		
	}while(elegirParqueo >= cantParqueaderos || elegirParqueo < 0);
	
	lugarDisponible = 0;
	
	for(i = 0; i < cantParqueaderos; i++){
		fflush(stdin);
		
		//Analiza si es carro y si la posicion de parqueo es par
		if(tipo == 1 && elegirParqueo % 2 == 0 ){
			if(parqueadero[i].estado == Libre && parqueadero[i].IDParqueadero == elegirParqueo ){
				lugarDisponible = 1;
				parqueadero[i].estado = Ocupado;
				
				printf("\nCarro ubicado exitosamente\n");
				printf("Se ubica en el lugar #%d\n",parqueadero[i].IDParqueadero);
				
				break;
			}
			//Si esa ubicacion ya esta ocupada
			else if(parqueadero[i].estado == Ocupado && parqueadero[i].IDParqueadero == elegirParqueo){
				printf("\nParqueadero Ocupado\n");
			}
			
		}
		//Analiza si es carro y si la posicion de parqueo no es par
		else if(tipo == 1 && elegirParqueo % 2 != 0 ){
			printf("\nLa ubicacion digitada es para Motos\n");
			break;
		}
		//Analiza si es moto y si la posicion de parqueo es impar
		else if(tipo == 2 && elegirParqueo % 2 != 0 ){
			if(parqueadero[i].estado == Libre && parqueadero[i].IDParqueadero == elegirParqueo){
				lugarDisponible = 1;
				parqueadero[i].estado = Ocupado;
				
				printf("\nMoto ubicada exitosamente\n");
				printf("Se ubica en el lugar #%d\n",parqueadero[i].IDParqueadero);
				
				break;
			}
			//Si esa ubicacion ya esta ocupada
			else if(parqueadero[i].estado == Ocupado && parqueadero[i].IDParqueadero == elegirParqueo){
				printf("\nParqueadero Ocupado\n");
			}
			
		}
		//Analiza si es moto y si la posicion de parqueo es par
		else if(tipo == 2 && elegirParqueo % 2 == 0 ){
			printf("\nLa ubicacion digitada es para Carros\n");
			break;
		}
		
	}
	
	if(lugarDisponible == 0){
		printf("No se pudo ubicar su vehiculo\n");		
	}
	
	porcentajeOcupados = porcentajeOcupacion(parqueadero, cantParqueaderos);
	
	printf("\nPorcentaje de Ocupacion: %d%c\n", porcentajeOcupados, 37);
	
	advertirPorcentajeCapacidad(parqueadero,cantParqueaderos, porcentajeOcupados);
}

void advertirPorcentajeCapacidad(Parqueadero *parqueadero, int cantParqueaderos, int porcentajeOcupacion){
	if(porcentajeOcupacion >= 80){
		printf("ADVERTENCIA. El limite de ocupacion esta por encima del 80%c\n", 37);
		system("pause");
		parqueadero = realloc(parqueadero, sizeof(Parqueadero) * cantParqueaderos+1 );
	}
}

int porcentajeOcupacion(Parqueadero *parqueadero, int cantParqueaderos){
	int i, lugaresOcupados = 0, porcentaje = 0;
	fflush(stdin);
	if(parqueadero != NULL){
		for(i = 0; i < cantParqueaderos; i++){
			if(parqueadero[i].estado == 1){
				lugaresOcupados++;
			}
		}
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}
	porcentaje = (lugaresOcupados* 100)/cantParqueaderos;
	return porcentaje;
}

void menuParqueadero(Parqueadero *parqueadero, int cantParqueaderos){
	int opcion;

	do{
		system("cls");
		printf("1. Ingresar Vehiculo\n");
		printf("2. Mostrar Estados de los Parqueaderos\n");

		printf("0. Salir\n");
		printf("Que quieres: ");
		scanf("%d", &opcion);
		fflush(stdin);
		switch(opcion){
			case 0:
				break;
			
			case 1:
				system("cls");
				ingresarVehiculo(parqueadero, cantParqueaderos);
				system("pause");
				break;
				
			case 2:
				system("cls");
				mostrarEstadosParqueadero(parqueadero, cantParqueaderos);
				system("pause");
				break;
					
			default:
				printf("\nOpcion no valida. Intente de nuevo\n");
				system("pause");
		}
		
				
	}while(opcion != 0);
	
	printf("\nParqueadero Liberado\n");
	system("pause");
	free(parqueadero);
}

void crearParqueadero(){
	int cantParqueaderos, i;
	
	do{
		system("cls");
		printf("\n*** Crear Parqueadero ***\n");
		printf("Numeros de parqueaderos: ");
		scanf("%d", &cantParqueaderos);
		
		if( cantParqueaderos <= 0 ){
			printf("Las cantidades deben ser positivas\nIntente nuevamente\n\n");
			system("pause");
		}
		
	}while(cantParqueaderos <= 0);
	
	Parqueadero *parqueadero;
	parqueadero = malloc( cantParqueaderos * sizeof(Parqueadero) );
	
	char carro[]= "CARRO";
	char moto[]= "MOTO";
	if(parqueadero != NULL){
		for(i = 0; i < cantParqueaderos; i++){
			parqueadero[i].IDParqueadero = i;
			if(parqueadero[i].IDParqueadero % 2 == 0){
				strcpy(parqueadero[i].tipoVehiculo, carro);
			}
			else{
				strcpy(parqueadero[i].tipoVehiculo, moto);
			}
			
			parqueadero[i].estado = Libre;
		}
	}
	
	printf("\nSe ha creado un parqueadero\n");
	system("pause");
	
	menuParqueadero(parqueadero, cantParqueaderos);
}

void aumentarCapacidadParqueadero(Parqueadero *parqueadero, int cantParqueaderos){
	
}
