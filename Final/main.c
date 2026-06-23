#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "motor.h"

int main() {
	struct AppNode* inicio = NULL;
	addApp(&inicio, "Bloco de Notas", "C:\\Windows\\notepad.exe");
	addApp(&inicio, "Calculadora", "C:\\Windows\\System32\\calc.exe");
	addApp(&inicio, "Paint", "C:\\Windows\\System32\\mspaint.exe");
	exportarJSON(inicio);
	abrirAplicativo(inicio->caminho);
	liberarLista(inicio);
	return 0;
}