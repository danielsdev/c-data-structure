#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO* raiz;


//Cria a arvore
NO* cria_ArvBin(){
	NO* raiz = malloc(sizeof(NO));
	if(raiz != NULL){
		raiz = NULL;
	}
	return raiz;
}


void libera_NO(NO* no){
	if(no == NULL){
		return;
	}
	libera_NO(no->esq); //Libera os nós da esquerda
	libera_NO(no->dir); //Libera os nós da direita
	free(no); //Libera a memoria do no
}

void libera_ArvBin(NO* raiz){
	if(raiz == NULL){
		return;
	}
	libera_NO(raiz); // Libera cada nó recursivamente
	free(raiz); //Libera a raiz
}

void pre_ordem(NO* raiz){
	if(raiz == NULL){
		return;
	}
	printf("%d\n", raiz->elemento);
	pre_ordem(raiz->esq);
	pre_ordem(raiz->dir);
}

void em_ordem(NO* raiz){
	if(raiz == NULL){
		return;
	}
	pre_ordem(raiz->esq);
	printf("%d\n", raiz->elemento);
	pre_ordem(raiz->dir);
}

void pos_ordem(NO* raiz){
	if(raiz == NULL){
		return;
	}
	pre_ordem(raiz->esq);
	pre_ordem(raiz->dir);
	printf("%d\n", raiz->elemento);

}



int main(){
	//Cria a arvore
	raiz = cria_ArvBin();

	return 0;
}
