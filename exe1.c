/*
Desenvolvido por Dayan Roberto Weber
Para a matéria de Estruturas de Dados I - 2016/01
Contato: weber.dayan@gmail.com
Objetivo:
Criar uma matriz, preenche-la com número randômicos;
Imprimir os números, e as posições de memória da matriz.
*/

#include<stdlib.h>
#include<stdio.h>

int main (){
	int linha=5,i,coluna,j;
	int **matriz = (int *)malloc(sizeof(int)*5);

	for(i=0;i < linha; i++){
		coluna = rand()%10;
		matriz[i] = (int *)malloc(coluna*sizeof(int));
		printf("%d ", matriz[i][0]);

		for(j=0;j < coluna; j++){
			matriz[i][j] = rand()%100;
			if(j == 0)
				printf("%d", matriz[i][j]);
			else
				printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
