#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
NO *fim;
int tam = 0;

void addInicio(int elemento){

	NO *novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;	
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
	novo->prox = NULL;
	if(tam == 0){ //inicio == null
	 inicio = novo;
	}else{
	 fim->prox = novo;	 
	}
	fim = novo;
	tam++;
}

void add(int posicao, int elemento){

    if(posicao >= 0 && posicao <=tam){
	 NO *novo = malloc (sizeof(NO));
	 novo->elemento = elemento;
	 novo->prox = NULL;
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
	  aux->prox = novo;
	  tam++;
      }
   }
}



void imprime () {
   NO *aux;
   for (aux = inicio; aux != NULL; aux = aux->prox) 
      printf ("%d\n", aux->elemento);
}

//Exercicio: criar as funções remover no inicio, fim e em qualquer posicao

void main(){

	
	imprime();	
	printf("Depois da remocao\n");
	rm(-1);
	imprime();
}
