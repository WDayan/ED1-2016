/*
Desenvolvido por Dayan Roberto Weber
Para a matéria de Estruturas de Dados I - 2016/01
Contato: weber.dayan@gmail.com
Objetivo:
Função que une dois vetores e depois imprime a união.
Depois imprimi-los.
*/
#include<stdlib.h>
#include<stdio.h>

int *uniao(int *v1, int n1, int *v2, int n2){

	int *v3 = (int *)malloc(sizeof(int)*(n1+n2));
	int i=0,x=0;

	while(i < n1){
		*(v3+i) = *(v1+i);
		i++;
	}
	while(x < n2){
		*(v3+i) = *(v2+x);
		x++;
		i++;
	}

	return v3;
}



int main(){
	int v1[4] = {11,13,45,7};
	int v2[6] = {24,4,16,81,10,12};
	int n1=4, n2=6, *p=NULL;
	int x=n1+n2,i=0;

	p = uniao(v1, n1, v2, n2);

	while(i < x){
        printf("%d\n", *(p+i));
        i++;
	}

	free(p);

	return 0;
}