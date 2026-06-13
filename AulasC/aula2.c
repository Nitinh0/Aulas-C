#include <stdio.h>

int main() {
	int ano;
	double custo;

	printf("Digite o ano previsto para o projeto e o custo estimado \n");
	scanf("%d", &ano);
	scanf("% .2f", &custo);

	if (custo > 5000.0) {
		printf("Alerta: Projeto de Alto Custo!\n");
	}
	else {
		printf("Projeto dentro do orçamento base.\n");
	}
	return 0;
}
