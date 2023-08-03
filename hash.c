#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct T_pos
{ // struct para armazenar as infos da key para printar
    int k;
    int table;
    int pos;
} T_pos;

Hash *cria_hash()
{
    Hash *hash;

    if (!(hash = malloc(sizeof(Hash))))
        return NULL;

    for (int i = 0; i < M; i++)
    {                        // inicializa as tabelas como vazias
        hash->t1[i] = VAZIO; //
        hash->t2[i] = VAZIO;
    }

    return hash;
}

Hash *destroi_hash(Hash *hash)
{
    if (!hash)
        return NULL;

    free(hash);
    return NULL;
}

int h1(int k)
{
    return k % M;
}

int h2(int k)
{
    return (int)floor(M * (k * 0.9 - floor(k * 0.9)));
}

int busca(Hash *hash, int k)
{
    int i = h1(k);

    if (hash->t1[i] == VAZIO) // busca em t1
        return -1;
    else if (hash->t1[i] == k)
        return i;

    i = h2(k);
    if (hash->t2[i] == k) // busca em t2
        return i;

    return -1;
}

void inserir(Hash *hash, int k)
{
    int i = h1(k);

    if (hash->t1[i] == VAZIO || hash->t1[i] == EXCLUIDO) // tenta inserir em t1
    {
        hash->t1[i] = k;
        return;
    }
    else if (hash->t1[i] != k) // insere em t2 caso a posição em t1 n esteja disponível
    {
        int j = h2(hash->t1[i]);
        hash->t2[j] = hash->t1[i];
        hash->t1[i] = k;
    }
}

int excluir(Hash *hash, int k)
{
    int i = h2(k);

    if (hash->t2[i] == k)
    { // busca em t2 e exclui se tiver lá
        hash->t2[i] = EXCLUIDO;
        return 1;
    }

    i = h1(k);
    if (hash->t1[i] == k)
    { // busca em t1 e exclui se tiver lá
        hash->t1[i] = EXCLUIDO;
        return 1;
    }

    return INEXISTENTE;
}

/* cria um vetor do tipo T_pos armaazenando a chave, posição e tabela para cada chave da hash
e depois printa essas informações ordenado pela chave */
void imprime_hash(Hash *hash)
{
    T_pos valores[M * 2];

    for (int i = 0; i < M; i++) // salva as infos de cada chave no vetor 
    {
        valores[i * 2].k = hash->t1[i];
        valores[i * 2].table = 1;
        valores[i * 2].pos = i;
        valores[(i * 2) + 1].k = hash->t2[i];
        valores[(i * 2) + 1].table = 2;
        valores[(i * 2) + 1].pos = i;
    }

    // selection sort p/ ordenar o vetor pela chave e printar 
    for (int i = 0; i < M*2 - 1; i++)
    {
        int pos_menor = i;
        for (int j = i + 1; j < M*2; j++)
        {
            if(valores[j].k < valores[pos_menor].k)
                pos_menor = j;
        }

        T_pos aux = valores[pos_menor];
        valores[pos_menor] = valores[i];
        valores[i] = aux;
    }

    for (int i = 0; i < M*2; i++)
    {
        if(valores[i].k != EXCLUIDO && valores[i].k != VAZIO){
            printf("%d,T%d,%d\n", valores[i].k, valores[i].table, valores[i].pos);
        }
    }
    
}
