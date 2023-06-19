#define M 11 // tamanho das tabelas
#define VAZIO -2
#define EXCLUIDO -3

typedef struct Hash{
    int t1[M]; // tabela hash 1
    int t2[M]; // tabela hash 2
} Hash;

Hash *cria_hash();

int busca(Hash *hash, int k);