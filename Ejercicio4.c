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
void buscarX(int *array,int largo, int x){
	if(largo!=0){
		buscarX(array,largo-1,x);
		if (array[largo-1]==x){
			printf("\nEl numero %d esta en la posicion %d del arreglo",x,largo-1);
		}
	}
}
int main(int argc, char const *argv[])
{
	int *arreglo;
	int largo,numX;
	printf("\nPrograma para buscar un elemento en un arreglo");
	printf("\nCuantos elementos desea que tenga el arreglo: ");
	scanf("%d",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarElementos(arreglo,largo);
	printf("\nIngrese el numero que desea buscar en el arreglo: ");
	scanf("%d",&numX);
	buscarX(arreglo,largo,numX);
	return 0;
}