#include<stdio.h>
#define CAP 100
#include<windows.h>
#include<stdlib.h>

typedef struct cliente{
   char nombre[10];
   int saldo;
   float deuda;
}cliente;

void menu(){
   printf("\n === BIENVENIDO A REY PALOMO's BANK INC. ===\n");
   printf("\n ==== MAIN MENU ====\n");
   printf("1. Agregar\n");
   printf("2. Buscar\n");
   printf("3. Modificar\n");
   printf("4. Eliminar\n");
   printf("5. Listar\n");
   printf("6. Consignar\n");
   printf("7. Retirar\n");
   printf("8. Totalizar\n");
   printf("9. Reporte\n");
   printf("10. Solicitar Prestamo\n");
   printf("11. Cambiar Nombre de Usuario\n");
   printf("12. Generador de Tarjeta\n");
   printf("0. Salir\n");
   printf("Para La Sorpresa resuelva: 1101 + 1 = \n");
   printf("\nQue quieres hacer: ");
   return;
}




int main(){
   cliente banco[CAP];
   
   FILE *f, *filesito, *save;
   char name[15];
   int opcion, cont = 0, i,j, digitos, consigna, retiro, monto = 100000, suma = 0;
   float prestamo, subtotal, ValorTotal, DeudaPagar;
   
   save = fopen( "BancoMilitar.dat", "rb" );
   fread( &cont, sizeof( int ), 1, save );
   fread( banco, sizeof( banco ), 1, save );
   fclose( save );
   printf( "*** se cargaron %d registros con exito\n", cont );
   system("pause");
   
   do{
   	  system("cls");
      menu();scanf( "%d", &opcion);
      switch(opcion){

         case 1: printf("\nAgregando al new user\n");
		 printf("Nombre: "); scanf("%s",banco[cont].nombre);
		 printf("Saldo: ");scanf("%d",&banco[cont++].saldo);
		 //printf("(Creditos a Fabian)\nVolver al menu? Si = 1/No = 0: "); scanf("%d",opcion);
  		 break;
  		 
	 case 2: printf("\n====Buscar a un user====\n");
		 printf("Nombre a Buscar: "); scanf("%s",name);
		 for(i=0; i < cont; i++){
		    if(strcmp(name,banco[i].nombre)== 0){
		       printf("\nEl saldo de %s es %d\n", name, banco[i].saldo);
		       
		    }
		    else{
		    	printf("El usuario %s no existe\n", name); 
		 		Beep(1000,1000);
		 		break;
		 		
			}
		 }  
		 
		 break;
		 
		 
	 case 3: printf("\nModificar el saldo de un user\n");
		 printf("Nombre: ");scanf("%s",name );
		 for(i = 0; i < cont; i++){
		    if(strcmp(name,banco[i].nombre)== 0){
		       printf("Saldo Nuevo[%d]:",banco[i].saldo); 
		       scanf("%d", &banco[i].saldo);
		       printf("\nNuevo Saldo de %s es %d", name, banco[i].saldo);
		       i++;//cambio aqui 10:07
		    }
		 }
		 if(i==cont){
		 	printf("El usuario %s no existe", name);
		 	Beep(1000,1000);
		 	printf("\nCreditos a Fabian Moreno XD\n");
		 }
		 break;
		 
	 case 4: printf("\nEliminar a un user\n");
		 printf("A quien vamos a eliminar: "); scanf("%s",name);
         int ok = 0;
		 for(i = 0; i < cont; i++){
		    if(strcmp(name,banco[i].nombre)== 0){
		        for (j = i; j < cont - 1; j++){
		          banco[j] = banco[j + 1]; 
		       }
                       cont--;
                       ok = 1;
                       break;
		    }
		 }
		 if( !ok ){
		    printf("PELIGRO!!! El usuario %s no existe!!!\n",name);  
		    Beep(1000,1000);
		 }
		 break; 
	 case 5:
	 	  	system("cls"); 
	        printf("\nLista de Usuarios en la Data Base\n");
	 		printf("      Nombre    Saldo\n");
			for( i = 0; i < cont; i++){
				printf("%10s  %8d\n", banco[i].nombre, banco[i].saldo );
			}
			system("pause");
			break;
			
	 case 6: printf("\n === VAMO A MANDAR PLATICA ===\n");
	 		 printf("Consignar a: "); scanf("%s",name);
	 		 for(i = 0; i < cont; i++){
		        if(strcmp(name,banco[i].nombre)== 0){
		        	printf("Cuanto le va a consignar a %s? ", name); scanf("%d",&consigna);
		        	banco[i].saldo += consigna; 
		        	printf("\nConsignacion exitosa!");
		        	break;
				}
			 }
			 if(i==cont){
		 	 printf("El usuario %s no esta registrado. La consignacion fue fallida.\n", name);
		 	 Beep(1000,1000);
		 	 
		 }
		 break;
		 
	 case 7: printf("\n === VAMO A RETIRAR PLATICA ===\n");
	 		 printf("Usuario: "); scanf("%s",name);
	 		 for(i = 0; i < cont; i++){
		        if(strcmp(name,banco[i].nombre)== 0){
		        	printf("Cuanto quiere retirar %s: ", name); scanf("%d",&retiro);
		        	while(retiro > banco[i].saldo){
		        		printf("Su saldo actual es inferior a lo que quiere retirar. Intentelo otra vez\n");
		        		printf("Cuanto quiere retirar %s: ", name); scanf("%d",&retiro);
					}
		        	
						banco[i].saldo -= retiro; 
		        		printf("\nSu Retiro Fue Exitoso!");
		        	
		        	break;
				}
			 }
			 if(i==cont){
		 	 printf("El usuario %s no esta registrado. El retiro fue fallido.\n", name);
		 	 Beep(1000,1000);
		 	 
		 }
		 break;
		 
	 case 8: printf("\n=== Total de toda la platica de los usuarios ===\n");	
	 		 for(i = 0; i < cont; i++){
	 		 	suma += banco[i].saldo;
	 		 	
			  }
			  printf("El monto total de los usuarios de REY PALOMO'S BANK es $%d dolares\n", suma);
			  break;
	 
	 case 9: printf("\n=== REPORTE ===\n");
	 		 f = fopen( "ReporteMilitar.txt", "w" );
	 		 fprintf(f,"\n  === REPORTE ===\n");
	 		 fprintf( f, "\nNombre       Saldo\n" );
                 fprintf( f, "========== ========\n" );
                 for( i = 0; i < cont; i++ ){
                    fprintf( f, "%-10s %8d\n", banco[ i ].nombre, 
                       banco[ i ].saldo );
                 }
                 fclose( f );
                 system( "notepad ReporteMilitar.txt" );
                 break;
                 
     case 10: printf("\nSOLICITAR UN PRESTAMO\n");
     		  printf("HACEMOS PRESTAMOS CON UNA TASA DE INTERES DEL:\n Inferior a 1000   5%%\n 10000 - 20000    10%%\n 20000 - 30000    15%%\n 30000 - superior 20%%\n");
     		  printf("\nNombre Usuario: "); scanf("%s", name);
			  for(i = 0; i < cont; i++){
		        if(strcmp(name,banco[i].nombre)== 0){
				  printf("Cuanto quiere que le prestemos %s: ",name); scanf("%f",&prestamo);
				  
				  while(prestamo >= monto){
				    Beep(1000,1000);	
				  	printf("\nNo podemos prestarle un valor superior o igual a nuestro monto\n");
				  	printf("\nCuanto quiere que le prestemos %s: ",name); scanf("%f",&prestamo);	
				  }
				  if(prestamo <= 10000){
				  	subtotal = prestamo * 0.20; 
				    ValorTotal = (subtotal + prestamo);
				  
				  	printf("\nSu prestamo Ha sido exitoso.");
				  	printf("\nSu deuda total con el banco es de %.2f dolares\n",ValorTotal);
				  	banco[i].saldo += prestamo;
					printf("\nSaldo de %s es: %d",name, banco[i].saldo); 
				  }
				  
				  else if(prestamo >= 10000 && prestamo <20000){
				  	subtotal = prestamo * 0.15; 
				    ValorTotal = (subtotal + prestamo);
				    
				    printf("\nSu prestamo Ha sido exitoso.");
				    printf("\nSu deuda total con el banco es de %.2f dolares\n",ValorTotal);
				    banco[i].saldo += prestamo;
					printf("\nSaldo de %s es: %d",name, banco[i].saldo); 
				  }
				  
				  else if(prestamo >= 20000 && prestamo <30000){
				  	subtotal = prestamo * 0.10; 
				    ValorTotal = (subtotal + prestamo);
				    
				    printf("Su prestamo Ha sido exitoso");
				    printf("\nSu deuda total con el banco es de %.2f dolares\n",ValorTotal);
				    banco[i].saldo += prestamo;
					printf("\nSaldo de %s es: %d",name, banco[i].saldo); 
				  }
				  
				  else if(prestamo >= 30000){
				  	subtotal = prestamo * 0.05; 
				    ValorTotal = (subtotal + prestamo);
				    
				    printf("Su prestamo Ha sido exitoso");
				    printf("\nSu deuda total con el banco es de %.2f dolares\n",ValorTotal);
				    banco[i].saldo += prestamo;
					printf("\nSaldo de %s es: %d",name, banco[i].saldo); 
				  }
				  
				}//cierra el if(strcmp(name,banco[i].nombre)== 0)
				
     		  }//cierra el primer for  
     		  if(strcmp(name,banco[i].nombre)!= 0){
			   		printf("\nNombre de Usuario No Encontrado\n");
			   		Beep(1000,1000);
			   		break;
				}
			  
     		  break;
     		   
 
     		  
     		  
     case 11: printf("\nCAMBIAR NOMBRE DE USUARIO\n");
     		  printf("Usuario: ");scanf("%s",name);
     		  for(i = 0; i < cont; i++){
     		  	if(strcmp(name,banco[i].nombre)== 0){
     		  		printf("\nNombre Nuevo: "); scanf("%s",&banco[i].nombre);
     		  		printf("\nSu Usuario fue cambiado Exitosamente\n");
				   }
				else if(strcmp(name,banco[i].nombre)== 1){
			   		printf("\nNombre de Usuario No Encontrado\n");
			   		Beep(1000,1000);
			   		break;
				}
			   }
			   
			   break;
			   
	 case 12: printf("\nGenerador de Tarjeta de Debito\n");
	 		  printf("Usuario: ");scanf("%s",name);
	 		  printf("\n");
     		  for(i = 0; i < cont; i++){
     		  	if(strcmp(name,banco[i].nombre)== 0){
     		  		for(j = 0; j <= 10; j++){
     		  			digitos = rand() % 100 + 1;
     		  			printf("%d", digitos);
					   }	
				   }
				   
			   }
			   printf("\nEsa es su tarjeta \n"); 
			    
			   
			   break;		   
	 		  
     case 13: system("START https://www.youtube.com/watch?v=cnM2_Hhf9t4");
     		  printf("\n=== REPORTE ===\n");
	 		  f = fopen( "ReporteMilitar.txt", "w" );
	 		  
	 		  fprintf(f,"\n LO QUIERO MUCHO PROFESORCITO YOAN \n ATT: Juanjo :) \n ");
	 		  fclose(f);
              system( "notepad ReporteMilitar.txt" );
              break;
              
	 case 0: break;		  
	 
 	 default: system("START https://www.youtube.com/watch?v=ECyDij_Tjac");
	  	      printf("\n=== REPORTE ===\n");
	 		  f = fopen( "MANCO.txt", "w" );
	 		  
	 		  fprintf(f,"\n		=== REPORTE ===\n\n UFF MEN ERES BIEN MANCO. MIRA COMO DEJASTE AL POBRE TOM ");
	 		  fclose(f);
              system( "notepad MANCO.txt" ); 
	  		
			  
      }
   }while(opcion != 0);
   save = fopen( "BancoMilitar.dat", "wb" );
   fwrite( &cont, sizeof( int ), 1, save );
   fwrite( banco, sizeof( cliente ), 100, save );
   fclose( save );
   printf( "*** se salvaron %d registros con exito\n", cont );
   return 0;
}
