#include"centroComercial.h"

// NOMBRE:  JUAN JOSE RESTREPO ROSERO
// PROYECTO FINAL DE TECNICAS Y PRACTICAS DE PROGRAMACION
// CALI, COLOMBIA. DICIEMBRE 4 DEL 2020
// PONTIFICIA UNIVERSIDAD JAVERIANA CALI
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

void swap(Local **mall, int pos1, int pos2, int piso){
	Local temp;
	
	strcpy(temp.nombre, mall[piso][pos1].nombre);
	temp.codigoPostal = mall[piso][pos1].codigoPostal;
	temp.estado = mall[piso][pos1].estado;
	temp.costoArriendo = mall[piso][pos1].costoArriendo;
	
	strcpy(mall[piso][pos1].nombre, mall[piso][pos2].nombre);
	mall[piso][pos1].codigoPostal = mall[piso][pos2].codigoPostal;
	mall[piso][pos1].estado = mall[piso][pos2].estado;
	mall[piso][pos1].costoArriendo = mall[piso][pos2].costoArriendo;
	
	strcpy(mall[piso][pos2].nombre, temp.nombre);
	mall[piso][pos2].codigoPostal = temp.codigoPostal;
	mall[piso][pos2].estado = temp.estado;
	mall[piso][pos2].costoArriendo = temp.costoArriendo;
	
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
	
	/*int posMinima;
	
	//Algortimo Ordenamiento por Seleccion
	for(i = 0; i < pisos; i++){
		posMinima = i;
		for(j = i+1; j < locales; j++){
			if(mall[elegirPiso][j].costoArriendo > mall[elegirPiso][posMinima].costoArriendo ){
				posMinima = j;
			}
			if( i != posMinima){
				swap(mall, i, posMinima, elegirPiso);
			}
		}
	}
	mostrarDatosCentroComercial(mall, elegirPiso+1, locales);*/
	
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
	
	system("cls");
	printf("\nOrdenamiento Exitoso\n");
	mostrarDatosCentroComercial(mall, elegirPiso+1, locales);
	
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
			//CONDICION PARA MODIFICAR EL NOMBRE: DEBE ESTAR OCUPADO (ESTADO = 1)
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
		printf("4. Crear Reporte Locales Disponibles\n");
		printf("5. Crear Reporte General\n");
		printf("6. Modificar Nombre Locales\n");
		printf("7. Desocupar Local\n");
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
				
			case 4://Crear Reporte Locales Disponibles txt
				
				reporteLocalesDisponibles(mall, pisos, locales);
				system("pause");
				break;
				
			case 5://Crear Reporte txt General
				
				crearReporteGeneral(mall, pisos, locales);
				system("pause");
				break;
			
			case 6://Cambiar Nombre Locales
				system("cls");
				modificarInformacionLocales(mall, pisos, locales);
				system("pause");
				break;	
			
			case 7://Desocupar Locales
				system("cls");
				modificarEstadoLocales(mall, pisos, locales);
				system("pause");
				break;
				
			default:
				printf("\nOpcion no valida. Intente de nuevo\n");
				system("pause");
		}
		
	}while(opcion != 0);
	printf("\n");
	guardarArchivo(mall, pisos, locales);
	
	system("pause");
	printf("\nCentro comercial Liberado\n");
	system("pause");
	free(mall);
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

void cargarONoDatosCentroComercial(){
	FILE *archivo;
	Local **centroComercial;
	
	int opcion, i,j;
	int pisos, locales;
	
	
	system("cls");
	printf("Desea crear un nuevo centro comercial o cargar uno ya existente?\n");
	printf("1. Crear nuevo centro comercial\n2. Cargar centro comercial\n");
	scanf("%d",&opcion);	
	
	printf("\nUsted eligio la opcion #%d\n", opcion);
	system("pause");
	if(opcion == 1){
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
		
		
		llenarDatosCentroComercial(centroComercial, pisos, locales);
	}
	else if(opcion == 2){
		//CARGAR LOS ARCHIVOS EXISTENTES
		archivo = fopen( "datosCentroComercial.dat" , "rb");
        fread(&pisos, sizeof(int), 1, archivo);
        fread(&locales, sizeof(int), 1, archivo);
        
        centroComercial = malloc( pisos * sizeof(Local ) );
        
		for(i = 0; i < pisos; i++){
			centroComercial[i] = malloc( locales * sizeof(Local ) );
			for(j = 0; j < pisos; j++){
				fread( &centroComercial[i][j], sizeof(Local), 1, archivo);
			}
		}
		/*
		for(i = 0; i < pisos; i++){
			for(j = 0; j < pisos; j++){
				fread( &centroComercial[i][j], sizeof(Local), 1, archivo);
			}
		}*/
		
        fclose( archivo );
        printf("\nSe cargaron %d registros con exito!\n", locales*pisos);
	    printf("Pisos: %d\nLocales: %d\n", pisos, locales);
	    
	    system("pause");
	    menuCentroComercial(centroComercial, pisos, locales);
	}
	
	
}

void llenarDatosCentroComercial(Local **centroComercial, int pisos, int locales){
	 //Columnas
	int i,j;
	int codigosPostales = 0;

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
