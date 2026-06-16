# 📘 Manual de Programação em C:

Este repositório contém os meus apontamentos de estudo e a evolução dos meus projetos em linguagem C.

---

## MÓDULO 1: Fundamentos Básicos (Aulas 1 a 5)

### 1. Estrutura Base de um Programa
Todo o código em C precisa de uma estrutura inicial para saber por onde começar a execução e como comunicar com o sistema operativo.

```c
#define _CRT_SECURE_NO_WARNINGS // Desativa avisos de segurança no Visual Studio
#include <stdio.h>              // Biblioteca para Input/Output (printf/scanf)
#include <string.h>             // Biblioteca para manipulação de texto (strings)

int main() {
    // O código começa a ser executado aqui
    return 0; // Indica ao sistema que o programa terminou com sucesso
}
```

### 2. Variáveis e Tipos de Dados

As variáveis são caixas na memória RAM com tipos estritos:
```c
    int: Números inteiros (ex: 10, -5). Usa %d no printf.

    float / double: Números decimais (ex: 10.5). Usa %f ou %lf.

    char: Um único caractere (ex: 'A'). Usa %c.
```

### Operadores Lógicos e Condições (if / else)

Servem para o programa tomar decisões baseadas em testes matemáticos:

```c
if (quantidade <= 5) {
    printf("Stock Crítico!\n");
} else {
    printf("Stock Normal.\n");
}
```
