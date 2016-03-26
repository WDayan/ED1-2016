#include<stdlib.h>
#include<stdio.h>
#define MAX 5

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;


node *begin();

node *push(int n);

void middlePush(node *q, int n, int position);

node *pop(node *q);

int full(node *q);

int empty(node *q);

void imprimir(node *q);
