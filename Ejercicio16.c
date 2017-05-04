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
void listarLista(lista *listaO,nodo *ptrO){
	if(ptrO==listaO->ini){
		printf("\nLos elementos de la lista son");
	}
	if (ptrO!=NULL){
		printf("\n%d",ptrO->valor);
		listarLista(listaO,ptrO->sgte);
	}
}
nodo *eliminarElementoFinal(lista *listaE){
	nodo *aux,*auxE;
	aux=listaE->ini;
	auxE=listaE->fin;
	nodo *ptrAnteFin;
	int i;
	if(listaE->tam>0){
		for (i=1;i<listaE->tam-1;i++){
			aux=aux->sgte;
		}
		ptrAnteFin=aux;
		ptrAnteFin->sgte=NULL;
		listaE->fin=ptrAnteFin;
		listaE->tam--;
	}
	return auxE;
	free(aux);
	free(auxE);
}

lista *invertirLista(lista *listaI){
	nodo *nodoFin;
	lista *newlista=crearLista();
	if(listaI->tam>0){
		nodoFin=eliminarElementoFinal(listaI);
		newlista=invertirLista(listaI);
		agregarNodo(newlista,nodoFin->valor);
		return newlista;
	}else{
		return newlista;
	}
}

int main(int argc, char const *argv[])
{
	lista *listaMain,*listaInvertida;
	listaMain=crearLista();
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,4);
	agregarNodo(listaMain,5);
	printf("\nPrograma para invertir una lista");
	nodo *ptr=listaMain->ini;
	listarLista(listaMain,ptr);
	listaInvertida=invertirLista(listaMain);
	printf("\n");
	printf("\nLista Invertida");
	ptr=listaInvertida->ini;
	listarLista(listaInvertida,ptr);
	return 0;
}