#include <stdio.h>

void multiDiagonal(int matrizA[3][3], int matrizB[3][3]);
void mostrarMatriz(int matrizA[3][3], int matrizB[3][3]);

int main() {
	int matrizA[3][3]={2, 3, 4, 5, 6, 7, 0, 8, 9}, matrizB[3][3];

	multiDiagonal(matrizA, matrizB);
	mostrarMatriz(matrizA, matrizB);

	return 0;
}

void multiDiagonal(int matrizA[3][3], int matrizB[3][3]) {
	int i, j;
	
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			matrizB[i][j]=matrizA[i][j]*matrizA[i][i];
			
		}
				
	}
	
	return;
}

void mostrarMatriz(int matrizA[3][3], int matrizB[3][3]) {
	int i, j;
	
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			printf(" %i", matrizA[i][j]);
			
		}
		printf("\n");
		
	}
	
	printf("\n");
	
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			printf(" %i", matrizB[i][j]);
			
		}
		printf("\n");
	
	}

	return;
}

