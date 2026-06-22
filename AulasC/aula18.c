#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogo {
	char nome[50];
};

int main() {
	int quantidade;
	printf("Insira a quantidade de jogos: ");
	scanf("%d", &quantidade);
	getchar();

	struct Jogo *catalogo;
	catalogo = malloc(quantidade * sizeof(struct Jogo));

	for (int i = 0; i < quantidade; i++) {
		printf("Insira o nome do jogo %d: ", i + 1);
		fgets(catalogo[i].nome, sizeof(catalogo[i].nome), stdin);
		catalogo[i].nome[strcspn(catalogo[i].nome, "\n")] = '\0';
	}

	printf("\nCatalogo de Jogos:\n");
	for (int i = 0; i < quantidade; i++) {
		printf("%d. %s\n", i + 1, catalogo[i].nome);
	}

	free(catalogo);
	return 0;
}