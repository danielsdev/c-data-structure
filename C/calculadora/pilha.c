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
	printf("\n IMPRIMINDO PILHA \n");
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

int resultadoPosFixado (char *entrada, int qtd){
	int a,b;
	for(int i=0; i<qtd; i++) {
		if(entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' ){
			a = pop();
			b = pop();
			push(operation(a, b,entrada[i]));
		}else{
			push(entrada[i] - 48);
		}
	}
	
	return topo->elemento;

}


int main(){
	int result;
	int qtd;
	char entrada[] = {'1','2','-','4','5','+','*'};
	qtd = sizeof(entrada) / sizeof(char);
	result = resultadoPosFixado(entrada, qtd);
	printf("%d", result);

	imprime();

	return 0;
}
