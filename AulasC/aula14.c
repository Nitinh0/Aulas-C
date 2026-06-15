#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Jogo {
	char nome[50];
	char genero[20];
	int ano;
};

int main() {
	struct Jogo meusJogos[2];

	for (int i = 0; i < 2; i++) {
		printf("Insira o nome do jogo %d: ", i+1);
		fgets(meusJogos[i].nome, 50, stdin);
		meusJogos[i].nome[strcspn(meusJogos[i].nome, "\n")] = '\0';
		printf("Digite o genero do jogo %d: ", i+1);
		fgets(meusJogos[i].genero, 20, stdin);
		meusJogos[i].genero[strcspn(meusJogos[i].genero, "\n")] = '\0';
		printf("Digite o ano de lancamento do jogo %d: ", i +1);
		scanf("%d", &meusJogos[i].ano);
		getchar();
	}

	printf("\nJogos Registados:\n");
	for (int i = 0; i < 2; i++) {
		printf("Jogo %d:\n", i+1);
		printf("Nome: %s\n", meusJogos[i].nome);
		printf("Genero: %s\n", meusJogos[i].genero);
		printf("Ano: %d\n", meusJogos[i].ano);
	}
	return 0;
}