-----

# Problema das N-Rainhas

Este é um script C++ que implementa o algoritmo de **backtracking** para resolver o clássico **Problema das N-Rainhas**.

O objetivo é posicionar N rainhas em um tabuleiro de xadrez N x N de forma que nenhuma rainha possa atacar a outra (mesma linha, coluna ou diagonal).

## Como Funciona

1.  O programa solicita ao usuário que insira o valor de `N` (o tamanho do tabuleiro).
2.  Ele inicializa um tabuleiro `N x N` vazio (preenchido com 0s).
3.  A função principal `resolverNRainhasRecursivo` é chamada para tentar posicionar as rainhas, uma coluna de cada vez (começando da coluna 0).
4.  Para cada coluna, ela tenta colocar uma rainha em cada linha (`i`).
5.  A função `Verificacao` checa se a posição `(i, col)` é segura, verificando ataques à esquerda (horizontal, diagonal superior e diagonal inferior).
6.  Se for segura, a rainha é "colocada" (`tabuleiro[i][col] = 1`).
7.  A função chama a si mesma recursivamente para a próxima coluna (`col + 1`).
8.  Se a recursão retornar (seja por encontrar uma solução ou um beco sem saída), a rainha é "removida" (`tabuleiro[i][col] = 0`). Isso é o **backtrack**, que permite tentar a próxima linha.
9.  Quando uma solução completa é encontrada (quando `col == N`), ela é impressa pela função `imprimirSolucao`.
10. Ao final, o programa exibe o número total de soluções encontradas.

## Exemplo de Saída (para N = 4)

Ao executar o programa e digitar `4`, a saída será:

```
Digite o valor de N (N>=4): 4

Solucao 1:
. R . . 
. . . R 
R . . . 
. . R . 

Solucao 2:
. . R . 
R . . . 
. . . R 
. R . . 

Total de solucoes encontradas: 2
```
