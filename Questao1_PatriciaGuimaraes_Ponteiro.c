//1. Fa�a um programa em C que armazene em um vetor 3 valores, e imprima os valores
//utilizando nota��o de ponteiro.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(){
	int v[3];
	int i;
	
	for(i=0; i<3; i++){
		printf("Digite os valores: \n");
		scanf("%d", v+i);//aqui ele t� salvando o endere�o // scanf("%i", &v[i]);
		printf("Valor impresso:\n");
		printf("%d\n", *(v+i));// para imprimir o conte�do o valor, aponta o conte�do da vari�vel v - antes era ("%i", vetor[i])
		printf("Endereco: %x - Valor: %d\n", v+i, *(v+i));
	}
	return 0;
}

