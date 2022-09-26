#include <stdio.h>
#include <stdlib.h>
#include "cache.h"




int main() {
	FILE *arq;
	arq = fopen("C:\\Users\\João Vitor\\Documents\\Trabalhocache\\txt\\EXcache.txt","r");
	
	int Tcache, Bcache, num, i, end, Tc, TRM, TWM, ciclo,j;
	char tipo;
	struct cache* c;
	
	
	//Verifica se conseguiu abrir o arquivo
	if (arq == NULL) {
		printf("Problema na leitura do arquivo!\n");
		return 0;
	}
	
	//Leitura primeira linha
	fscanf(arq, "%d %d %d %d %d", &Tcache, &Bcache, &Tc, &TRM, &TWM);
	c = criar_cache(Tcache,Bcache,Tc,TRM,TWM);
	
	//Leitura segunda linha
	fscanf(arq, "%d", &num);
	
	//Leitura linhas restantes
	for(i=0;i<num;i++){
		fscanf(arq, "%d %c %d", &ciclo, &tipo, &end);
		c = Procurar_cache(c,ciclo,tipo,end);
	}
	
	
	
	
	printf("%d 4 %d LRU WB WNA %d %d %d\n", Tcache, Bcache, Tc, TRM, TWM);
	printf("%d\n", c->tt);
	printf("%d %d\n",c->miss, c->hit);
	printf("%d\n", c->num_linhas);
	for(i=0;i<c->num_linhas;i++){
		for(j=0;j<4;j++){
			printf("%d ", c->bloco[i][j].dados);
		}
		printf("\n");
	}
	freeCache(c);
	fclose(arq);
	
	
	return 0;
}
	
