#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double custo = -0.1;

	while (custo != 0.0) {
		printf("Digite o custo do projeto:\n");
		scanf("%lf", &custo);

		if (custo > 5000.0) {
			printf("Alerta: Projeto de Alto Custo!\n");
		}
		else {
			printf("Projeto dentro do orçamento base.\n");
		}
	}
}