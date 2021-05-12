/*2. Crie uma estrutura para descrever restaurantes. Os membros devem armazenar o nome, o
endereço, o preço médio e o tipo de comida. Crie uma lista simples encadeada e escreva um
programa que utilize uma função para solicitar os dados de um elemento da lista e outra para
listar todos os dados.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<locale.h>


//prof colocou no github

typedef struct endereco end;
struct endereco{
	char rua[30];
	char cidade[20];
};

typedef struct comercio restaurantes;
struct comercio{
	char nome[20];
	float precoMedio;
	char tipoComida[20];
	end endereco;
	restaurantes *proximo;//ponteiro que vai guarda endereço do proximo elemento
	
};

restaurantes *inicializar();
void menu();
restaurantes *inserir(restaurantes *cadRestaurantes);
void listarRestaurantes(restaurantes *cadRestaurantes);


int main(){
	restaurantes *cadRestaurantes;
	int opcao;
	cadRestaurantes = inicializar();
	do{
        menu();
        scanf("%d", &opcao);
        fflush(stdin);
            switch(opcao){
                case 1:
               		cadRestaurantes = inserir(cadRestaurantes);
                break;
                
                case 2:
                    listarRestaurantes(cadRestaurantes);
                break;
                
                case 3:
                    return 0;
                break;
                
                default: printf("Codigo invalido!");
            }
//        printf("Deseja realizar uma nova operacao? Digite o numero 1 para sim: ");   
//        fflush(stdin);
//        scanf("%i", &opcao2);
    }while (opcao!=0);	
	
}

restaurantes *inicializar(){
	return NULL;
}

void menu(){
	printf("1 - Inserir restaurante\n 2 - Listar cadastro dos Restaurantes\n 3 - Sair\n");
	
}

restaurantes *inserir(restaurantes *cadRestaurantes){
	restaurantes *novo = (restaurantes*) malloc(sizeof(cadRestaurantes));

		printf("Informe nome do restaurante: ");
		fgets(novo->nome, 20, stdin);//Como nome tem espaços não pode scanf
		
		printf("Informe o tipo da comida:");
		fgets(novo->tipoComida, 20, stdin);
		
		printf("Informe o preco medio: ");
		scanf("%f", &novo->precoMedio);
		fflush(stdin);	
		
		printf("Informe o endereco - Rua: ");
		fgets(novo->endereco.rua, 30, stdin);//Como nome tem espaços não pode scanf
		
		printf("Informe a cidade: ");
		fgets(novo->endereco.cidade, 20, stdin);//Como nome tem espaços não pode scanf
	
		novo->proximo = cadRestaurantes;
			
	return novo;
}

void listarRestaurantes(restaurantes *cadRestaurantes){
	restaurantes *aux;
	if(cadRestaurantes != NULL){
		for(aux=cadRestaurantes; aux!=NULL; aux=aux->proximo){
			printf("Restaurante: %s\t", aux->nome);
			printf("Endereco: Rua %s - Cidade %s\t", aux->endereco.rua, aux->endereco.cidade);
			printf("Tipo de comida: %s\t", aux->tipoComida);
			printf("Valor medio do cardapio: %.2f", aux->precoMedio);
		}		
	}else{
		printf("Nenhum cadastro foi realizado.");
	}	
}


