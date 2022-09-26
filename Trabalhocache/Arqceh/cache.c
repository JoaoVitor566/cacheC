#include <stdio.h>
#include <stdlib.h>
#include "cache.h"



struct cache* criar_cache(unsigned int tamanho, unsigned int Tam_bloco,unsigned int tc, unsigned int TRM, unsigned int TWM){
	unsigned int indice = tamanho/(4*Tam_bloco), i, j;
	struct cache* c = malloc(sizeof(struct cache));
	c->bloco = (struct Bloco_cache**)malloc(indice*sizeof(struct Bloco_cache*));
	for(i=0;i<indice;i++){
		c->bloco[i] = malloc(4*sizeof(struct Bloco_cache));
		for(j=0;j<4;j++){
			c->bloco[i][j].dados = 0;
			c->bloco[i][j].tag = 0;
			c->bloco[i][j].valido = 0;
		}
	}
	c->Tam = tamanho;
	c->Tbloco = Tam_bloco;
	c->num_linhas = indice;
	c->hit = 0;
	c->miss = 0;
	c->tc = tc;
	c->tr = TRM;
	c->tw = TWM;
	c->tt = 2*c->tw;
	
	return c;
	
}

void freeCache(struct cache* c){
	int i;
	for(i=0;i<c->num_linhas;i++){
		free(c->bloco[i]);
	}
	free(c->bloco);
	free(c);
}

struct cache* Procurar_cache(struct cache* c,unsigned int ciclo, char tipo,unsigned int end){
	unsigned int i;
	unsigned int num_bit_tag = 64-(2 + c->num_linhas);
	unsigned int tag_end = (end <<(2 + c->num_linhas));
	unsigned int indice_end = (num_bit_tag >> end <<  2);
	
	for(i=0;i<4;i++){
		if(c->bloco[indice_end][i].tag == tag_end){
			if(tipo == 'W'){
				c->tt += c->tc;
			}
			else {
				c->tt += c->tc + c->tr;
			}
			c->hit++;
			LRU(c,tag_end, indice_end);
			break;
		}
		else if(i==3){
			c->miss++;
			if(tipo == 'R'){
				c->tt += c->tc + c->tr;
				escreve_cache(c,tag_end,end,indice_end);
				LRU(c, tag_end, indice_end);
			}
			else {
				c->tt += c->tc + c->tw;
			}
			
		}
	}
	
	
	
	return c;
	
}

void LRU(struct cache* c, unsigned int tag, unsigned int indice){
	unsigned int i;
	struct Bloco_cache* bloco_aux;
	bloco_aux = c->bloco[indice];
	
	for(i=indice;i>0;i--){
		c->bloco[i] = c->bloco[i-1];
	}
	c->bloco[0] = bloco_aux;
}

void escreve_cache(struct cache* c, unsigned int tag, unsigned int dado, unsigned int indice){
	int i;
	for(i=0;i<4;i++){
		if(c->bloco[indice][i].valido == 0){
			c->bloco[indice][i].tag = tag;
			c->bloco[indice][i].dados = dado;
			c->bloco[indice][i].valido = 1;
			break;
		}
	}
}
