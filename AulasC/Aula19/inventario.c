#include <stdio.h>
#include "inventario.h"

void adicionarStock(struct Produto *p, int qtdNova) {
	if (p != NULL) {
		p->quantidade += qtdNova;
	}
}