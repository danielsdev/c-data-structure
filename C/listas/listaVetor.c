#include <stdio.h>
#include <stdlib.h>

int vetor[10];
int tam = 0;

void add(int posicao, int elemento){

	if(posicao >= 0 && posicao <= tam && tam < 10){
	 int i;
		for(i = tam; i > posicao; i--){
			vetor[i] = vetor[i-1];
		}
	 vetor[posicao]= elemento;
	 tam++;
	}
}

//Retorna a posição do elemento no vetor
int buscar(int elemento){
	int i;
	for(i = 0; i < tam; i++){
		if(vetor[i] == elemento)
			return i;
	}
	return -1;
}

//remover ...
void remover(int elemento){
	int posicao = buscar(elemento);
	if(posicao>=0 && posicao <tam){
		int i;
		for(i=posicao; i<tam-1; i++){
			vetor[i] = vetor[i+1];
		}
		tam--;
		printf("\nElemento excluído\n");
	}else{
		printf("\nElemento não encontrado");
	}
}



void imprimir(){
	int i;
	printf("imprimindo... \n");
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
}


int main(){

	add(0,00); //add inicio
	add(1,10); //add fim
	add(2,20); //add "meio"
	add(3,30);
	add(4,40);
	add(5,50);
	add(6,60);
	add(7,70);
	add(8,80);
	add(9,90);
	
	imprimir();
	
	remover(90);
	
	printf("\n");
	imprimir();
	
	return 0;
}

