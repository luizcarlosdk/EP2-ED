#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void imprimepalavraHorizontal(char **tabuleiro, palavra** Dicionario,int linha,int coluna,int indice,int tamanho){
  int i;

  for (i=0; i < tamanho; i++)
  {
    tabuleiro[linha][coluna+i] = Dicionario[indice]->palavra[i];
  }
  
}

void imprimepalavraVertical(char **tabuleiro, palavra** Dicionario,int linha,int coluna,int indice,int tamanho){
  int i;

  for (i=0; i < tamanho; i++)
  {
    tabuleiro[linha+i][coluna] = Dicionario[indice]->palavra[i];
  }
  
}

int VerificaVertical(char** tabuleiro, int tamanho, palavra **Dicionario, int indice,int linha, int coluna){
  int i;
  for (i = 0; i < tamanho; i++)
  {
    if(tabuleiro[linha+i][coluna] != Dicionario[indice]->palavra[i] && tabuleiro[linha+i][coluna] != ' '){
      return 0;
    }
  }
  return 1;
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

void liberaMatrizInt (int ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++) free(mat[i]);
  free (mat);
}

void liberaMatrizChar (char ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++) free(mat[i]);
  free (mat);
}

int ContaDireta(char **matriz, int linhaAtual, int ColunaAtual, int ColunaMax)
{
  int contador = 0;
  while (matriz[linhaAtual][ColunaAtual] != '*' && ColunaAtual < ColunaMax)
  {
    contador++;
    ColunaAtual++;
  }
  return contador;
}

int ContaAbaixo(char **matriz, int linhaAtual, int ColunaAtual, int LinhaMax)
{
  int contador = 0;
  while (linhaAtual < LinhaMax && matriz[linhaAtual][ColunaAtual] != '*')
  {
    contador++;
    linhaAtual++;
  }
  return contador;
}

