#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

int ** alocaMatrizInt (int lin, int col) {
  int ** mat = malloc (lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int));
  return (mat);
}

char ** alocaMatrizChar (int lin, int col) {
  char ** mat = malloc (lin * sizeof(char *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(char));
  return (mat);
  
}

int ContaDireta(int ** matriz,int linhaAtual, int ColunaAtual,int ColunaMax){
  int contador = 0;
  while (matriz[linhaAtual][ColunaAtual] != -1 && ColunaAtual < ColunaMax){
    contador++; 
    ColunaAtual++;
  }
  return contador;
}

int ContaAbaixo(int ** matriz,int linhaAtual, int ColunaAtual,int LinhaMax){
  int contador = 0; 
  while (matriz[linhaAtual][ColunaAtual] != -1 && linhaAtual < LinhaMax)
  {
    contador++; 
    linhaAtual++;
  }
  return contador;
}

int contaPalavras(int** matriz,int linhas,int colunas){
  int contador,linhaAtual=0,colunaAtual=0;
  int i,j;
  int ContadorPalavras=0;

  for(linhaAtual=0;linhaAtual < linhas;linhaAtual++){

    for(i=0;i<colunas;i++){
      if(matriz[linhaAtual][i] == 0 && i==colunas-1 && contador>1){
        contador=0;
        ContadorPalavras++;
      }
      else if(matriz[linhaAtual][i] == 0 ){
          contador++;
      }
      else if(matriz[linhaAtual][i] == -1 && contador>1){
        ContadorPalavras++;
        contador = 0;

      }
      else{
        contador = 0;
      }
      
    }
    contador =0;
  }

  contador =0;
  
  for(colunaAtual=0;colunaAtual < colunas;colunaAtual++){

    for(j=0;j<linhas;j++){
      if(matriz[j][colunaAtual] == 0 && j==linhas-1 && contador>=1){
        contador=0;
        ContadorPalavras++;
      }
      else if(matriz[j][colunaAtual] == 0 ){
          contador++;
      }
      else if(matriz[j][colunaAtual] == -1 && contador>1){
        ContadorPalavras++;
        contador = 0;
      }
      else{
        contador = 0;
      }
    }
    printf("To vendo a coluna:%d\n",colunaAtual);
    printf("Valor atual:%d\n",ContadorPalavras);
    contador =0;
  }
  return ContadorPalavras;
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

void imprimeMatrizChar (char **a, int m, int n) {
    int i,j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) printf("+---");
        printf("+\n");
        for (j = 0; j <n; j++)
          if(a[i][j] != 0) printf("|%3c", a[i][j]);
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

  int ** tabuleiro = alocaMatrizInt(linha,coluna);

  for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
      printf("Por favor, digite os valores da linha %d coluna %d separados por enter:  \n",i+1,j+1);
      scanf("%d",&valor);
      tabuleiro[i][j] =  valor;
    }
  }

  imprimeMatriz(tabuleiro,linha,coluna);

  printf("Por favor, Digite a quantidade de palavras:\n");
  scanf("%d",&QtdPalavras);
  getchar();
  palavra** dicionario = malloc(QtdPalavras * sizeof(palavra*));

  
 for(i=0;i<QtdPalavras;i++){
   dicionario[i] = malloc(sizeof(palavra));
   colocapalavra(dicionario[i]);
   colocatamanho(dicionario[i]);
 }
  ordenapalavras(dicionario,QtdPalavras);

  char** tabuleiroResposta = alocaMatrizChar(linha,coluna);

  for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
      if(tabuleiro[i][j] == -1)      
      tabuleiroResposta[i][j] = '*';
      else 
      tabuleiroResposta[i][j] = ' ';
    }
  }


imprimeMatrizChar(tabuleiroResposta,linha,coluna);
 printf("%s\n",dicionario[0]->palavra);
 printf("%s\n",dicionario[1]->palavra);
int totalpalavras = contaPalavras(tabuleiro,linha,coluna);
printf("%d\n",totalpalavras);
printf("Acabou\n");
}
