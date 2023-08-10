#include<stdio.h>
#include<stdlib.h> //Usar cuando se va a asignar *pointer=NULL

int main(){
	
	int num1, *dir_num1 = NULL; /*Aputandor a una variable de tipo int*/
	int num2, *dir_num2 = NULL; /**Aputandor a una variable de tipo int*/
	
	num1 = 9;
	num2 = 10;
	
	dir_num1 = &num1;
	dir_num2 = &num2;
	
	printf("Numero1: %d\n",num1);
	printf("Direccion de memoria: %x\n", dir_num1);
	printf("Contenido dir_num1: %p (en Hexadecimal 16 digitos)\n", *dir_num1);
	
	printf("Numero2: %d\n",num2);
	printf("Direccion de memoria: %x\n", dir_num2);
	printf("Contenido dir_num2: %p (en Hexadecimal 16 digitos)\n", *dir_num2);
	
	
	return 0;
}
