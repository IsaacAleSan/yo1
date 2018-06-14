#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
int edad;
char nombre;
struct nodo *ant;
struct nodo *sig;
struct nodo *aux;
}nodo;
nodo* primero=NULL;
nodo* ultimo=NULL;

void insertarNodo();
void desplegar();
void desplegarUP();
void eliminar();
void avanzar();

int main(){
	int op = 0;
	do{
	printf("----Que decea realisar---- \n 1)ingresar jugadores \n 2)jugar\n \n");
	scanf ("%i",&op);
	switch (op){
		case 1:
		insertarNodo();
		break;
		case 2:
		avanzar();
		break;
	}system("cls");
}while(op!=3);
	return 0;
}
void insertarNodo(){	
	int e;
	char nom;
    nodo* nuevo =(nodo*) malloc(sizeof(nodo));
	printf("inserte el nombre\n");
	scanf("%d",&nom);
	nuevo->nombre=nom;
	printf("inserte la edad\n");
	scanf("%d",&e);
	nuevo->edad=e;
	
	
	if(primero==NULL){
		primero=nuevo;
		primero->sig=primero;
		ultimo=primero;
		primero->ant=ultimo;
	}
	else{
	ultimo->sig=nuevo;
	nuevo->sig=primero;
	nuevo->ant=ultimo;
	ultimo=nuevo;
	primero->ant=ultimo;
	}
	printf("jugador ingresado\n");
	desplegar();
	system("pause");
}
void desplegar(){
	nodo* actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		do{
			
			printf("\n%d   %d\n",actual->edad,actual->nombre);
			actual=actual->sig;
		} while(actual != primero);
}
	else{
		printf("la lista se encuentra vacia \n");
		 }
 }
void desplegarUP(){
 	
	nodo* actual=(nodo*)malloc(sizeof(nodo));
	actual=ultimo;
	if(primero!=NULL){
		do{
			
			printf("\n%d",actual->edad);
			actual=actual->ant;
		} while(actual != ultimo);
}
	else{
		printf("la lista se encuentra vacia \n");
 }
 }
void avanzar(){	
 	nodo* actual=(nodo*)malloc(sizeof(nodo));
	int n=0,i;
	actual=primero;
	n=3;
	do{
		for (i=0; i<=n; i++){
		actual=actual->sig;		
	}
	n=actual->edad;
	printf("la edad de el niño eliminado es %i \n",n);
	
	actual->ant->sig=actual->sig;
	actual->sig->ant=actual->ant;
	
	for (i=0; i<=n; i++){
		actual=actual->ant;
	}
	n=actual->edad;
	
	actual->ant->sig=actual->sig;
	actual->sig->ant=actual->ant;
	printf("la edad de el niño eliminado es %i \n",n);
}while (actual != primero);
printf("la edad de el niño ganador es %i \n",n);
system("pause");
}
