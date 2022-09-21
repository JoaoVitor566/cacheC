struct cache {
	unsigned int tam;
	unsigned int Num_set;
	unsigned int Tbloco;
	struct Bloco_cache bloco;
	
};

struct Bloco_cache {
	bool indice;
	bool valido;
	unsigned int tag;
	unsigned int dado;
};

