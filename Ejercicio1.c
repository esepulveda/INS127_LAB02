#include <stdio.h>

int calcularFactorial(int n){
	int fact=1;
	if(n>0){
		fact=calcularFactorial(n-1);
		fact=fact*n;
		return fact;
	}else{
		return fact;
	}
}
int main(int argc, char const *argv[])
{
	int num,factorial;
	printf("\nPrograma para calcular el factorial de un numero");
	printf("\nIngrese un numero : ");
	scanf("%d",&num);
	factorial=calcularFactorial(num);
	printf("\nEl factorial de %d es: %d",num,factorial);
	return 0;
}