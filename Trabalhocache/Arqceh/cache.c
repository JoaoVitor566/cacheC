#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

struct cache {
	unsigned int tam;
	unsigned int tBloco;
	unsigned int num_linhas;
	struct bloco_cache* bloco;
};
struct bloco_cache {
	unsigned int dados;
	unsigned int tag;
	unsigned int valido;
};

struct cache* criar_cache(const unsigned int tam, const unsigned int tam_bloco){
	unsigned int num_linhas = tam/(tam_bloco*4);
	int i;
	struct cache* c = malloc(sizeof(struct cache));
	c->bloco = (struct bloco_cache*)malloc((num_linhas*4)*sizeof(struct bloco_cache));
	for(i=0;i<(num_linhas*4);i++){
		c->bloco[i].tag = 0;
		c->bloco[i].valido = 0;
		c->bloco[i].dados = 0;
	}
	c->tam = tam;
	c->tBloco = tam_bloco;
	c->num_linhas = num_linhas;
	
	return c;
}

void freeCache(struct cache* c){
	free(c->bloco);
}

Procurar_cache(struct cache* c, int num){
	int i, indice=0;
	for(i=0;i<c->num_linhas;i++){
		if(num & 1<<i){
			indice++;
		}
	}
	for(i=0;i<c->num_linhas;i+=4){
		
	}
}
