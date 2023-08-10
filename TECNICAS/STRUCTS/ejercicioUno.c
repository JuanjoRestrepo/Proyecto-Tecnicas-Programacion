#include<stdio.h>
#include<stdlib.h>

typedef struct Produccion{
	char nombre[30];
	int anio;
	char tipo[20];
};

struct Produccion llenarProduccion(){
	struct Produccion produccion;
	printf("\nNombre: ");
	fflush(stdin);
	fgets(produccion.nombre, 30, stdin);
	printf("Anio: ");
	scanf("%d", &produccion.anio);
	printf("Tipo: ");
	fflush(stdin);
	fgets(produccion.tipo, 20, stdin);
	
	return produccion;
}

void llenarStruct(struct Produccion producciones[], int tam){
	int i;
	
	for(i = 0; i<tam; i++){
		printf("\nNombre: ");
		fflush(stdin);
		fgets(producciones[i].nombre, 30, stdin);
		printf("Anio: ");
		scanf("%d", &producciones[i].anio);
		printf("Tipo: ");
		fflush(stdin);
		fgets(producciones[i].tipo, 20, stdin);
	}	
}

void mostrarStructCompleto(struct Produccion producciones[], int tam){
	int i;
	for(i = 0; i<tam; i++){
		printf("\nNombre: %s", producciones[i].nombre);
		printf("Anio: %d\n", producciones[i].anio);
		printf("Tipo: %s", producciones[i].tipo);
	}
}

void mostrarStruct(struct Produccion producciones[], int tam){
	int i;
	for(i = 0; i<tam; i++){
		if(producciones[i].anio > 2010 && producciones[i].anio < 2015){
			printf("\nNombre: %s", producciones[i].nombre);
			printf("Anio: %d\n", producciones[i].anio);
			printf("Tipo: %s", producciones[i].tipo);
		}
		
	}
}


void ejecutar(){
	int tam = 2;
	struct Produccion producciones[tam];
	
	printf("*** Llenando Struct producciones ***\n");
	llenarStruct(producciones, tam);
	printf("\n*** Struct producciones Completo ***\n");
	mostrarStructCompleto(producciones, tam);
	
	system("pause");
	printf("\n*** Producciones entre 2010 y 2015 ***\n");
	mostrarStruct(producciones, tam);
	
	system("pause");
	printf("\nLlenando Struct produccion Uno\n");
	struct Produccion produccionUno;
	produccionUno = llenarProduccion();
	
	printf("\nNombre: %s", produccionUno.nombre);
	printf("Anio: %d\n", produccionUno.anio);
	printf("Tipo: %s\n", produccionUno.tipo);
	
	
	
}

int main(){
	ejecutar();
	return 0;
}
