#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

/*  4. Crie uma função que aceite como parâmetro um vetor de inteiros com N valores, e 
determina o maior elemento do vetor e o número de vezes que este elemento ocorreu no 
vetor. Por exemplo, para um vetor com os seguintes elementos: 3, 5, 12, 6, 7, 27, 9, 16, 
27, a função deve retorna para o programa que a chamou o valor 27 e o número 2 
(indicando que o número 27 ocorreu 2 vezes). A função deve ser do tipo void.   */

#define MAX 5

void incluirInteiros(int *vetor);
void procurarMaiorValor( int *vetor);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[MAX], valorIgual;
	int qtde;

	incluirInteiros(vetor);
    procurarMaiorValor (vetor);
     
    return 0;
}

void incluirInteiros(int *vetor){
	int i;
	char continuar;
	
	for(i=0; i<MAX; i++){
	printf("Digite o %iº valor:", i+1);
	scanf("%i", &vetor[i]);
	fflush(stdin);
	}
}

void procurarMaiorValor ( int *vetor){
	int i, count = 0;
	int maiorValor=vetor[0];
	for(i=0; i<MAX; i++){
		if(vetor[i] >= maiorValor){
			maiorValor = vetor[i];
			count++;
		}
	}
	puts("----Valores Digitados----");
	printf("\nMaior valor: %i \n", maiorValor);
	printf("Quantidade: %d ", count);

}

