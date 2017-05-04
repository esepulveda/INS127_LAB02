#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int l){
	int *array;
	array=(int*)malloc(l*sizeof(int));
	return array;
}
int *agregarElementos(int *array,int largo){
	int i,num;
	for (i=0;i<largo;i++){
		printf("\nIngrese el elemento %d al arreglo: ",i+1);
		scanf("%d",&num);
		array[i]=num;
	}
	return array;
}
void imprimirArreglo(int *arreglo,int largo){
	if(largo!=0){
		imprimirArreglo(arreglo,largo-1);
		printf("\nElemento %d del arreglo es : %d",largo,arreglo[largo-1]);
	}
}

int main(int argc, char const *argv[])
{
	int *arreglo;
	int largo;
	printf("\nPrograma mostrar los numeros dentro de un arreglo");
	printf("\nCuantos elementos desea que tenga el arreglo: ");
	scanf("%d",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarElementos(arreglo,largo);
	imprimirArreglo(arreglo,largo);
	return 0;
}