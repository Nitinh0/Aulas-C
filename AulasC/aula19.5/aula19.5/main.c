#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "launcher.h"

int main() {
	int nApps;
	struct App* catalogo;
	FILE* f;

	printf("Quantas aplicações deseja configurar? ");
	fscanf(stdin, "%d", &nApps);
	getchar();

	catalogo = (struct App*)malloc(nApps * sizeof(struct App));

	if (catalogo != NULL) {
		configurarApps(catalogo, nApps);
		printf("\nAplicações configuradas:\n");
		f = fopen("config.txt", "w");
		if (f != NULL) {
			for (int i = 0; i < nApps; i++) {
				printf("Aplicação %d:\nNome: %s, \nCaminho: %s\n", i + 1, catalogo[i].nome, catalogo[i].caminho);
				fprintf(f, "%s\n%s\n", catalogo[i].nome, catalogo[i].caminho);
			}
			fclose(f);
		}
		else {
			printf("Erro ao abrir o arquivo para escrita.\n");
		}
		free(catalogo);
	}
	else {
		printf("Erro ao alocar memória para o catálogo de aplicações.\n");
	}
}