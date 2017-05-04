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
int sumarArreglo(int *arreglo,int largo){
	int acum=0;
	if(largo!=0){
		acum=sumarArreglo(arreglo,largo-1);
		acum=acum+arreglo[largo-1];
		return acum;
	}else{
		return acum;
	}
}
int main(int argc, char const *argv[])
{
	int *arreglo;
	int largo,suma;
	printf("\nPrograma para sumar los numeros dentro de un arreglo");
	printf("\nCuantos elementos desea que tenga el arreglo: ");
	scanf("%d",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarElementos(arreglo,largo);
	suma=sumarArreglo(arreglo,largo);
	printf("\nLa suma de los elementos del arreglo da como resultado : %d",suma);
	return 0;
}