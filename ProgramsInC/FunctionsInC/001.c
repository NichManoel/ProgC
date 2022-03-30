/*
	FAÇA UM PROGRAMA QUE LEIA DOIS NÚMEROS INTEIROS E CALCULE A SOME DO VALOR ABSOLUTO DE CADA UM.
*/

#include <stdio.h>
#include <stdlib.h>

int somarAbsoluto(int x, int y);
int numModulo(int x);

int main(void) {
	system("clear");
	
	int x, y;
	
	printf("Insira o valor de X e de Y: ");
	scanf("%d%d", &x, &y);
	
	int somaAbs=somarAbsoluto(x, y);
	
	printf("A soma dos absolutos é = %d", somaAbs);
	
	return 0;
}

int somarAbsoluto(int x, int y) {
	
	if (x<0) {
		x=numModulo(x);
	
	} 
	else if (y<0) {
		y=numModulo(y);
	
	}
	
	int somaAbs=x+y;	

	return somaAbs;
}

int numModulo(int x) {
	
	int mod=x * -1;	

	return mod;
}
