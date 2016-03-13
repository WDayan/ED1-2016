/*
Desenvolvido por Dayan Roberto Weber
Para a matéria de Estruturas de Dados I - 2016/01
Contato: weber.dayan@gmail.com
Objetivo:
Ler números inteiros até que o usuário digite uma letra.
Depois imprimi-los.
*/

#include<stdlib.h>
#include<stdio.h>



int main(){
	int *p = NULL, i=0, count=0;

	p = (int *)malloc(sizeof(int)*5);

	while(scanf(" %d", *(p+i)) == 1){

		if(count == 4){
			p = realloc(p, sizeof(int)*5);
          	count=-1;
		}
		i++;
		count++;
	}

	count = 0;
	while(count < i){
        printf("%d\n", *(p+count));
        count++;
	}

	return 0;
}
