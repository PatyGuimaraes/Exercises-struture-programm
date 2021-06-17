/*4 – Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo 
com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo 
do segundo).*/

#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp1, *fp2;
	char texto[20], texto1[40];
	int i=1;
	
	fp2 = fopen("arquivoRecebe.txt", "w");//cria e abre em fp2
	
	do{
		printf("Digite o nome do %i%c arquivo: \n", i, 167);
		fflush(stdin);
		gets(texto);
		if((fp1 = fopen(texto, "r"))!= NULL){//
			i++;//incrementar
			//ler dados do arquivo
			while(fgets(texto1, 39, fp1)!= NULL){// tamanho do texto -1, le dados do texto1
				//guardar em arquivo fp2
				fputs(texto1, fp2);
			}
			fclose(fp1);//fecha na primeira vez e usa fp1 novamente
		}else{
			printf("%i%c arquivo nao pode ser aberto.\n", i, 167);
		}
	}while(i<=2);//porque quero 2x essa contagem, pq posso digitar 2 arquivos
	fclose(fp2);//fecha depois dos 2 arquivos juntos
}
