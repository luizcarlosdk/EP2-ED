#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


int verifica(int tamanho, palavra **Dicionario, int indice){
  if(Dicionario[indice]->tamanho == tamanho && Dicionario[indice]->disponibilidade == 1){
    return 1;
  }
  else
  {
    return 0;
  }
}
int **alocaMatrizInt(int lin, int col)
{
  int **mat = malloc(lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc(col * sizeof(int));
  return (mat);
}

char **alocaMatrizChar(int lin, int col)
{
  char **mat = malloc(lin * sizeof(char *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc(col * sizeof(char));
  return (mat);
}

int ContaDireta(char **matriz, int linhaAtual, int ColunaAtual, int ColunaMax)
{
  int contador = 0;
  while (matriz[linhaAtual][ColunaAtual] != '*' || ColunaAtual < ColunaMax)
  {
    contador++;
    ColunaAtual++;
  }
  return contador;
}

int ContaAbaixo(char **matriz, int linhaAtual, int ColunaAtual, int LinhaMax)
{
  int contador = 0;
  while (matriz[linhaAtual][ColunaAtual] != '*' && linhaAtual < LinhaMax)
  {
    contador++;
    linhaAtual++;
  }
  return contador;
}

int contaPalavras(int **matriz, int linhas, int colunas)
{
  int contador, linhaAtual = 0, colunaAtual = 0;
  int i, j;
  int ContadorPalavras = 0;

  for (linhaAtual = 0; linhaAtual < linhas; linhaAtual++)
  {

    for (i = 0; i < colunas; i++)
    {
      if (matriz[linhaAtual][i] == 0 && i == colunas - 1 && contador > 1)
      {
        contador = 0;
        ContadorPalavras++;
      }
      else if (matriz[linhaAtual][i] == 0)
      {
        contador++;
      }
      else if (matriz[linhaAtual][i] == -1 && contador > 1)
      {
        ContadorPalavras++;
        contador = 0;
      }
      else
      {
        contador = 0;
      }
    }
    contador = 0;
  }

  contador = 0;

  for (colunaAtual = 0; colunaAtual < colunas; colunaAtual++)
  {

    for (j = 0; j < linhas; j++)
    {
      if (matriz[j][colunaAtual] == 0 && j == linhas - 1 && contador >= 1)
      {
        contador = 0;
        ContadorPalavras++;
      }
      else if (matriz[j][colunaAtual] == 0)
      {
        contador++;
      }
      else if (matriz[j][colunaAtual] == -1 && contador > 1)
      {
        ContadorPalavras++;
        contador = 0;
      }
      else
      {
        contador = 0;
      }
    }
    printf("To vendo a coluna:%d\n", colunaAtual);
    printf("Valor atual:%d\n", ContadorPalavras);
    contador = 0;
  }
  return ContadorPalavras;
}

void imprimeMatriz(int **a, int m, int n)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      printf("+---");
    printf("+\n");
    for (j = 0; j < n; j++)
      if (a[i][j] != 0)
        printf("|%3d", a[i][j]);
      else
        printf("|   ");
    printf("|\n");
  }
  for (j = 0; j < n; j++)
    printf("+---");
  printf("+\n");
}

void imprimeMatrizChar(char **a, int m, int n)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      printf("+---");
    printf("+\n");
    for (j = 0; j < n; j++)
      if (a[i][j] != 0)
        printf("|%3c", a[i][j]);
      else
        printf("|   ");
    printf("|\n");
  }
  for (j = 0; j < n; j++)
    printf("+---");
  printf("+\n");
}

