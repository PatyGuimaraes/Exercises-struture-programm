/*1 – Escreva um programa que:
(a) Crie/abra um arquivo texto de nome “arq.txt”
(b) Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário
entre com o caractere ‘0’
(c) Feche o arquivo
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os 
caracteres armazenados.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char caracteres;
	char texto[100];
	int i=0;
//´para gravar
	if((fp = fopen("arq.txt", "w"))!=NULL){//w para gravar
		printf("Digite varios caracteres. Para finalizar digite 0: \n");
		while((caracteres = getche())!= '0'){
			putc(caracteres, fp);
		}
		fclose(fp);
	}
//para mostrar
	if((fp = fopen("arq.txt", "r"))!=NULL){
		while((caracteres = getc(fp))!= EOF){//le os caracteres até o fim
			putc(caracteres, fp);
			texto[i] = caracteres;//guarda em texto
			i++;
		}
		fclose(fp);
		texto[i]= '\0';//texto de i = nulo para parar o texto.
	}
	puts(texto);//mostrar texto do arquivo
		
	
}
