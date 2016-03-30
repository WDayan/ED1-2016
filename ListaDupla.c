#include "listDupla.h"


int main(){

	TpListaDupla *head= begin(),*body = begin();
	int op, n;

	printf("-----------Fila Dupla desenvoldida por Dayan Roberto Weber-----------\n");
	do{
		printf("\n\nDigite:\n1) Para insercao\n2) Para remocao\n3) Para verificar se esta cheia\n4) Para verificar se esta vazia\n5) Para imprimir\n0) Para sair\n");
		scanf(" %d", &op);

		if(op == 1){ //Caso deseje inserir novo numero
			if(empty(head)){ //Sempre quando for a primeira vez deve ser inserido na cabeca HEAD
                printf("\nInsira o numero: ");
                scanf(" %d", &n);
				head = push(NULL, n);
				
				if(head == NULL)
            		printf("\nErro na alocacao da Memoria\n\n");
				
				head->prox = begin();
				printf("\nItem adicionado com sucesso\n");
				body = head; //O corpo (body) recebendo o espaço alocado para a cabeca, agora apenas trabalhar com ele!
			}
			else{
				if(full(head)) //Caso esteja cheia nao posso inserir novos itens
					printf("\nFila cheia, voce nao pode adicionar novos itens\n");
				else{
				    printf("\nInsira o numero: ");
                    scanf(" %d", &n);
                    body->prox = push(body, n); //Inserindo novo item, fazendo a calda andar, passando o ponteiro atual em *anterior
					
                    if(body == NULL)
                        printf("\nErro na alocacao da Memoria\n\n");
					
					body = body->prox; //Fazendo a calda andar
					body->prox = begin();
					printf("\nItem adicionado com sucesso\n");
				}
			}
		}

		else if(op == 2){ //Caso a fila esteja vazia nao posso remover nada!
            if(empty(head))
                printf("\nFila vazia, nao ha o que remover\n");
            else{
                head = pop(head); //Se nao, removo o primeiro item!
				printf("\nItem removido com sucesso\n");
			}

		}

		else if(op == 3){ //Testando se a fila esta cheia
			if(full(head))
				printf("\nFila esta cheia\n");
			else
				printf("\nFila nao esta cheia\n");
		}

		else if(op == 4){ //Testando se a fila esta vazia
			if(empty(head))
				printf("\nFila esta vazia\n");
			else
				printf("\nFila nao esta vazia\n");
		}

		else if(op == 5) //Imprimindo os valores da FILA
			print(head);

		else if(op != 0)
			printf("\nOpcao invalida\nTente novamente\n");

	}while(op != 0);

	return 0;
}




TpListaDupla *begin(){

	return NULL;
}

TpListaDupla *push(TpListaDupla *anterior, int num){

	TpListaDupla *ld = (TpListaDupla*) malloc(sizeof(TpListaDupla)); //Alocando novo espaço de memória

	if(ld == NULL)
		return NULL;

	ld->ant = anterior; //Recebendo o ponteiro anterior
	ld->prox = begin();//Setando para NULL o próximo ponteiro
	ld->info = num; //Salvando o valor 

	return ld;
}

TpListaDupla *pop(TpListaDupla *head){
	

	TpListaDupla *ld; //Ponteiro auxiliar
	
	ld = head->prox; //Recebendo o proximo da fila
	if(ld != NULL)
		ld->ant = begin(); //Caso nao exista proximo, nao existe espaco alocado para o anterior
	free(head); //free na cabeça
	
	return ld;
}

int full(TpListaDupla *head){
	int i;
	for(i=0; head != NULL; i++) //contador.. se existirem 5 proximo está cheio
		head = head->prox;

	if(i == MAX)
		return 1;

	return 0;


}

int empty(TpListaDupla *head){
	if(head == NULL) //caso a cabeca seja NULL não ha nenhum elemento!
		return 1;
	return 0;
}


void print(TpListaDupla *head){
	TpListaDupla *aux;
	if(head == NULL){
		printf("\nNao ha nada para imprimir\n\n");
		return ;
	}

	printf("\nModo Normal: ");
	while(head != NULL){
		if(head->prox == NULL)
			aux = head;	//Salvando para depois imprimir invertido haha

		printf("%d ", head->info);
		head = head->prox; //Pegando o proxima da fila
	}

	printf("\nModo com Emocao: "); //Imprimindo em ordem inversa
	while(aux != NULL){
	
		printf("%d ", aux->info);
		aux = aux->ant;
	}
	printf("\n");

	return;
}
