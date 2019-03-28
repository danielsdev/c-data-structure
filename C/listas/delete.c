#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
NO *fim;
int tam = 0;

void addInicio(int elemento){

	NO *novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	if(tam == 0){ //inicio == null
	 fim = novo;
	}else{
	 novo->prox = inicio;	 
	}
	inicio = novo;
	tam++;
}

void addFim(int elemento){

	NO *novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	if(tam == 0){ //inicio == null
		inicio = novo;
	}else{
		fim->prox = novo;
	}
	fim = novo;
	tam++;
}


void add(int posicao, int elemento){
	if(posicao>=0 && posicao <=tam){
		if(posicao==0){
			addInicio(elemento);
		}else{
			NO *aux = inicio;
			NO *novo = malloc (sizeof(NO));
			novo->elemento = elemento;
			int i;
			for(i = 0; i<posicao-1; i++){
				aux = aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
		}
		tam++;
	}
}

void rmInicio(){
	if(tam>0){
		NO* lixo = inicio;
		if(tam ==1){
			inicio = NULL;
			fim = NULL;
		}else{
			inicio = inicio->prox;
		}
		free(lixo);
		tam--;
	}
}

void rm(int posicao){
	if(posicao >= 0 && posicao < tam && tam>0){
		if(posicao == 0){
			rmInicio();
		}else{
			NO* aux = inicio;
			int i;
			for(i = 0; i<posicao-1; i++){
				aux = aux->prox;
			}
			NO* lixo = aux->prox;
			aux->prox = aux->prox->prox;
			if(posicao == tam-1){
				fim = aux;
			}
			free(lixo);
			tam--;
		}
	}
}

void imprime () {
   NO *aux;
   int i = 0;
   for (aux = inicio; aux != NULL; aux = aux->prox){
      printf ("%d - %d\n", i, aux->elemento);
      i++;
   }
}

int main(){

	addInicio(30);
	addInicio(20);
	addInicio(10);
	addFim(40);
	imprime();
	printf("\n---------------\n");
	rm(0);
	imprime();
	return 0;
}
