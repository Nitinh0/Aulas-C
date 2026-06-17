#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void verificarOrcamento(double custo) {
	if (custo > 5000.0) {
		printf("Alerta: Projeto de Alto Custo!\n");
	}
	else {
		printf("Projeto dentro do orçamento base.\n");
	}
}

int main() {
	double custos[3];
	printf("Insira o custo do projeto 1: \n");
	scanf("%lf", &custos[0]);
	printf("Insira o custo do projeto 2: \n");
	scanf("%lf", &custos[1]);
	printf("Insira o custo do projeto 3: \n");
	scanf("%lf", &custos[2]);

	verificarOrcamento(custos[0]);
	verificarOrcamento(custos[1]);
	verificarOrcamento(custos[2]);
	return 0;
}