int contaPalavras(int **matriz, int linhas, int colunas)
{
  int contador=0, linhaAtual = 0, colunaAtual = 0;
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
  int palavras = 0; 
  int vertical = 0, horizontal = 0; 
  int indicepalavra = 0;
  int linhaAtual = 0, colunaAtual = 0;
  int tamanho=0;
  pulaPalavra atual;
  int ok;

  while (palavras < total)
  {

    while (horizontal == 0)
    {
      while (linhaAtual < linhaMax)
      { 
        if (colunaAtual < colunaMax)
        { 

         if (ContaDireta(tabuleiroResposta, linhaAtual, colunaAtual, colunaMax) < 1) 
          {
            colunaAtual++;
          }
          else{
             ok = 0;
          tamanho = ContaDireta(tabuleiroResposta, linhaAtual, colunaAtual, colunaMax);
          while (!ok && indicepalavra < PalavrasDisponiveis && tamanho>1)
          {
            if (Dicionario[indicepalavra]->tamanho == tamanho && Dicionario[indicepalavra]->disponibilidade == 1){
              ok = 1;
            }
              
            else{
              indicepalavra++;
            }
              
          }

          if (ok)
          {
            atual.linha = linhaAtual;
            atual.coluna = colunaAtual;
            atual.indice = indicepalavra;
            atual.leitura = horizontal;
            Dicionario[indicepalavra]-> disponibilidade = 0;
            empilha(decisao, atual);
            
            palavras = palavras+1;
            imprimepalavraHorizontal(tabuleiroResposta,Dicionario,linhaAtual,colunaAtual,indicepalavra,tamanho);
            colunaAtual = colunaAtual + tamanho;
            indicepalavra=0;
            
          }
          else
          { 
            if (pilhaVazia(decisao) && tamanho > 1)
            {
              destroiPilha(decisao);
              printf("Não há solução.\n");
              return;
            }
            else if(tamanho > 1){
            atual = desempilha(decisao); 
            colunaAtual = atual.coluna;
            linhaAtual = atual.linha;
            indicepalavra = atual.indice;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra++;
            palavras = palavras-1;
            }
            else
            {
              colunaAtual++;
              indicepalavra = 0;
            }
            
          }
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
      linhaAtual=0;
      colunaAtual=0;
      while (vertical == 0)
      {
        while (colunaAtual < colunaMax && horizontal == 1)
      { 
        if (linhaAtual < linhaMax && horizontal == 1)
        {
          if (ContaAbaixo(tabuleiroResposta, linhaAtual, colunaAtual, linhaMax) < 1) 
          {
            linhaAtual++;
          }
          else{
            ok = 0;
          tamanho = ContaAbaixo(tabuleiroResposta, linhaAtual, colunaAtual, linhaMax);
          while (!ok && indicepalavra < PalavrasDisponiveis)
          {
            if (Dicionario[indicepalavra]->tamanho == tamanho && Dicionario[indicepalavra]->disponibilidade == 1){
              if(VerificaVertical(tabuleiroResposta,tamanho,Dicionario,indicepalavra,linhaAtual,colunaAtual)){
              ok = 1;
              }
              else{
                indicepalavra++;
              }
              
            }
              
            else
              indicepalavra++;
          }

          if (ok)
          {
            atual.linha = linhaAtual;
            atual.coluna = colunaAtual;
            atual.indice = indicepalavra;
            atual.leitura = horizontal;
            Dicionario[indicepalavra]-> disponibilidade = 0;
            empilha(decisao, atual);
            
            palavras = palavras+1;
            linhaAtual = linhaAtual + tamanho;
            
            indicepalavra=0; 
            
          }
          else
          { 
            if(tamanho > 1){
            atual = desempilha(decisao); 
            colunaAtual = atual.coluna;
            linhaAtual = atual.linha;
            indicepalavra = atual.indice;
            horizontal = atual.leitura;
            Dicionario[indicepalavra]-> disponibilidade = 1;
            indicepalavra++;
            palavras = palavras-1;
              if(horizontal == 0){
                vertical = 1;
              }
            }
            else
            {
              linhaAtual++;
              indicepalavra=0;
            }
            
          }
          }

          
        }
        else
        {
          linhaAtual=0;
          colunaAtual++;
        }
      }
      vertical = 1;
      }
  }
    while(atual.leitura == 1){
      atual = desempilha(decisao);
      tamanho = ContaAbaixo(tabuleiroResposta,atual.linha,atual.coluna,linhaMax);
      imprimepalavraVertical(tabuleiroResposta,Dicionario,atual.linha,atual.coluna,atual.indice,tamanho);

    }
    imprimeMatrizChar(tabuleiroResposta,linhaMax,colunaMax);
    destroiPilha(decisao);
}

  int main()
  {
    int linha, coluna, valor, QtdPalavras,instancias,totalpalavras;
    int i, j,k;
    int **tabuleiro;
    palavra **dicionario;
    char **tabuleiroResposta;
    printf("Por favor, digite o número de instâncias:\n");
    scanf("%d",&instancias);
    for (k = 0; k < instancias; k++)
    {
    printf("Instância %d :\n",k+1);
    scanf("%d", &linha);
    scanf("%d", &coluna);

    tabuleiro = alocaMatrizInt(linha, coluna);

    for (i = 0; i < linha; i++)
    {
      for (j = 0; j < coluna; j++)
      {
        scanf("%d", &valor);
        tabuleiro[i][j] = valor;
      }
    }
    scanf("%d", &QtdPalavras);
    getchar();
    dicionario = malloc(QtdPalavras * sizeof(palavra *));

    for (i = 0; i < QtdPalavras; i++)
    {
      dicionario[i] = malloc(sizeof(palavra));
      colocapalavra(dicionario[i]);
      colocatamanho(dicionario[i]);
      dicionario[i]->disponibilidade=1;
    }
    ordenapalavras(dicionario, QtdPalavras);

    tabuleiroResposta = alocaMatrizChar(linha, coluna);

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
    totalpalavras = contaPalavras(tabuleiro,linha,coluna);
    PalavrasCruzadas(tabuleiroResposta,linha,coluna,totalpalavras,dicionario,QtdPalavras);
    destroiDicionario(dicionario,QtdPalavras);
    liberaMatrizInt(tabuleiro,linha);
    liberaMatrizChar(tabuleiroResposta,linha);
    }
    return 0;
  }
