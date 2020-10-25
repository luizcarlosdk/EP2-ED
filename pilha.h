#include <stdio.h>

typedef int item;

typedef struct {
  item * v;
  int topo;
  int tam;
} pilha;

typedef struct{
  char* palavra;
  int tamanho
} palavra;

pilha * criaPilha (int tam);
void destroiPilha (pilha * p);
void empilha (pilha * p, item x);
item desempilha (pilha * p);
int pilhaVazia (pilha * p);
item topoDaPilha (pilha *p);
pilha * aumentaPilha (pilha * p); 