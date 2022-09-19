#include <stdio.h>
#include <stdlib.h>
#include "cache.h"



int main() {
	FILE *arq;
	arq = fopen("C:\\Users\\João Vitor\\Documents\\Trabalhocache\\txt\\EXcache.txt","r");
	
	int Tcache, Bcache, num, i, end;
	float Tc, TRM, TWM, ciclo;
	char tipo;
	
	
	//Verifica se conseguiu abrir o arquivo
	if (arq == NULL) {
		printf("Problema na leitura do arquivo!\n");
		return 0;
	}
	
	//Leitura primeira linha
	fscanf(arq, "%d %d %f %f %f", &Tcache, &Bcache, &Tc, &TRM, &TWM);
	printf("%d %d %.0f %.0f %.0f\n", Tcache, Bcache, Tc, TRM, TWM);
	
	//Leitura segunda linha
	fscanf(arq, "%d", &num);
	printf("%d\n", num);
	
	//Leitura linhas restantes
	for(i=0;i<num;i++){
		fscanf(arq, "%f %s %d", &ciclo, &tipo, &end);
		printf("%.0f %c %d\n", ciclo, tipo, end);
	}
	printf("%d 4 %d LRU WB WNA %.0f %.0f %.0f\n", Tcache, Bcache, Tc, TRM, TWM);
	fclose(arq);
	return 0;
}
