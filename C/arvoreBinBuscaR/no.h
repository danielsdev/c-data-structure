#include <stdio.h>
#include <stdlib.h>

struct NO{
	int elemento;
	struct NO* esq;
	struct NO* dir;
};

typedef struct NO NO;

NO* cria_ArvBin();

void libera_ArvBin();
