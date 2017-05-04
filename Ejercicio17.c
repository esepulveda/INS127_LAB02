#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Nodo{
	int valor;
	struct Nodo *sgte;
}nodo;
typedef struct Pila{
	nodo *tope;
	int tam;
}pila;
pila *crearPila(){
	pila *newPila;
	if(newPila=(pila*)malloc(sizeof(pila))){
		newPila->tam=0;
		newPila->tope=NULL;
	}else{
		printf("\nError, memoria pila no asignada");
	}
	return newPila; 
}
void apilar(pila *pilaPush,int val){
	nodo *newNodo;
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->sgte=pilaPush->tope;
		pilaPush->tam++;
		pilaPush->tope=newNodo;
		newNodo->valor=val;
	}
}
nodo *desapilar(pila *pilaPop){
	nodo *aux;
	if(pilaPop->tam>0){
		aux=pilaPop->tope;
		pilaPop->tope=aux->sgte;
		aux->sgte=NULL;
	}
	return aux;
	free(aux);
}
bool noEsVacia(pila *pilaV){
	if(pilaV->tope!=NULL){
		return true;
	}else{
		return false;
	}
}
pila *vaciarPila(pila *pilaV){
	pila *newPila=crearPila();
	nodo *nodoTope;
	while(noEsVacia(pilaV)){
		nodoTope=desapilar(pilaV);
		apilar(newPila,nodoTope->valor);
	}
	return newPila;
	free(newPila);
}

pila *invertirPila(pila *pilaI){
	pila *newPila=vaciarPila(pilaI);
	nodo *nodoTope;
	while(noEsVacia(pilaI)){
		nodoTope=desapilar(pilaI);
		newPila=invertirPila(pilaI);
		apilar(newPila,nodoTope->valor);
	}
	return newPila;
}
void mostrarPila(pila *pilaM){
	nodo *nodoTope;
	printf("\nLos valores de la pila son: ");
	while(noEsVacia(pilaM)){
		nodoTope=desapilar(pilaM);
		printf("\n%d",nodoTope->valor);
	}
	free(nodoTope);
}
int main(int argc, char const *argv[]){
	pila *pilaMain,*pilaMainD,*pilaInvertida;
	pilaMain=crearPila();
	pilaMainD=crearPila();
	apilar(pilaMain,1);
	apilar(pilaMain,2);
	apilar(pilaMain,3);
	apilar(pilaMain,4);
	apilar(pilaMainD,1);
	apilar(pilaMainD,2);
	apilar(pilaMainD,3);
	apilar(pilaMainD,4);
	mostrarPila(pilaMainD);
	pilaInvertida=(invertirPila(pilaMain));
	mostrarPila(pilaInvertida);
	return 0;
}