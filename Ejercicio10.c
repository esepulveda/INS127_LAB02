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
	free(aux);
}
int existeElemento(lista *listaO,int x,nodo *ptrO){
	int interruptor=0;
	if (ptrO!=NULL){
		interruptor=existeElemento(listaO,x,ptrO->sgte);
		if(x==ptrO->valor){
			interruptor=1;
		}
		return interruptor;
	}else{
		return interruptor;
	}
}

int main(int argc, char const *argv[])
{
	lista *listaMain;
	int num;
	listaMain=crearLista();
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,5);
	agregarNodo(listaMain,7);
	printf("\nPrograma para saber si un elemento existe en la lista ");
	recorrerLista(listaMain);
	printf("\nAhora ingrese una numero para ver si existe: ");
	scanf("%d",&num);
	nodo *ptr=listaMain->ini;
	int interrup=existeElemento(listaMain,num,ptr);
	if(interrup==1){
		printf("\nLa variable %d si existe en la lista");
	}else{
		printf("\nLa variable %d no existe en la lista");
	}
	return 0;
}