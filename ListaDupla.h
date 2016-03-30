#include<stdlib.h>
#include<stdio.h>
#define MAX 5

//Lista Encadeada
struct listaDupla{
	int info;
	struct listaDupla *ant;
	struct listaDupla *prox;
};
typedef struct listaDupla TpListaDupla;

//Funcoes para Lista Dupla

TpListaDupla *begin();

TpListaDupla *push(TpListaDupla *anterior, int num);

TpListaDupla *pop(TpListaDupla *head);

int full(TpListaDupla *head);

int empty(TpListaDupla *head);

void print(TpListaDupla *head);
