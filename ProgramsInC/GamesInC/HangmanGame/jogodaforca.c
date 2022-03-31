#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

char *sortPalavra(char [], char []);

void flush_in() { 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
    
}

void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
    
}

char *sortPalavra(char arquivo[], char palavraSortida[]) {
	char linha[100][13];
	int cont=0, i;
	FILE *arq;

	if ((arq=fopen("palavrasForca.txt", "r"))==NULL) {
		puts("Erro ao abrir o arquivo!");

	}
	else {
		do {
			fgets(palavraSortida, 13, arq);
			
			for (i=0;i<strlen(palavraSortida);i++) {
				if (palavraSortida[i]=='\n') {
					palavraSortida[i]='\0';
				
				}
				
			}
			 
			if (strcmp(palavraSortida, "")) {
				strcpy(linha[cont], palavraSortida);
				cont++;
			
			}
		
		} while (!feof(arq));
	
	}
	
	srand(time(NULL));
	i=rand()%cont;
	
	strcpy(palavraSortida, linha[i]);
	
//	printf("%s", palavraSortida);
				
	return palavraSortida;
}

int main(void) {
	system("clear");
	
	char palavraCorreta[13], arrayForca[13], letraTentativa=' ', arrayAux[13], palavraSortida[13];
	int i, r, numTentativas=0, maxTentativas, acertos=0, erros=0, fimdeJogo=0, letraCorreta, ultLoop=0;
	void gotoxy(int x, int y);
	void flush_in();
	int toupper (int c);
	int tolower (int c);
	int isupper (int c);

	strcpy(palavraCorreta, sortPalavra("palavrasForca.txt", palavraSortida));
	strcpy(arrayAux, palavraCorreta);
	
	maxTentativas=strlen(palavraCorreta)*.5;

// |===== INSERE CAMPOS VAZIOS DE ACORDO COM O TAMANHO DA STRING =====| 

	for (i=0;i<strlen(palavraCorreta);i++) {
		arrayForca[i]=' ';
		
	}

// |===== LAÇO DE REPETIÇÃO PARA TODO O PROGRAMA =====| 

	do {
		system("clear");
		gotoxy(20, 1);
		printf("\n\n\n\n");
		printf("\t\t\t*---------------------------*\n");
		printf("\t\t\t|                           |\n");
		printf("\t\t\t|       JOGO DA FORCA       |\n");
		printf("\t\t\t|                           |\n");
		printf("\t\t\t*---------------------------*\n");
		printf("\n\n\n\n");
		

// |===== INSERE OS ESPAÇOS PARA AS LETRAS ENCONTRADAS =====|

		gotoxy(16,14);
		for (i=0;i<strlen(palavraCorreta);i++) {
			printf(" %c  ", arrayForca[i]);
			
		}
		

// |===== TENTATIVAS RESTANTES, ACERTOS E ERROS =====|
		
		gotoxy(65, 6);
		printf("Tentativas: %d\n", maxTentativas-numTentativas);
		gotoxy(65, 7);
		printf("Acertos: %d\n", acertos);
		gotoxy(65, 8);
		printf("Erros: %d", erros);
		gotoxy(65, 9);
		printf("Histórico: %c", letraTentativa);
		

// |===== INSERE O GABARITO DAS POSIÇÕES =====|

		gotoxy(16, 15);
		for (i=0;i<strlen(arrayForca);i++) {
			printf("___ ");
			
		}
	
// |===== ENTRADA DE TENTATIVAS DO JOGADOR =====|
		
		if (ultLoop==1) {
			gotoxy(34, 18);
			printf("VOCÊ VENCEU!");
			break;
		
		}
		else if (ultLoop==2) {
			gotoxy(34, 18);
			printf("VOCÊ PERDEU!");
			break;
		
		}
		else {
			gotoxy(18, 18);
			printf("INSIRA UMA LETRA PARA JOGAR ou 0 PARA SAIR");
		
		}
		
		if (ultLoop==1) {
			break;	
			
		}
		else {
			gotoxy(39, 21);
			scanf("%c", &letraTentativa);
			flush_in();
		
		}
		
		if (isupper(letraTentativa)) {
			letraTentativa= tolower(letraTentativa);
		
		}
		
// |===== TESTA SE A ENTRADA É VÁLIDA =====|

		letraCorreta=0;

		for (i=0;i<strlen(palavraCorreta);i++) {
			if (arrayAux[i]==letraTentativa) {
				arrayAux[i]=' ';
				arrayForca[i]=toupper(letraTentativa);
				acertos++;
				letraCorreta=1;
			
			}
		
		}
		
		if (letraCorreta==0) {
			erros++;
			numTentativas++;
		
		}
		
// |===== TESTA VITÓRIA OU DERROTA =====|

		r=strcasecmp(arrayForca, palavraCorreta);
		
		if (r) {
			
		}
		else {
			ultLoop=1;
		
		}
		
		for (i=0;i<strlen(palavraCorreta);i++) {
			if (numTentativas>=maxTentativas || letraTentativa=='0') {	
				arrayForca[i]=toupper(palavraCorreta[i]);
				ultLoop=2;
				
			}	
							
		} 
		
	} while (fimdeJogo==0);
		
	return 0;
}