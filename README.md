# Hash Table
Tabela Hash implementada para a disciplina de Algoritmos e Estrutura de Dados 3. A implementação foi feita simulando o algoritmo Cuckoo Hash, mas sem o rehashing.

# Execução:
Execute o makefile para gerar o executável. Com o executável gerado, execute da seguinte forma:
./myht

## Entrada:
Para realizar a inclusão ou remoção de um valor:
    <operação(char)> <valor(int)>

As operações podem ser i (inserir) e r (remover). O programa irá executar enquanto você continuar a entrar um char e um int, um seguido do outro.

## Exemplo:
    ./myht
    i 10
    i 22
    r 10
    g g

## Saída:
A saída será a impressão dos valores na Hash, em qual tabela estão e qual posição da tabela estão.

Para o exemplo acima, a saída seria:
    22,T1,0

# Enunciado do projeto

## Tabelas Hash:

O trabalho terá duas tabelas hash de tamanho igual T1 e T2. Assuma tamanho m = 11. A função hash tem a assinatura h(k), onde k é a chave inteira. A primeira tabela T1 possui função hash "h1(k) = k mod m". A segunda tabela T2 possui função hash "h2(k) = ⌊m * (k * 0.9 − ⌊k * 0.9⌋)⌋", onde "⌊ ⌋" significa o arredondamento para inteiro imediatamente menor (i.e., chão) de um valor real. Trataremos colisão movendo chaves entre T1 e T2 ao invés de usar sondagem (e.g., linear ou quadrática). Esse exercício simula o algoritmo de Cuckoo Hash, mas sem nos preocuparmos com rehashing.
Algoritmo de busca:

    Se a posição da chave k calculada por h1(k) estiver vazia, então retorna nulo e a chave não existe (devido nosso tratamento de colisão na inclusão e exclusão).
    Se a chave k existe em T1, retorna a posição dela em T1 com h1(k).
    Senão, a chave k existe em T2, retorna a posição dela em T2 com h2(k).

## Algoritmo de busca:

    1. Se a posição da chave k calculada por h1(k) estiver vazia, então retorna nulo e a chave não existe (devido nosso tratamento de colisão na inclusão e exclusão).
    
    2. Se a chave k existe em T1, retorna a posição dela em T1 com h1(k).
    
    3. Senão, a chave k existe em T2, retorna a posição dela em T2 com h2(k).


## Algoritmo de inclusão:

    Algoritmo de inclusão:

    1. A inclusão deve ser feita sempre em T1: Se a posição calculada por h1(k) estiver vazia ou marcada como "excluída", então insira a chave k.
    
    2. Senão, temos colisão em T1 e devemos realizar duas operações:
        1. considere a chave atual como ki e a nova chave a ser inserida como kj e considere a colisão quando h1(ki) == h1(kj)
        
        2. copiar ki que está em h1(ki) de T1 para T2. O objetivo é permitir inclusão da nova chave kj em T1 sem perder ki na colisão. A chave ki deverá ser incluida em T2 usando h2(ki).
        
        3. incluir a nova chave kj na posição h1(kj) de T1.
        
    3. A estrutura deverá ignorar chaves duplicadas neste caso simplesmente mantendo a primeira chave inserida.

Considere como exemplo a inclusão das seguintes chaves em sequencia: k = {10, 22, 4, 15, 59}. A imagem abaixo mostra as tabelas T1 e T2 após as inclusões e um log das operações. As chaves 10 e 22 não tiveram colisão. As chaves 4, 15 e 59 tiveram colisão. Em T1 somente deve ficar a chave 59, pois foi a última a ser inserida. As chaves 4 e 15 foram movidas para T2 seguindo o algoritmo e estão escritas em vermelho em T1 somente para mostrar que foram retiradas de T1. Como não nos preocuparemos com rehashing, os casos de teste não terão colisão em T2.

## Algoritmo de exclusão:

    1. Podemos excluir qualquer chave de qualquer tabela. Considere que a chave a ser excluída ki existe em T1 ou T2.
    
    2. Se a chave ki estiver na posição calculada por h2(ki) em T2, então apenas exclua a chave ki de T2.
    
    3. Senão, a chave está na posição calculada por h1(ki) em T1. Neste caso precisamos ter cuidado, pois podem existir chaves inser/idas em T2 que dependem de uma busca em T1 e se encontrarem um valor nul a busca retorna "chave inexistente". Então exclua ki de h1(ki) em T1 e marque a posição em T1 como "excluída" para que uma busca não encontre posição nula e devolva chave não encontrada. Não esqueça de alterar o algoritmo de busca para considerar o estado de "excluída".

Considere como exemplo a exclusão das seguintes chaves em sequencia: k = {15, 22, 59}. As posições das chaves 22 e 59 em T1 foram marcadas como excluida pois não sabemos se existem chaves em T2 que dependem dessa posição para a busca.
