
### 📘 VOLUME 1: Os Alicerces (Aulas 1 a 4)
<details>

<summary><b>Este volume foca-se em como o programa nasce, como guarda dados simples e como toma as primeiras decisões.</b></summary>

### 1. A Estrutura Obrigatória
Todo o programa em C precisa de um ponto de partida e de um relatório de saída.

-   **#include <stdio.h>** -- A biblioteca base que nos permite usar o ecrã e o teclado.
-   **int main()** -- A porta de entrada do programa. O Windows procura sempre por esta função para arrancar.
-   **return 0;**  -- A "assinatura" de que tudo correu bem. É crucial não esquecer, pois é isto que avisa o sistema operativo de que o programa terminou sem erros.

### 2. Variáveis e Marcadores
O C precisa de saber o formato exato das "caixas" de memória e como as imprimir.

-   **int** (Inteiros) -> Marcador: **%d**    
-   **double** (Decimais) -> Marcador: **%lf**
-   **char** (Uma letra) -> Marcador: **%c**

### 3. Ler e Escrever (printf vs scanf)

-   **printf("Texto puro");** -- Usado para falar com o utilizador. Só leva marcadores e variáveis se quiseres imprimir valores.    
-   **scanf("%d", &idade);** -- Usado para ouvir o teclado. 
>**Regra de Ouro:** Para ler números, o scanf exige o símbolo **&** antes da variável, que significa "guarda nesta morada de memória".

### 4. Tomada de Decisão (if / else)

Servem para que o programa faça escolhas com base em condições lógicas, como comparar números ou verificar se a condição é verdadeira ou falsa.
   
   - if: Executa um bloco de código se a condição for verdadeira.

   - else: Executa um bloco de código se a condição for falsa.

Usam operadores de comparação:
   - **==** -- Igual a
   - **!=** -- Diferente de
   - **>** / **>=** -- Maior que / Maoir ou igual a
   - **<** / **<=** -- Menor que / Menor ou igual a

```c
if (quantidade <= 5) {
    printf("Stock Crítico!\n");
} else {
    printf("Stock Normal.\n");
}
```
</details>