#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Hash *cria_hash(){
    Hash *hash;
    
    if(!(hash = malloc(sizeof(Hash))))
        return NULL;

    for (int i = 0; i < M; i++)
    { // inicializa as tabelas como vazias
        hash->t1[i] = VAZIO; // 
        hash->t2[i] = VAZIO;
    }
    
    return hash;
}

int h1(int k){
    return k % M;
}

int h2(int k){
    return (int) floor(M * (k * 0.9 - floor(k * 0.9)));
}

int busca(Hash *hash, int k){
    int i = h1(k);

    if(hash->t1[i] == VAZIO)
        return -1; 
    else if(hash->t1[i] == k)
        return i;
    
    i = h2(k);
    if(hash->t2[i] == k)
        return i;

    return -1;
}