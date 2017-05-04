#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Nodo{
	int valor;
	struct Nodo *sgte; 
}nodo;
typedef struct Lista{
	nodo *ini;
	nodo *fin;
	int tam;
}lista;

lista *crearLista(){
	lista *newlista;
	if (newlista=(lista*)malloc(sizeof(lista))){
		newlista->ini=NULL;
		newlista->fin=NULL;
		newlista->tam=0;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newlista;
	free(newlista);
}
void agregarNodo(lista *listaA,int num){
	nodo *newNodo;
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->valor=num;
		if (listaA->tam==0){
			listaA->fin=newNodo;
			newNodo->sgte=NULL;
		}
		newNodo->sgte=listaA->ini;
		listaA->ini=newNodo;
		listaA->tam++;
	}
}
bool sonIguales(lista *listaA, lista *listaB,nodo *auxA,nodo *auxB){
	if (auxA!=NULL){
		if(sonIguales(listaA,listaB,auxA->sgte,auxB->sgte)){
			if (auxA->valor==auxB->valor){
				return true;
			}else{
				return false;
			}
		}		
	}
}
int main(int argc, char const *argv[]){
	lista *listaMainA,*listaMainB;
	int num,i,valor;
	listaMainA=crearLista();
	listaMainB=crearLista();
	printf("\nPrograma para indicar si las listas ingresadas son iguales");
	printf("\nCuantos elementos desea agregar a cada lista: ");
	scanf("%d",&num);
	for (i=0;i<num;i++){
		printf("\nIngrese el elemento %d a la lista 1: ",i+1);
		scanf("%d",&valor);
		agregarNodo(listaMainA,valor);
	}
	for (i=0;i<num;i++){
		printf("\nIngrese el elemento %d a la lista 2: ",i+1);
		scanf("%d",&valor);
		agregarNodo(listaMainB,valor);
	}
	nodo *ptrA=listaMainA->ini;
	nodo *ptrB=listaMainB->ini;
	if (sonIguales(listaMainA,listaMainB,ptrA,ptrB)){
		printf("\nTRUE");
	}else{
		printf("\nFALSE");
	}
	return 0;
}