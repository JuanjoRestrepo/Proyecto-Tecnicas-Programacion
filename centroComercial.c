#include"centroComercial.h"

// 	================================	CENTRO COMERCIAL		================================

void mostrarDatosCentroComercial(Local **mall, int pisos, int locales){
	int i, j;
	fflush(stdin);
	if(mall != NULL){
		printf("ESTADOS\nLIBRE = 0  OCUPADO = 1\n");
		for(i = 0; i < pisos; i++){
			printf("________________________\nPiso: %d", i);
			for(j = 0; j < locales; j++){
				printf("\n\nNombre del local: %s", mall[i][j].nombre);
				printf("\nCodigo Postal: %d", mall[i][j].codigoPostal);
				printf("\nEstado: %d", mall[i][j].estado);
				printf("\nCosto de arriendo $: %d", mall[i][j].costoArriendo);
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}
}

void inicializarCostoArriendo(Local **mall, int pisos, int locales){
	int i,j;
	
	if(mall != NULL){
		for(i = 0; i < pisos; i++){
			printf("________________________\nPiso: %d", i);
			for(j = 0; j < locales; j++){
				printf("\nDigite el costo de arriendo del local #%d $: ", j+1);
				fflush(stdin);
				scanf("%d", &mall[i][j].costoArriendo);
			}
		}
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}
	
	printf("\nCostos inicializados con exito!\n");
	system("pause");
}

void alquilarLocal(Local **mall, int pisos, int locales){
	int pisoAlquilar, j, localDisponible, pagoDisponible;
	
	int elegirLocal;
	
	do{	
		system("cls");
		printf("Total de pisos del Mall: %d", pisos);
		printf("\nLos pisos inician desde el numero 0");
		printf("\n\nPiso en el que desea alquilar el local: ");
		scanf("%d", &pisoAlquilar);
		
		if(pisoAlquilar >= pisos || pisoAlquilar < 0){
			printf("\nNumero de piso no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(pisoAlquilar >= pisos || pisoAlquilar < 0);
	
	fflush(stdin);
	int capacidadPago = 0;
	
	do{
		//system("cls");
		printf("\nDigite su capacidad de pago: ");
		scanf("%d", &capacidadPago);
		
		if(capacidadPago <= 0){
			printf("\nLa capacidad de pago debe ser positiva\n");
			system("pause");
		}
		
	}while(capacidadPago <= 0);

	
	//Variables de control
	localDisponible = 0;
	pagoDisponible = 0;
	
	printf("\nDigite el codigo postal del local que desea alquilar: ");
	scanf("%d", &elegirLocal);
	fflush(stdin);
	
	for(j = 0; j < locales; j++){
		if(mall[pisoAlquilar][j].estado == LIBRE && mall[pisoAlquilar][j].codigoPostal == elegirLocal){
			localDisponible = 1;
			if(mall[pisoAlquilar][j].costoArriendo <= capacidadPago){
				
				printf("\nNombre nuevo del local [MAX 30]: ");
				fflush(stdin);
				fgets(mall[pisoAlquilar][j].nombre, 30, stdin);
				fflush(stdin);
				printf("\nEl codigo postal del local es: %d", mall[pisoAlquilar][j].codigoPostal);
				printf("\nSu local se ubica en el piso #%d \n", mall[pisoAlquilar][j].piso );
				mall[pisoAlquilar][j].estado = OCUPADO;
				
				//Se ocupa el local
				pagoDisponible = 1;
				fflush(stdin);
				break;
			}
			else if(pagoDisponible == 0){
				printf("\nLo sentimos, su capacidad de pago (%d) no es suficiente para alquilar el local %d en el piso %d\n", capacidadPago, elegirLocal, pisoAlquilar);
			}
				
		}
		
	}
	if(localDisponible == 0){
		printf("\nLo sentimos, ese local ya esta ocupado o no hay disponibilidad en ese piso (%d)\n", pisoAlquilar);
	}
}

void mostrarCostosArriendoDescendentemente(Local **mall, int pisos, int locales, int pisoElegido){
	int j;
	printf("\nSe han ordenado los locales por costo de arriendo de forma descendente\n");
	printf("________________________\nPiso: %d\n", pisoElegido);
	for(j = 0; j < locales; j++){
		printf("\nCosto de arriendo local %d: %d\n", mall[pisoElegido][j].codigoPostal, mall[pisoElegido][j].costoArriendo);
		
	}
}

void ordenarPiso(Local **mall, int pisos, int locales){
	int elegirPiso, i, j, pos;
	
	do{	
		system("cls");
		printf("Total de pisos del Mall: %d", pisos);
		printf("\nLos pisos inician desde el numero 0\n");
		printf("\nQue piso quiere ordenar: ");
		scanf("%d", &elegirPiso);
		
		if(elegirPiso >= pisos || elegirPiso < 0){
			printf("\nNumero de piso no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(elegirPiso >= pisos || elegirPiso < 0);
	
	fflush(stdin);
	int temp;
	
	//Algortimo Ordenamiento por Insercion
	
	for(j = 0; j < locales; j++){
		
		temp = mall[elegirPiso][j].costoArriendo;
		pos = j;
		while(pos > 0 && mall[elegirPiso][j-1].costoArriendo < temp){
			mall[elegirPiso][pos].costoArriendo = mall[elegirPiso][pos-1].costoArriendo;
			pos--;
		}
		mall[elegirPiso][pos].costoArriendo = temp;
	}
	
	mostrarCostosArriendoDescendentemente(mall, pisos, locales, elegirPiso);
	
}

void modificarInformacionLocales(Local **mall, int pisos, int locales){
	int i, j, localesAModificar, pisoAModificar; 
	
	do{	
		system("cls");
		printf("Total de pisos del Mall: %d", pisos);
		printf("\nLos pisos inician desde el numero 0\n");
		printf("\nEn cual piso desea modificar: ");
		scanf("%d", &pisoAModificar);
		
		if(pisoAModificar >= pisos || pisoAModificar < 0){
			printf("\nNumero de piso no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(pisoAModificar >= pisos || pisoAModificar < 0);
	
	fflush(stdin);
	
	int localesOcupados = 0;
	for(j = 0; j < locales; j++){
		if(mall[pisoAModificar][j].estado == OCUPADO ){
			localesOcupados++;
		}
	}
	
	printf("\nHay %d local(es) ocupados en el piso %d\n", localesOcupados, pisoAModificar );
	system("pause");
	
	do{
		system("cls");
		printf("\nCuantos locales desea modificar en el piso %d: ", pisoAModificar);
		scanf("%d", &localesAModificar);
		
		if(localesAModificar > localesOcupados || localesAModificar < 0){
			printf("\nNumero de locales no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(localesAModificar > localesOcupados || localesAModificar < 0);
	
	int digitarCodPostal;
	
	fflush(stdin);
	
	int modificado = 0;
	for(i = 0; i < localesAModificar; i++){
		printf("\nDigite el codigo postal del local a modificar: " );
		scanf("%d", &digitarCodPostal);
		fflush(stdin);
		for(j = 0; j <= localesOcupados; j++){
		
			if(mall[pisoAModificar][j].estado == OCUPADO && mall[pisoAModificar][j].codigoPostal == digitarCodPostal){
				printf("\nNombre nuevo del local %d [MAX 30]: ", j+1);
				fflush(stdin);
				fgets(mall[pisoAModificar][j].nombre, 30, stdin);
				fflush(stdin);
				modificado = 1;
			}
			
		}
	}
	if(modificado == 1){
		printf("\nSe modifico el nombre exitosamente\n");
	}
	else if(modificado == 0){
		printf("\nNo se pudo modificar el nombre del local\n");
	}
	
	
}

void modificarEstadoLocales(Local **mall, int pisos, int locales){
	int i, j, localesAModificar, pisoAModificar; 
	
	do{	
		system("cls");
		printf("Total de pisos del Mall: %d", pisos);
		printf("\nLos pisos inician desde el numero 0\n");
		printf("\nEn cual piso desea desocupar: ");
		scanf("%d", &pisoAModificar);
		
		if(pisoAModificar >= pisos || pisoAModificar < 0){
			printf("\nNumero de piso no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(pisoAModificar >= pisos || pisoAModificar < 0);
	
	fflush(stdin);
	
	int localesOcupados = 0;
	for(j = 0; j < locales; j++){
		if(mall[pisoAModificar][j].estado == OCUPADO ){
			localesOcupados++;
		}
	}
	
	printf("\nHay %d local(es) ocupados en el piso %d\n", localesOcupados, pisoAModificar );
	system("pause");
	
	do{
		system("cls");
		printf("\nCuantos locales desea desocupar en el piso: %d: ", pisoAModificar);
		scanf("%d", &localesAModificar);
		
		if(localesAModificar > localesOcupados || localesAModificar < 0){
			printf("\nNumero de locales no valido. Intente nuevamente\n");
			system("pause");
		}
		
	}while(localesAModificar > localesOcupados || localesAModificar < 0);
	
	int digitarCodPostal;
	
	fflush(stdin);
	
	int modificado = 0;
	
	char texto[] = "UNKNOWN";
	for(i = 0; i < localesAModificar; i++){
		printf("\nDigite el codigo postal del local a modificar: " );
		scanf("%d", &digitarCodPostal);
		fflush(stdin);
		for(j = 0; j <= localesOcupados; j++){
			if(mall[pisoAModificar][j].estado == OCUPADO && mall[pisoAModificar][j].codigoPostal == digitarCodPostal){
	
				strcpy(mall[pisoAModificar][j].nombre, texto);
				mall[pisoAModificar][j].estado = LIBRE;
				modificado = 1;
				fflush(stdin);
				break;
			}
			
		}
	}
	if(modificado == 1){
		printf("\nEstados modificados exitosamente\n");
	}
	else if(modificado == 0){
		printf("\nNo se pudo modificar el estado del local\n");
	}
	
}


void guardarArchivo(Local **mall, int pisos, int locales){
	int i;
    FILE *archivo = fopen( "datosCentroComercial.dat" , "wb");
    
    if(mall != NULL){
        fwrite(&pisos, sizeof(int), 1, archivo);
        fwrite(&locales, sizeof(int), 1, archivo);
        for(i = 0; i < pisos; i++){
             fwrite( mall[i] , sizeof( Local ), locales, archivo);
        }
        fclose( archivo );
        printf("\nSe guardaron %d registros con exito!\n", locales*pisos);
    }
    else{
        printf("\nERROR - No existen datos\n");
        return;
    }
    
}

void cargarArchivo(Local **mall, int pisos, int locales){
	int i;
	FILE *archivo = fopen( "datosCentroComercial.dat" , "rb");
	
	if(mall != NULL){
        fread(&pisos, sizeof(int), 1, archivo);
        fread(&locales, sizeof(int), 1, archivo);
        for(i = 0; i < pisos; i++){
             fread( mall[i] , sizeof( Local ), locales, archivo);
        }
        fclose( archivo );
        printf("\nSe cargaron %d registros con exito!\n", locales*pisos);
    }
    else{
        printf("\nERROR - No existen datos\n");
        return;
    }
    system("pause");
	
}

void crearReporteGeneral(Local **mall, int pisos, int locales){
	int i, j;
	FILE *archivo = fopen( "ReporteGeneral.txt" , "wb");	
	if(mall != NULL){
		fprintf(archivo,"\n======== REPORTE GENERAL ========\n");
		fprintf( archivo, "==========	  		  ==========\n" );
		for(i = 0; i < pisos; i++){
			fprintf(archivo, "________________________\nPiso: %d", i);
			for(j = 0; j < locales; j++){
				fprintf(archivo, "\n\nNombre del local: %s", mall[i][j].nombre);
				fprintf(archivo, "\nCodigo Postal: %d", mall[i][j].codigoPostal);
				fprintf(archivo, "\nEstado: %d", mall[i][j].estado);
				fprintf(archivo, "\nCosto de arriendo $: %d", mall[i][j].costoArriendo);
			}
			fprintf(archivo, "\n");
		}
		fprintf(archivo, "\n");
		fclose(archivo);
		printf("\n\nReporte creado exitosamente\n");		
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}
}

void reporteLocalesDisponibles(Local **mall, int pisos, int locales){
	int i, j;
	FILE *archivo = fopen( "Reporte Locales Disponibles.txt" , "wb");
	if(mall != NULL){
		fprintf(archivo,"\n======== REPORTE LOCALES DISPONIBLES ========\n");
		fprintf( archivo, "==========	  		  ==========\n" );
		for(i = 0; i < pisos; i++){
			fprintf(archivo, "________________________\nPiso: %d", i);
			for(j = 0; j < locales; j++){
				if(mall[i][j].estado == 0){
					fprintf(archivo, "\n\nNombre del local: %s", mall[i][j].nombre);
					fprintf(archivo, "\nCodigo Postal: %d", mall[i][j].codigoPostal);
					fprintf(archivo, "\nEstado: %d", mall[i][j].estado);
					fprintf(archivo, "\nCosto de arriendo $: %d", mall[i][j].costoArriendo);
				}
			}
			fprintf(archivo, "\n");
		}
		fprintf(archivo, "\n");
		fclose(archivo);
		printf("\n\nReporte creado exitosamente\n");
	}
	else{
		printf("\nMemoria Insuficiente\n");
	}		
	
}	

void menuCentroComercial(Local **mall, int pisos, int locales){
	
	int opcion;

	do{
		system("cls");
		printf("1. Alquilar Piso\n");
		printf("2. Mostrar Locales\n");
		printf("3. Ordenar Por Costo De Arriendo\n");
		printf("4. Guardar Archivos\n");
		printf("5. Crear Reporte Locales Disponibles\n");
		printf("6. Crear Reporte General\n");
		printf("7. Cargar Archivos\n");
		printf("8. Modificar Nombre Locales\n");
		printf("9. Desocupar Local\n");
		printf("0. Salir\n");
		printf("Que quieres: ");
		scanf("%d", &opcion);
		fflush(stdin);
		switch(opcion){
			case 0:
				break;
			
			case 1:
				system("cls");
				alquilarLocal(mall, pisos, locales);
				system("pause");
				break;
			
			case 2:
				system("cls");
				mostrarDatosCentroComercial(mall, pisos, locales);
				system("pause");
				break;
			
			case 3:
				system("cls");
				ordenarPiso(mall, pisos, locales);
				system("pause");
				break;
				
			case 4:
				
				guardarArchivo(mall, pisos, locales);
				system("pause");
				break;
				
			case 5://Crear Reporte Locales Disponibles txt
				
				reporteLocalesDisponibles(mall, pisos, locales);
				system("pause");
				break;
				
			case 6://Crear Reporte txt General
				
				crearReporteGeneral(mall, pisos, locales);
				system("pause");
				break;
			
			case 7:
				system("cls");
				cargarArchivo(mall, pisos, locales);
				system("pause");
				break;
			
			case 8://Cambiar Nombre Locales
				system("cls");
				modificarInformacionLocales(mall, pisos, locales);
				system("pause");
				break;	
			
			case 9://Desocupar Locales
				system("cls");
				modificarEstadoLocales(mall, pisos, locales);
				system("pause");
				break;
				
			default:
				printf("\nOpcion no valida. Intente de nuevo\n");
				system("pause");
		}
		
	}while(opcion != 0);
	
	printf("\nCentro comercial Liberado\n");
	free(mall);
}

void crearCentroComercial(){
	int pisos; //Filas
	int locales; //Columnas
	int i,j;
	int codigosPostales = 0;

	Local **centroComercial;
	do{
		system("cls");
		printf("\n*** Crear un Centro Comercial ***\n");
		printf("Numeros de pisos: ");
		scanf("%d", &pisos);
		printf("Numeros de locales por piso: ");
		scanf("%d", &locales);
		
		if(pisos <= 0 && locales <= 0){
			printf("Las cantidades deben ser positivas\nIntente nuevamente\n\n");
			system("pause");
		}
		
	}while(pisos <= 0 && locales <= 0);
	

	centroComercial = malloc( pisos * sizeof(Local ) );
	if(centroComercial != NULL){
		for(i = 0; i< pisos; i++){
			centroComercial[i] =  malloc( locales * sizeof(Local ) );
		}	
	}
	printf("\nSe ha creado un centro comercial\n");
	system("pause");
	
	char texto[] = "UNKNOWN";
	for(i = 0; i < pisos; i++){
		for(j = 0; j < locales; j++){
			strcpy(centroComercial[i][j].nombre, texto);
			centroComercial[i][j].codigoPostal = ((i+1)*100) + codigosPostales;
			centroComercial[i][j].piso = i;
			centroComercial[i][j].estado = LIBRE;
			centroComercial[i][j].costoArriendo = 0;
			codigosPostales++;
		}
		codigosPostales = 0;
	}
	
	printf("\nInicializando costos de arriendo de cada local\n");
	inicializarCostoArriendo(centroComercial, pisos, locales);
	
	menuCentroComercial(centroComercial, pisos, locales);
	
}


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
			if(parqueadero[i].estado == LIBRE && parqueadero[i].IDParqueadero == elegirParqueo ){
				lugarDisponible = 1;
				parqueadero[i].estado = OCUPADO;
				
				printf("\nCarro ubicado exitosamente\n");
				printf("Se ubica en el lugar #%d\n",parqueadero[i].IDParqueadero);
				
				break;
			}
			//Si esa ubicacion ya esta ocupada
			else if(parqueadero[i].estado == OCUPADO && parqueadero[i].IDParqueadero == elegirParqueo){
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
			if(parqueadero[i].estado == LIBRE && parqueadero[i].IDParqueadero == elegirParqueo){
				lugarDisponible = 1;
				parqueadero[i].estado = OCUPADO;
				
				printf("\nMoto ubicada exitosamente\n");
				printf("Se ubica en el lugar #%d\n",parqueadero[i].IDParqueadero);
				
				break;
			}
			//Si esa ubicacion ya esta ocupada
			else if(parqueadero[i].estado == OCUPADO && parqueadero[i].IDParqueadero == elegirParqueo){
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
			
			parqueadero[i].estado = LIBRE;
		}
	}
	
	printf("\nSe ha creado un parqueadero\n");
	system("pause");
	
	menuParqueadero(parqueadero, cantParqueaderos);
}


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
				
				crearCentroComercial();
				break;
				
			default:
				printf("\nOpcion no valida. Intente de nuevo\n");
				system("pause");
		}
		
	}while(opcion != 0);
}

