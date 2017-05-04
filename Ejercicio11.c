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
void EliminarX(lista *listaO,int x,nodo *ptrO){
	nodo *aux;
	if(x==ptrO->valor && listaO->ini==ptrO){ //primera parte no recursiva, ya que si el nodo a eliminar 
		aux=ptrO;                            // esta en la primera posicion no necesito hacer nada mas     
		listaO->ini=aux->sgte;
		aux->sgte=NULL;
		listaO->tam--;
		free(aux);
	}else if (ptrO->sgte!=NULL){
		EliminarX(listaO,x,ptrO->sgte); //recursividad
		if(x==ptrO->sgte->valor){
			aux=ptrO->sgte;
			ptrO->sgte=ptrO->sgte->sgte;
			aux->sgte=NULL;
			listaO->tam--;
			free(aux);
		}
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
	printf("\nPrograma para eliminar un elemento de la lista ");
	recorrerLista(listaMain);
	printf("\nAhora ingrese una numero para eliminarlo: ");
	scanf("%d",&num);
	nodo *ptr=listaMain->ini;
	EliminarX(listaMain,num,ptr);
	recorrerLista(listaMain);
	return 0;
}