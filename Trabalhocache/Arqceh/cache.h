struct cache {
	unsigned int tam;
	unsigned int Num_set;
	unsigned int Tbloco;
	struct Bloco_cache bloco;
	struct HitMiss hitmiss; 
	struct Endereco endereco;
};

struct Bloco_cache {
	bool indice;
	bool valido;
	unsigned int tag;
	unsigned int dado;
};

struct HitMiss {
	unsigned int hit;
	unsigned int miss;
};

struct Endereco {
	unsigned int tag_end;
	unsigned int indice_end;
	unsigned int tam_end;
	unsigned int valido_end; 
};
