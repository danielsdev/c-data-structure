#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO* topo;
int tam=0;

void push(int elemento){
	NO* novo = malloc(sizeof(NO));
	novo->elemento = elemento;

	novo->prox = NULL;
	if(tam==0){
		topo = novo;
	}else{
		novo->prox = topo;
		topo = novo;
	}
	tam++;
}

int pop(){
	if(tam>0){
		NO* lixo = topo;
		int aux = topo->elemento;
		if(tam==1){
			topo=NULL;
		}else{
			topo = topo->prox;
		}
		tam--;
		free(lixo);
		return aux;
	}
	return 0;
}

void imprime(){
	NO* aux = topo;
	for(aux = topo; aux != NULL; aux = aux->prox)
		printf("%d ",aux->elemento);
}

//OPERAÇÕES

int operation(int a, int b, char op){
	int num = 0;
	switch(op){
		case '+':
			num = b+a;
			break;
		case '-':
			num = b-a;
			break; 
		case '/':
			num = b/a;
			break; 
		case '*':
			num = b*a;
			break; 
	}
	return num;
}

void calc(){
	char elemento;
	int a,b;
	do{
		setbuf(stdin, NULL);
		printf("\nDigite o elemento ou a operação ou 'N' para fechar: ");
		scanf("%27[^\n]%*c", &elemento);
		if(elemento == '+' || elemento == '-' || elemento == '*' || elemento == '/' ){
			a = pop();
			b = pop();
			push(operation(a, b,elemento));
		}else if(elemento != 'N'){
			//Converte para inteiro e insere na pilha
			push(elemento - 48);
		}
	}while(elemento != 'N');
}

int main(){
	
	calc();
	imprime();
	//calc();

	return 0;
}
