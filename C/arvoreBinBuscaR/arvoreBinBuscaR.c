#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO* raiz;

//Cria a Arvore
NO* cria_ArvBin(){
	NO* raiz = malloc(sizeof(NO));
	if(raiz != NULL){
		raiz = NULL;
	}
	return raiz;
}

//Libera a memoria do NO
void libera_NO(NO* no){
	if(no == NULL){
		return;
	}
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
}

//Libera a memoria da Arvore
void libera_ArvBin(NO* raiz){
	if(raiz == NULL){
		return;
	}
	libera_NO(raiz); // Libera cada nó recursivamente
	free(raiz);
}

//Adiciona valores na Arvore
void add(NO** node, int valor){
	
	//Encaixa o valor na Arvore
	if(*node == NULL){
		NO* novo = malloc(sizeof(NO));
		novo->elemento = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		*node = novo;
	}else{
		if(valor < (*node)->elemento){
			add(&(*node)->esq, valor);
		}else if(valor > (*node)->elemento ){
			add(&(*node)->dir, valor);
		}
	}
}

//Trata os 3 casos de remocao
NO* rm_atual(NO* atual){
	NO* no2;
	
	//Caso for remover uma folha, ou NO com 1 filho
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	NO* no1;
	no1 = atual;
	no2 = atual->esq;
	
	//Busca o filho mais a direita
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	
	//Atualiza os ponteiros
	if(no1 != atual){
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}
	no2->dir = atual->dir;
	
	free(atual);
	return no2;
}

//Busca pelo NO a ser removido
int rm_ArvoreBin(NO** raiz, int valor){
	if(raiz == NULL){
		return 0;
	} 
	
	NO* ant = NULL;
	NO* atual = *raiz;
	
	while(atual != NULL){
		if(valor == atual->elemento){
			if(atual == *raiz){
				*raiz = rm_atual(atual);
			}else{
				if(ant->dir == atual ){
					ant->dir = rm_atual(atual);
				}else{
					ant->esq = rm_atual(atual);
				}
			}
			return 1;
		}
		
		//Percorre a arvore
		ant = atual;
		if(valor > atual->elemento){
			atual = atual->dir;
		}else{
			atual = atual->esq;
		}
	}
	return 0;
}

int consulta(NO* raiz, int valor){

	if(raiz == NULL){
		return 0;
	}
	NO* atual = raiz;
	while(atual != NULL){
		if(valor == atual->elemento){
			return 1;
		}
		if(valor > atual->elemento){
			atual = atual->dir;
		}else{
			atual = atual->esq;
		}
	}
	return 0;
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
	em_ordem(raiz->esq);
	printf("%d\n", raiz->elemento);
	em_ordem(raiz->dir);
}

void pos_ordem(NO* raiz){
	if(raiz == NULL){
		return;
	}
	pos_ordem(raiz->esq);
	pos_ordem(raiz->dir);
	printf("%d\n", raiz->elemento);

}

int main(){
	
	//Cria a arvore
	add(&raiz, 50);
	add(&raiz, 99);
	add(&raiz, 100);
	add(&raiz, 105);
	
	printf("\nPre ordem:\n");
	pre_ordem(raiz);
	
	rm_ArvoreBin(&raiz, 99);
	printf("\nPre ordem:\n");
	pre_ordem(raiz);

	if(consulta(raiz, 99)){
		printf("\n ACHOU !!!!");
	}
	
	return 0;
}

