#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
NO *fim;
int tam = 0;

void add(int elemento){

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

void rm(){
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

void imprime () {
   NO *aux;
   for (aux = inicio; aux != NULL; aux = aux->prox) 
      printf ("%d\n", aux->elemento);
}

int main(){
	
	add(10);
	add(20);
	add(30);
	add(40);
	add(50);
	
	imprime();
	
	return 0;
}
