#include<stdio.h>

void llenarArreglo(int arreglo[], int tam, int semilla){
	int i;
	for(i = 0; i<tam; ++i){
		*(arreglo + i) = i+semilla;
	}
}


int main(){
	int arreglo[5] = {1,2,3,4,5};
	
	printf("Direccion %x, Contendido %d\n", &arreglo[0],*(arreglo));
	printf("Direccion %x, Contendido %d\n", &arreglo[1],*(arreglo+1));
	printf("Direccion %x, Contendido %d\n", &arreglo[2],*(arreglo+2));
	printf("Direccion %x, Contendido %d\n", &arreglo[3],*(arreglo+3));
	printf("Direccion %x, Contendido %d\n", &arreglo[4],*(arreglo+4));
	
	
	
	return 0;
}


