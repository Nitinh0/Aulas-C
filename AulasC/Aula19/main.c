#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "inventario.h"

int main() {
	struct Produto Teclado;
	strcpy(Teclado.nome, "Teclado");
	Teclado.quantidade = 10;

	printf("Quantidade de %s: %d\n", Teclado.nome, Teclado.quantidade);

	adicionarStock(&Teclado, 5);

	printf("Quantidade de %s: %d\n", Teclado.nome, Teclado.quantidade);

	return 0;
}