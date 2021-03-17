// Escrever um programa que declare um vetor de reais e leia as notas de 30 alunos.


#include <stdio.h>
float leValidaNotas(int ind);
int main(){
	
	float notas[30];
	int i;
	
	printf("\tNotas dos alunos.\n");
	for(i=0; i<30; i++){
		notas[i]= leValidaNotas(i);
	}

	return 0;
}
float leValidaNotas(int ind){
	float nota;
	do{
		printf("Nota do %i%c aluno: ", ind+1, 167);
		scanf("%f", &nota);
		if (nota<0 || nota>10){
			printf("\nNota inv%clida. Notas de 0 a 10\n", 160);
		}
	}while(nota<0 || nota>10);
	return nota;
}
