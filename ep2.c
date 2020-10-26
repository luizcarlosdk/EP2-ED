#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

int ** alocaMatriz (int lin, int col) {
  int ** mat = malloc (lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int));
  return (mat);
}

void imprimeMatriz (int **a, int m, int n) {
    int i,j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) printf("+---");
        printf("+\n");
        for (j = 0; j <n; j++)
          if(a[i][j] != 0) printf("|%3d", a[i][j]);
            else printf("|   ");
        printf("|\n");
    }
    for (j = 0; j < n; j++) printf("+---");
    printf("+\n");
}

int main(){
  int linha,coluna,valor,QtdPalavras;
  int i,j;

  printf("Por favor, Digite o número de linhas da matriz:\n");
  scanf("%d",&linha);
  printf("Por favor, Digite o número de colunas da matriz:\n");
  scanf("%d",&coluna);

  int ** tabuleiro = alocaMatriz(linha,coluna);

  for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
      printf("Por favor, digite os valores da linha %d coluna %d separados por enter:  \n",i+1,j+1);
      scanf("%d",&valor);
      tabuleiro[i][j] =  valor;
    }
  }

  imprimeMatriz(tabuleiro,linha,coluna);

  printf("Por favor, Digite a quantidade de palavras:");
  scanf("%d",&QtdPalavras);
  getchar();
  palavra** dicionario = malloc(QtdPalavras * sizeof(palavra*));

  
 for(i=0;i<QtdPalavras;i++){
   dicionario[i] = malloc(sizeof(palavra));
   colocapalavra(dicionario[i]);
   colocatamanho(dicionario[i]);
 }
  ordenapalavras(dicionario,QtdPalavras);

 printf("%s\n",dicionario[0]->palavra);
 printf("%s\n",dicionario[1]->palavra);
  printf("Acabou\n");
}
