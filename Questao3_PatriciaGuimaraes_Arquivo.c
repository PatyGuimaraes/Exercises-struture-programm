/*3 � Fa�a um programa que receba do usu�rio um arquivo texto e um caracter. Mostre na 
tela quantas vezes aquele caractere ocorre dentro do arquivo.*/

#include<stdio.h>
#include<string.h>
//ainda tenho que fazer
int main(){
	FILE *fp;
	char caracteres;
	char texto[100];
	int i=0;
//�para gravar
	if((fp = fopen("arq.txt", "w"))!=NULL){//w para gravar
		printf("Digite varios caracteres: \n");
		while((caracteres = getche())!= NULL){
			putc(caracteres, fp);
		}
		fclose(fp);
	}
//para mostrar
	
	if((fp = fopen("arq.txt", "r"))!=NULL){
	
		while((caracteres = getc(fp))!= EOF){//le os caracteres at� o fim
			putc(caracteres, fp);
			texto[i] = caracteres;//guarda em texto
			i++;
		}
		fclose(fp);
		texto[i]= '\0';//texto de i = nulo para parar o texto.
	}
	puts(texto);//mostrar texto do arquivo
		
	
}
