#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void verificarOrcamento(char nome[], double custo) {
	if (custo > 5000.0) {
		printf("Projeto %s: Alerta! Projeto de Alto Custo!\n", nome);
	}
	else {
		printf("Projeto %s: Dentro do orcamento base.\n", nome);
	}
}

int main() {
	char nomeProjeto[50];
	double custo;

	printf("Insira o nome do projeto: \n");
	scanf("%s", nomeProjeto);

	printf("Insira o custo do projeto: \n");
	scanf("%lf", &custo);

	verificarOrcamento(nomeProjeto, custo);
	return 0;
}