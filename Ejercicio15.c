#include <stdio.h>
#include <stdlib.h>
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
void recorrerLista(lista *listaR){
	nodo *aux;
	aux=listaR->ini;
	printf("\nLa lista contiene los siguientes elementos");
	while(aux!=NULL){
		printf("\n%d",aux->valor);
		aux=aux->sgte;
	}
}

lista *merge(lista *listaA, lista *listaB,nodo *auxA,nodo *auxB){
	lista *listaM=crearLista();
	int valor;
	if(auxA!=NULL && auxB!=NULL){
		if (auxA->valor<auxB->valor){
			listaM=merge(listaA,listaB,auxA->sgte,auxB);
			valor=auxA->valor;
		}else{
			listaM=merge(listaA,listaB,auxA,auxB->sgte);
			valor=auxB->valor;
		}

		agregarNodo(listaM,valor);
		return listaM;	
	}else{
		agregarNodo(listaM,auxB->valor);
	}
	return listaM;
}


int main(int argc, char const *argv[])
{
	lista *listaMainA,*listaMainB,*listaMainC;
	listaMainA=crearLista();
	listaMainB=crearLista();
	listaMainC=crearLista();
	agregarNodo(listaMainA,9);
	agregarNodo(listaMainA,7);
	agregarNodo(listaMainA,5);
	agregarNodo(listaMainA,3);
	agregarNodo(listaMainA,1);
	agregarNodo(listaMainB,10);
	agregarNodo(listaMainB,8);
	agregarNodo(listaMainB,6);
	agregarNodo(listaMainB,4);
	agregarNodo(listaMainB,2);
	nodo *ptrA=listaMainA->ini;
	nodo *ptrB=listaMainB->ini;
	listaMainC=merge(listaMainA,listaMainB,ptrA,ptrB);




	printf("\nPrograma para crear una nueva lista ordenada a partir de 2 listas, ingresando valores intercalados");
	printf("\nLista 1");
	recorrerLista(listaMainA);
	printf("\nLista 2");
	recorrerLista(listaMainB);
	printf("\n");
	printf("\nLista ordenada e intercalada");
	recorrerLista(listaMainC);
	return 0;
}