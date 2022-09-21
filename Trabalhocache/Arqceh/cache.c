#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

struct cache* criar_cache(unsigned int tamanho, unsigned int Tam_bloco){
	unsigned int Num_set = tamanho/(4*Tam_bloco), i=0, j=0;
	struct cache* c = malloc(sizeof(struct cache));
	c->bloco = (struct Bloco_cache**)malloc(Num_set*sizeof(struct Bloco_cache*));
	for(i=0;i<Num_set;i++){
		c->bloco[i] = (struct Bloco_cache*)malloc(4*sizeof(struct Bloco_cache));
		for(j=0;j<4;j++){
			c->bloco[i][j].valido = 0;
			c->bloco[i][j].indice = 0;
			c->bloco[i][j].tag = 0;
		}
	}
	c->tam = tamanho;
	c->Tbloco = Tam_bloco;
	c->Num_set = Num_set;
	
}


void freeCache(Struct cache* c){
	unsigned int i;
	for(i=0;i<c->Num_set;i++){
		free(c->bloco[i]);
	}
	free(c->bloco);
	free(c);
}
