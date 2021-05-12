/*1. Considerando o conjunto de dados abaixo para criação da estrutura, crie um programa em C
que leia o preço, o nome e as baixas de todos os dias de todos os produtos e armazene em uma
lista encadeada simples, após percorra a estrutura de dados e verifique qual foi o produto que
teve mais baixa, ou seja, que foi mais vendido. Ao final, mostre o nome e quantas unidades deste
produto foram vendidas. A estrutura deve conter: código, nome, preço, baixa como uma matriz
4X6, onde o 4 representa as semanas e o 6 cada dia da semana (segunda a sábado)*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<locale.h>
//Não está rodando corretamente
typedef struct venda vendas;
struct venda{
	int codigo;
	char nome[20];
	double valor;
	int qtdVendasMensais[1][2];
	vendas *proximo;//ponteiro que vai guarda endereço do proximo elemento
	
};
vendas* inicializar();
void menu();
vendas *inserir(vendas *vendasMes);
void produtoMaisVendido(vendas *vendasMes);


int main(){

	//produtosVendidos vendas[10]; se fosse vetor seria assim
	vendas *vendasMes; //criar uma lista do tipo venda
	int opcao, opcao2;

	vendasMes = inicializar();
	do{
        menu();
        scanf("%d", &opcao);
            switch(opcao){
                case 1: vendasMes = inserir(vendasMes); break;
                case 2: produtoMaisVendido(vendasMes); break;
                case 3: return 0;
                default: printf("Codigo invalido!");
            }
//outra opcao            
/*        printf("Deseja realizar uma nova operacao? Sim, para continuar");   
        scanf("%s", &opcao2);
    }while (strcmp(opcao2,"Sim")==0);*/

	    printf("Deseja realizar uma nova operacao? Digite 1 - se sim.");   
	    scanf("%d", &opcao2);
    }while (opcao2==1);
	
	return 0;
}

vendas* inicializar(){
	return NULL;
}

void menu(){
	printf("\nMENU\n1 - Inserir vendas da semana\n 2- Verificar produto com maior venda\n 3 - Sair\n");
}

vendas *inserir(vendas *vendasMes){
	int i, j;
	vendas* novo = (vendas*) malloc(sizeof(vendasMes));//espaço da memória alocado dinamicamente.
	
	printf("Digite o codigo do produto: ");
	scanf("%d", &novo->codigo);
	fflush(stdin);
	
	printf("Nome do produto:");
	fgets(novo->nome, 20, stdin);
	fflush(stdin);
	
	printf("Valor do produto R$:");
	scanf("%f", &novo->valor);
	fflush(stdin);
	
	for(i=0; i<1; i++)	{
		for(j=0; j<2; j++){
			printf("Digite a quantidade de produto vendido %d - %d:", i, j);
			scanf("%d", &novo->qtdVendasMensais[i][j]);
			fflush(stdin);
		}
	}
	
	//continuar o preenchimento da struct
	novo->proximo = vendasMes;//nesse estrutura preenche todos os dados 
	
	return novo;//retorna o item da lista preenchido
}

void produtoMaisVendido(vendas *vendasMes){
	int soma, i, j, maiorVendas=0, codigoMaiorVenda;
	vendas *aux;
	
	if(vendasMes == NULL){
	
		printf("Nao foram realizadas vendas!\n");
	}else{
		
		for(aux=vendasMes; aux!=NULL; aux=aux->proximo){//percorrer a lista por isso criou uma lista auxiliar
				soma = 0;//inicializa soma aqui pq cada vez que andar zera.
			for(i=0; i<1; i++)	{
				for(j=0; j<2; j++){
					soma = soma + aux->qtdVendasMensais[i][j];//percorrer a matriz pra somar qtde de vendas
				}
			}
			if(soma > maiorVendas){
				maiorVendas = soma;
				codigoMaiorVenda = aux->codigo;
			}
		}
	}
	printf("Produto mais vendido----\n");
	for(aux=vendasMes; aux!=NULL; aux=aux->proximo){
		if(codigoMaiorVenda == aux->codigo){
			printf("Codigo: %d\n", aux->codigo);
			printf("Produto: %s\n", aux->nome);
			printf("Quantidade de vendas: %d\n", maiorVendas);
		}
	}
}


