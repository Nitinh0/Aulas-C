
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


### 📙 VOLUME 2: Escala e Automação (Aulas 5 a 6)
<details>

<summary><b>Este volume marca a transição de escrever linhas repetidas para ensinar o computador a trabalhar por ti.</b></summary>

### 5. Arrays (Listas de Variáveis)
Em vez de criar custo1, custo2 e custo3, cria-se um contentor com várias posições.
-   **double custos[3];** -- Cria espaço para 3 números.
    > **Atenção:** Em C, as posições começam sempre no zero! (Ou seja: custos[0], custos[1], custos[2]).

### 6. O Ciclo for

A melhor ferramenta para percorrer Arrays. Tem 3 regras: Início, Fim e Incremento.  
```c
for (size_t i = 0; i < 3; i++) {  
	printf("Posicao %d\n", i);  
}
```
> **Nota Profissional:** Usar size_t em vez de int para a variável i protege o teu código, impedindo que o ciclo tente ler posições negativas de memória por acidente.
</details>

### 📕 VOLUME 3: Domínio do Texto e Arquitetura (Aulas 7 a 9)
<details>
<summary><b>Onde a programação se cruza com o mundo real (nomes de aplicações, caminhos de pastas e menus interativos).</b></summary>

### 7. Strings (O Texto em C)
Em C, as palavras não são mais do que Arrays de letras (caracteres).
- **char nome[50];** -- Cria espaço para uma palavra até 49 letras (+1 terminador invisível \0).
- A Exceção do &: No scanf para ler texto (com o marcador %s), não se usa o &. **O próprio nome do array já representa a sua memória**.
- 
### 8. Textos com Espaços e o fgets
O scanf tradicional não consegue ler frases com espaços (ex: "Program Files"). A alternativa profissional é o **fgets**.

-   Sintaxe: **fgets(nomePasta, 300, stdin);**    
-   O Problema da Tesoura: O fgets guarda acidentalmente o "Enter" (\n) que digitas no teclado.    
-   A Solução (**strcspn**): Importamos a **<string.h>** e ordenamos ao C que encontre a posição do **\n** e o substitua por **\0** (Fim do texto).
```c
nomePasta[strcspn(nomePasta, "\n")] = '\0';
```

### 9. Matrizes (Arrays 2D) e Choques de Memória
-   Arrays de Texto: Para guardar uma lista de nomes, juntamos duas dimensões. Ex: **char listaApps[3][50];** (3 apps, até 50 letras cada). Para ler/gravar, usas apenas listaApps[i].
    
#### O Choque Mortal (scanf vs fgets):
-   O que acontece: Se usares um **scanf** para ler um menu (ex: opção 1) e logo a seguir o código tentar ler um texto com **fgets**, o fgets vai encravar porque encontra o "Enter" fantasma deixado para trás pelo scanf.
    
- **A Cura:** Usar sempre a função **getchar();** imediatamente após um scanf para "limpar" o buffer do teclado antes de chamar um **fgets**.

</details>