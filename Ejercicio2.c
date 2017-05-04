#include <stdio.h>

int multiplicarConSuma(int a, int b){
	int product=0;
	if (a>0){
		product=multiplicarConSuma(a-1,b);
		product=product+b;
		return product;
	}else{
		return product;
	}
}
int main(int argc, char const *argv[])
{
	int numA,numB,producto;
	printf("\nPorgrama para multiplicar dos numeros ocupando sumas");
	printf("\nIngrese un numero: ");
	scanf("%d",&numA);
	printf("\nIngrese un segundo numero:");
	scanf("%d",&numB);
	producto=multiplicarConSuma(numA,numB);
	printf("\nEl producto de los numeros %d y %d es %d",numA,numB,producto);
	return 0;
}