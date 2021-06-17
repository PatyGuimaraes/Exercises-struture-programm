/*2 – Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas
letras são vogais e quantas são consoantes.*/

#include<stdio.h>
#include<string.h>

int main(){
	
	FILE *fp;
	char caracter, nomeArq[30];
	int contVogal=0, contConsoante=0;
	puts("Digite o nome do arquivo:");
	gets(nomeArq);
	
	if((fp=fopen(nomeArq, "r"))!=NULL){
		while((caracter = getc(fp))!=EOF){//caracter por caracter enquanto for != final
			caracter = tolower(caracter);//para aceitar minusculas e maiusculas
			if(caracter =='a'|| caracter =='e' || caracter =='i' || caracter=='o' || caracter =='u'){
				contVogal++;//incrementa para contar as vogais
			}else{
				if(caracter>'a' && caracter<='z'){//>a porque é a partir de b, não precisa o a pq é vogal
					contConsoante++;//conta as consoantes
				}
			}
		}
		fclose(fp);
	}
	printf("Arquivo %s possui %i vogais.\n", nomeArq, contVogal);
	printf("Arquivo %s possui %i consoantes.\n", nomeArq, contConsoante);
}

