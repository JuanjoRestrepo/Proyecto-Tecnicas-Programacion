all: programa
programa: centroComercial Main
	gcc -o ejecutable main.c centroComercial.o
Main: main.c
	gcc -c main.c
centroComercial: centroComercial.c
	gcc -c centroComercial.c
	
	


