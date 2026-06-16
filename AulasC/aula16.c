#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void trocarprioridade(int* appA, int* appB) {
	int temp = *appA;
	*appA = *appB;
	*appB = temp;
}

int main() {
	int prioridadeStremio = 1;
	int prioridadeSteam = 2;

	printf("Prioridade incial: \n");
	printf("Stremio: %d\n", prioridadeStremio);
	printf("Steam: %d\n", prioridadeSteam);

	trocarprioridade(&prioridadeStremio, &prioridadeSteam);

	printf("Prioridade final: \n");
	printf("Stremio: %d\n", prioridadeStremio);
	printf("Steam: %d\n", prioridadeSteam);

	return 0;
}