#include <stdio.h>
#include "hash.h"

int main() {
    Hash *hash;
    hash = cria_hash();
    
    char op;
    int k;
    while(scanf("%c%d", &op, &k) == 2){
        if(op == 'i')
            inserir(hash, k);
        else if(op == 'r')
            excluir(hash, k);

        scanf("%c", &op); // le \n
    }

    imprime_hash(hash);
    hash = destroi_hash(hash);
    return 0;
}