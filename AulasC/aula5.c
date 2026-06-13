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
	scanf("Insira o custo do projeto 1: %lf\n", &custos[0]);
	scanf("Insira o custo do projeto 2: %lf\n", &custos[1]);
	scanf("Insira o custo do projeto 3: %lf\n", &custos[2]);

	verificarOrcamento(custos[0]);
	verificarOrcamento(custos[1]);
	verificarOrcamento(custos[2]);
}