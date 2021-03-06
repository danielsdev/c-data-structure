#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
NO *fim;
int tam = 0;

void addInicio(int elemento){

	NO* novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	if(tam == 0){ //inicio == null
		fim = novo;
	}else{
		novo->prox = inicio;
		inicio->ant = novo;
	}
	inicio = novo;
	tam++;
}


void addFim(int elemento){

	NO* novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	if(tam == 0){ //inicio == null
		inicio = novo;
	}else{
		fim->prox = novo;
		novo->ant = fim;
	}
	fim = novo;
	tam++;
}

void add(int posicao, int elemento){

    if(posicao >= 0 && posicao <=tam){
		NO *novo = malloc (sizeof(NO));
		novo->elemento = elemento;
		novo->prox = NULL;
		novo->ant = NULL;
		if(posicao == 0){ 
			addInicio(elemento);
		}else if(posicao == tam){
			addFim(elemento);	 
		}else{
			NO* aux = inicio;
			int i;
			for(i=0; i<posicao-1; i++){
			  aux = aux->prox;
			}
			novo->prox = aux->prox;
			novo->ant = aux;
			aux->prox->ant = novo;
			aux->prox = novo;
			tam++;
		}
   }
}

void rmInicio(){
	if(tam>0){
		NO* lixo = inicio;
		if(tam == 1){
			inicio = NULL;
			fim = NULL;
		}else{
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		free(lixo);
		tam--;
	}
}

void rmFim(){
	if(tam>0){
		NO* lixo = fim;
		if(tam == 1){
			inicio = NULL;
			fim = NULL;
		}else{
			fim = fim->ant;
			fim->prox = NULL;
		}
		free(lixo);
		tam--;
	}
}

void rm(int posicao){
	if(posicao >= 0 && posicao < tam && tam>0){
		if(posicao == 0){
			rmInicio();
		}else if(posicao == tam-1){
			rmFim();
		}else{
			NO* aux = inicio;
			int i;
			for(i = 0; i<posicao-1; i++){
				aux = aux->prox;
			}
			NO* lixo = aux->prox;
			aux->prox = aux->prox->prox;
			aux->prox->prox->ant = aux;
			free(lixo);
			tam--;
		}
	}
}



void imprime () {
   NO *aux;
   for (aux = inicio; aux != NULL; aux = aux->prox) 
      printf ("%d\n", aux->elemento);
}

int main(){
	addInicio(60);
	addInicio(50);
	addInicio(40);
	addInicio(30);
	addInicio(20);
	addInicio(10);
	
	imprime();
	
	rm(3);
	
	printf("\n------------------\n");
	
	imprime();
	
	return 0;
}

