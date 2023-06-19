#include <stdio.h>
#include "hash.h"

int main() {
    Hash *h;

    h = cria_hash();
    
    h->t1[1] = 20;
    h->t1[1] = 23;
    printf("%d\n", busca(h, 23));
    return 0;
}