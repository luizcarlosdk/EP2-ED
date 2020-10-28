#include <stdio.h>

typedef struct{
  int linha;
  int coluna;
  int indice;
  int leitura; //Define a direção no qual será feita a leitura, ajudará a controlar os while.
}pulaPalavra;

typedef pulaPalavra item;

typedef struct {
  item * v;
  int topo;
  int tam;
} pilha;

typedef struct{
  char* palavra;
  int tamanho;
  int disponibilidade;
} palavra;

void troca(palavra **v, int i, int j);
void ordenapalavras(palavra **p,int n);
void colocapalavra(palavra *p);
void colocatamanho(palavra *p);
pilha * criaPilha (int tam);
void destroiPilha (pilha * p);
void empilha (pilha * p, item x);
item desempilha (pilha * p);
int pilhaVazia (pilha * p);
item topoDaPilha (pilha *p);
pilha * aumentaPilha (pilha * p); 