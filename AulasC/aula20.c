#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct JogoNode {
	char nome[50];
	struct JogoNode* proxima;
};

int main() {
	struct JogoNode* inicio = NULL;
	struct JogoNode* atual = NULL;
	struct JogoNode* jogo1 = NULL;
	struct JogoNode* jogo2 = NULL;
	struct JogoNode* jogo3 = NULL;

	jogo1 = malloc(sizeof(struct JogoNode));
	strcpy(jogo1->nome, "GTA V");
	jogo1->proxima = NULL; //neste momento existe apenas um jogo, a proxima posição é NULL

	jogo2 = malloc(sizeof(struct JogoNode));
	strcpy(jogo2->nome, "FIFA 26");
	jogo1->proxima = jogo2; //o jogo 1 aponta para o jogo 2
	jogo2->proxima = NULL; //o jogo 2 é o último da lista, então a próxima posição é NULL

	jogo3 = malloc(sizeof(struct JogoNode));
	strcpy(jogo3->nome, "Call of Duty: Modern Warfare II");
	jogo2->proxima = jogo3; //o jogo 2 aponta para o jogo 3
	jogo3->proxima = NULL; //o jogo 3 é o último da lista, então a próxima posição é NULL

	inicio = jogo1; //o início da lista é o jogo 1
	atual = inicio;

	while (atual != NULL) {
		printf("Jogo: %s\n", atual->nome);
		atual = atual->proxima; //avança para o próximo jogo
	}

	//libera a memória alocada
	atual = inicio; // Voltamos a colocar o leitor no início
	struct JogoNode* proximoTemporario;

	while (atual != NULL) {
		proximoTemporario = atual->proxima; // 1. Guardamos a morada do próximo jogo em segurança
		free(atual);                        // 2. Destruímos o jogo atual em segurança
		atual = proximoTemporario;          // 3. Saltamos para o jogo que guardámos
	}

	return 0;
}