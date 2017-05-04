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
void insertarOrdenado(lista *listaO,int x,nodo *ptrO){
	nodo *nodoO,*auxA,*auxB;
	nodoO=(nodo*)malloc(sizeof(nodo));
	nodoO->valor=x;
	if(nodoO->valor<ptrO->valor && listaO->ini==ptrO){ 
		nodoO->sgte=listaO->ini;
		listaO->ini=nodoO;
		listaO->tam++;
	}else if (ptrO->sgte!=NULL){
		insertarOrdenado(listaO,x,ptrO->sgte); 
		if(nodoO->valor<ptrO->sgte->valor && x>ptrO->valor){
			auxA=ptrO;
			auxB=ptrO->sgte;
			auxA->sgte=nodoO;
			nodoO->sgte=auxB;
			listaO->tam++;
		}
	}
}



int main(int argc, char const *argv[])
{
	lista *listaMain;
	int num;
	listaMain=crearLista();
	agregarNodo(listaMain,9);
	agregarNodo(listaMain,7);
	agregarNodo(listaMain,5);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,1);
	printf("\nPrograma para insertar un elemento ordenado en la una lista con elementos ya ordenados");
	recorrerLista(listaMain);
	printf("\nAhora ingrese una numero para insertalo: ");
	scanf("%d",&num);
	nodo *ptr=listaMain->ini;
	insertarOrdenado(listaMain,num,ptr);
	recorrerLista(listaMain);
	return 0;
}