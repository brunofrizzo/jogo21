#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Funcao para gerar numero aleatorio de 1 a 6
int dadoBranco() { 
	return ((rand() % 6) + 1); //Limita os numeros aleatorio gerados para ser de 1 ate 6
}

int dadoVermelho() {
	return ((rand() % 6) + 1);
}

int main () {
	int i, pontosJogador1=0, pontosJogador2=0, opcao, resultadoDadoVermelho, x=0;
	
	srand(time(0));
	
	for (i = 1; i <= 3; i++) { //3 rodadas
		
		printf("Jogador 1, informe uma opcao: 1-Rodar o dado ou 2-Passar a vez?\n");
		scanf("%d", &opcao);
			
		switch(opcao) {
			case 1:
				printf("Rodando dado branco...\n");
				pontosJogador1 = (pontosJogador1 + dadoBranco()); //Acumula na variavel o valor do dado branco
				printf("Sua pontuacao: %d\n", pontosJogador1);
				printf("Rodando o dado vermelho...\n");
				resultadoDadoVermelho = dadoVermelho(); //Armazena em uma variavel o valor do dado vermelho
				if (resultadoDadoVermelho == 6) { //Verifica se o valor do dado vermelho deu 6
					pontosJogador1 = pontosJogador1 + 6*2;
				} else {
					pontosJogador1 = pontosJogador1 + resultadoDadoVermelho; 
				}
				printf("Sua pontuacao: %d\n", pontosJogador1);
				break;
			case 2:
				break; //Passa a vez
			default: printf("opcao invalida\n");
		}
		
		printf("----------------------------\n");
		printf("Jogador 2, informe uma opcao: 1-Rodar o dado ou 2-Passar a vez?\n");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				printf("Rodando dado branco...\n");
				pontosJogador2 = pontosJogador2 + dadoBranco();
				printf("Sua pontuacao: %d\n", pontosJogador2);
				printf("Rodando o dado vermelho...\n");
				resultadoDadoVermelho = dadoVermelho();
				if (resultadoDadoVermelho == 6) {
					pontosJogador2 = pontosJogador2 + 6*2;
				} else {
					pontosJogador2 = pontosJogador2 + resultadoDadoVermelho; 
				}
				printf("Sua pontuacao: %d\n", pontosJogador2);
				break;
			case 2:
				break;
			default: printf("opcao invalida\n");
		}
		
		printf("-------------Fim da rodada %d-------------\n", i);
		
	}	
	
	printf("--------------------\n");
	printf("Pontuacao final\nJogador 1: %d\nJogador 2: %d\n", pontosJogador1, pontosJogador2);
	
	if ((pontosJogador1 > 21) && (pontosJogador2 < 21)) { 
		printf("Resultado: Jogador 2 ganhou\n");
	} else if ((pontosJogador2 > 21) && (pontosJogador1 < 21)) {
		printf("Resultado: Jogador 1 ganhou\n");
	} else if ( ( (pontosJogador1 > 21) && (pontosJogador2 > 21) )  || (pontosJogador1 == pontosJogador2)) { //Verifica se ambos ponturam mais de 21 ou fizeram a mesma pontuação
		printf("Resultado: Empate\n");
	} else if ((pontosJogador1 < 21) && (pontosJogador2 < 21)) {
		if (21 - pontosJogador1 < 21 - pontosJogador2) { //Verifica quem tirou a pontuação mais proxima de 21
			printf("Resultado: Jogador 1 ganhou\n");
		} else {
			printf("Resultado: Jogador 2 ganhou\n");
		}
	}
	
	return 0;
}



 
