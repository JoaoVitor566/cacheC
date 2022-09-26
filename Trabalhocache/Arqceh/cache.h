#ifndef CACHE_H
#define CACHE_H
#include <stdlib.h>

struct cache {
	unsigned int Tam;
	unsigned int Tbloco;
	struct Bloco_cache** bloco;
	unsigned int num_linhas;
	
	unsigned int hit;
	unsigned int miss;
	
	unsigned int tc;
	unsigned int tw;
	unsigned int tr;
	unsigned int tt;
	
		
};
	
struct Bloco_cache {
	unsigned int valido;
	unsigned int tag;
	unsigned int dados;
};
	
struct cache* criar_cache(unsigned int Tam, unsigned int Bcache,unsigned int tc, unsigned int TRM, unsigned int TWM);
void freeCache(struct cache* c);
struct cache* Procurar_cache(struct cache* c,unsigned int ciclo, char tipo, unsigned int end);
void LRU(struct cache* c, unsigned int tag, unsigned int indice);
void escreve_cache(struct cache* c, unsigned int tag, unsigned int dado, unsigned int indice);
	
	
	
#endif

