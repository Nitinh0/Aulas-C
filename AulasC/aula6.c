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

	for (int i = 0; i < 3; i++){
		printf("Insira o custo do projeto %d: ", i + 1);
		scanf("%lf", &custos[i]);
	}

	for (int i = 0; i < 3; i++)	{
		verificarOrcamento(custos[i]);
	}
	return 0;
}