/*
	PROGRAMA PARA ORDENAR ITENS EM UM VETOR UTILIZANDO O ALGORITMO INSERTION SORT.
*/

#include <stdio.h>
#include <stdlib.h>

void ordemCresc(int array[], int n);

int main(void) {
	system("clear");
	
	int i, array[20] = {8, 7, 5, 4, 2, 9, 1, 3, 6, 0, 12, 19, 46, 24, 98, 76, 65, 45, 87, 50};

	ordemCresc(array, 20); // apenas o nome é necessário para passar o vetor para a função
	
	for (i=0;i<20;i++) {
		printf("%d ", array[i]);
	
	}
	
	return 0;
}

void ordemCresc(int array[], int n) {

	int copia, indice, i;
	
	for (i=1;i<20;i++) {
		copia=array[i];
		indice=i;
		
		while (indice>0 && array[indice-1] > copia) {
			array[indice]=array[indice-1];
			indice--;
		
		}
		array[indice]=copia;
		
	}

	return;
}