void PalavrasCruzadas(char **tabuleiroResposta, int linhaMax, int colunaMax, int total, palavra **Dicionario, int PalavrasDisponiveis)
{
  pilha *decisao = criaPilha(total);
  int palavras = 0; // Variavel para guardar o total de palavras
  int vertical = 0, horizontal = 0; //controlar o while do vertical
  int indicepalavra = 0;            //indice da palavra atual no vetor
  int linhaAtual = 0, colunaAtual = 0;
  int tamanho;
  pulaPalavra atual;
  int ok;

  while (palavras < total)
  {

    while (horizontal == 0)
    { //Loop para manter na horizontal.
      while (linhaAtual < linhaMax)
      { //
        if (colunaAtual < colunaMax)
        { // Decidir quando trocar a linha

          if (tabuleiroResposta[linhaAtual][colunaAtual] == '*')
          {
            colunaAtual++;
          }

          ok = 0;
          tamanho = ContaDireta(tabuleiroResposta, linhaAtual, colunaAtual, colunaMax);
          while (!ok && indicepalavra < PalavrasDisponiveis)
          {
            if (verifica(tamanho, Dicionario, indicepalavra))
              ok = 1;
            else
              indicepalavra++;
          }

          if (ok)
          {
            empilha(decisao, atual);
            colunaAtual = colunaAtual + tamanho;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra=0; //começa a comparar a partir do começo no novo bloco de palavra
            palavras++;
          }
          else
          { /* backtrack */
            if (pilhaVazia(decisao))
            {
              destroiPilha(decisao);
              printf("Esti é o valor :%d",indicepalavra);
              printf("Não há solução.");
              return;
            }
            atual = desempilha(decisao);
            colunaAtual = atual.coluna;
            linhaAtual = atual.linha;
            indicepalavra = atual.indice;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra++;
            palavras--;
          }
        }
        else
        {
          linhaAtual++;
          colunaAtual=0;
        }
        

        
      }
      horizontal = 1;
    }
      vertical = 0;
      while (vertical == 0)
      {
        while (colunaAtual < colunaMax)
      { //
        if (linhaAtual < linhaMax)
        { // Decidir quando trocar a linha

          if (tabuleiroResposta[linhaAtual][colunaAtual] == '*')
          {
            linhaAtual++;
          }

          ok = 0;
          tamanho = ContaAbaixo(tabuleiroResposta, linhaAtual, colunaAtual, linhaMax);
          while (!ok && indicepalavra < PalavrasDisponiveis)
          {
            if (verifica(tamanho, Dicionario, indicepalavra))
              ok = 1;
            else
              indicepalavra++;
          }

          if (ok)
          {
            empilha(decisao, atual);
            linhaAtual = linhaAtual + tamanho;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra=0; //começa a comparar a partir do começo no novo bloco de palavra
            palavras++;
          }
          else
          { /* backtrack */
            if (pilhaVazia(decisao))
            {
              destroiPilha(decisao);
              printf("O indice da palavra é = %d",indicepalavra);
              printf("Não há solução.");
              return;
            }
            atual = desempilha(decisao);
            colunaAtual = atual.coluna;
            linhaAtual = atual.linha;
            indicepalavra = atual.indice;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra++;
            palavras--;
          }
        }
        else
        {
          linhaAtual++;
          colunaAtual=0;
        }
      }
      vertical = 1;
      printf("Acabou xD\n");
      }
    
  }
    //imprimeMatrizChar(tabuleiroResposta);
    destroiPilha(decisao);
}

  int main()
  {
    int linha, coluna, valor, QtdPalavras;
    int i, j;

    printf("Por favor, Digite o número de linhas da matriz:\n");
    scanf("%d", &linha);
    printf("Por favor, Digite o número de colunas da matriz:\n");
    scanf("%d", &coluna);

    int **tabuleiro = alocaMatrizInt(linha, coluna);

    for (i = 0; i < linha; i++)
    {
      for (j = 0; j < coluna; j++)
      {
        printf("Por favor, digite os valores da linha %d coluna %d separados por enter:  \n", i + 1, j + 1);
        scanf("%d", &valor);
        tabuleiro[i][j] = valor;
      }
    }

    imprimeMatriz(tabuleiro, linha, coluna);

    printf("Por favor, Digite a quantidade de palavras:\n");
    scanf("%d", &QtdPalavras);
    getchar();
    palavra **dicionario = malloc(QtdPalavras * sizeof(palavra *));

    for (i = 0; i < QtdPalavras; i++)
    {
      dicionario[i] = malloc(sizeof(palavra));
      colocapalavra(dicionario[i]);
      colocatamanho(dicionario[i]);
    }
    ordenapalavras(dicionario, QtdPalavras);

    char **tabuleiroResposta = alocaMatrizChar(linha, coluna);

    for (i = 0; i < linha; i++)
    {
      for (j = 0; j < coluna; j++)
      {
        if (tabuleiro[i][j] == -1)
          tabuleiroResposta[i][j] = '*';
        else
          tabuleiroResposta[i][j] = ' ';
      }
    }

    imprimeMatrizChar(tabuleiroResposta, linha, coluna);
    printf("%s\n", dicionario[0]->palavra);
    printf("%s\n", dicionario[1]->palavra);
    int totalpalavras = contaPalavras(tabuleiro, linha, coluna);
    printf("%d\n", totalpalavras);
    PalavrasCruzadas(tabuleiroResposta,linha,coluna,totalpalavras,dicionario,QtdPalavras);
    printf("Acabou\n");
    return 0;
  }
