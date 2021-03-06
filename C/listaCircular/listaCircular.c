#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
int tam = 0;

void addInicio(int elemento){

	NO* novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	if(tam == 0){ //inicio == null
		novo->prox = novo;
		novo->ant = novo;
	}else{
		novo->prox = inicio;
		novo->ant = inicio->ant;
		inicio->ant->prox = novo;
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
		novo->prox = novo;
		novo->ant = novo;
		inicio = novo;
	}else{
		novo->prox = inicio->ant->prox;
		novo->ant = inicio->ant;
		inicio->ant->prox = novo;
		inicio->ant = novo;
	}
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
		}else{
			inicio->prox->ant = inicio->ant;
			inicio->ant->prox = inicio->prox;
			inicio = inicio->prox;
		}
		free(lixo);
		tam--;
	}
}

void rmFim(){
	if(tam>0){
		NO* lixo = inicio->ant;
		if(tam == 1){
			inicio = NULL;
		}else{
			inicio->ant = inicio->ant->ant;
			inicio->ant->prox = inicio;
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
   aux = inicio;
   int i;
   for(i = 0; i<tam; i++){
	   printf ("%d\n", aux->elemento);
	   aux = aux->prox;
	}
}

void tamanho(){
	printf("A lista tem %d elementos\n",tam);
}

int main(){
	addFim(100);
	addInicio(60);
	addInicio(50);
	addInicio(40);
	addInicio(30);
	addInicio(20);
	
	
	imprime();
	rm(4);
	printf("\n------------------\n");
	tamanho();
	imprime();
	
	return 0;
}

