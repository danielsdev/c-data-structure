#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 127

int tabela[TABLE_SIZE];

int f(int valor){
	
	int v =  valor * M_SQRT1_2; //Raiz de 1/2
	
	int v2 = valor*M_E; //Número de Euler
	
	return ((valor * v * v2))%127;
}

int main(){
	int i,valor, indice, colisao = 0;
	
	//Inicializa os valores do vetor com -1
	for(i=0; i<127;i++){
		tabela[i] = -1;
	}
	
	//Gera 50 números aleatórios
	for(i=0; i<50; i++){
		printf("%d \n", rand() % 1000);
		valor = rand() % 1000;
		indice = f(valor);
		
		//-1 representa um espaco livre
		if(tabela[indice] == -1){
			tabela[indice] = valor;
		}else{
			if(tabela[indice] == valor){
			
			}else{
				colisao++;
			}
		}
	}
	
	printf("Numero de colisoes = %d", colisao);
	
	return 0;
}
