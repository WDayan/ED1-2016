#include "libDayan.h"

int main(){

	int op, n=0, position;
	node *queueHead = begin();
	node *queue = begin();
	printf("-----------Fila desenvoldida por Dayan Roberto Weber-----------\n");
	do{
		printf("\n\nDigite:\n1) Para insercao\n2) Para remocao\n3) Para verificar se esta cheia\n4) Para verificar se esta vazia\n0) Para sair\n");
		scanf(" %d", &op);

		if(op == 1){
			if(empty(queueHead)){
                printf("\nInsira o numero: ");
                scanf(" %d", &n);
				queueHead = push(n);
				
				if(queueHead == NULL)
            		printf("\nErro na alocacao da Memoria\n\n");
				
				queueHead->prox = begin();
				printf("\nItem adicionado com sucesso\n");
				queue = queueHead;
			}
			else{
				if(full(queueHead))
					printf("\nFila cheia, voce nao pode adicionar novos itens\n");
				else{
					printf("\nDigite uma posicao VALIDA que deseja inserir o numero: ");
					scanf(" %d", &position);
				    printf("\nInsira o numero: ");
                    scanf(" %d", &n);
                    //queue->prox = push(position, n);
					if(position == 0)
						position = 1;
					middlePush(queueHead, n, position);
					
                    if(queue == NULL)
                        printf("\nErro na alocacao da Memoria\n\n");
					
					//queue = queue->prox;
					//queue->prox = begin();
					printf("\nItem adicionado com sucesso\n");
				}
			}
		}

		else if(op == 2){
            if(empty(queueHead))
                printf("\nFila vazia, nao ha o que remover\n");
            else{
                queueHead = pop(queueHead);
				printf("\nItem removido com sucesso\n");
			}

		}

		else if(op == 3){
			if(full(queueHead))
				printf("\nFila esta cheia\n");
			else
				printf("\nFila nao esta cheia\n");
		}

		else if(op == 4){
			if(empty(queueHead))
				printf("\nFila esta vazia\n");
			else
				printf("\nFila nao esta vazia\n");
		}

		else if(op == 5)
			imprimir(queueHead);

		else if(op != 0)
			printf("\nOpcao invalida\nTente novamente\n");

	}while(op != 0);

	return 0;
}



node *begin(){

	return NULL;
}

void middlePush(node *q, int n, int position){
	int i;
	node *new = (node *) malloc(sizeof(node));
	node *aux = q;
	aux->prox = q->prox;
	for(i=1; i < position; i++){
		aux = q;
		aux->prox = q->prox;
		q = q->prox;
	}
	new->prox = aux->prox;
	aux->prox = new;
	new->num = n;

}

node *push( int n){
	node *q = (node *)malloc(sizeof(node));
	if(q == NULL)
		return q;
	
	q->num = n;
	return q;
}

node *pop(node *q){
	if(empty(q))
		return NULL;
	node *aux = begin();
	aux = q->prox;
	free(q);

	return aux;
}

int full(node *q){
	int i;
	for(i=0; q != NULL; i++)
		q = q->prox;

	if(i == MAX)
		return 1;

	return 0;
}

int empty(node *q){
	if(q == NULL)
		return 1;

	return 0;
}

void imprimir(node *q){
	if(q == NULL){
        printf("\nNao ha ninguem para impressao aqui\n");
		return;
	}
	printf("\nNa fila: ");
	while(q != NULL){
		printf("%d  ", q->num);
		q = q->prox;
	}
	printf("\n");

	return;
}
