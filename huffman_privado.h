typedef unsigned char byte;

typedef struct nodeArvore
{
    int                 frequencia;
    byte                c;
    struct nodeArvore   *esquerda;
    struct nodeArvore   *direita;
} nodeArvore;

typedef struct nodeLista
{
    nodeArvore          *n;
    struct nodeLista    *proximo;
} nodeLista;

typedef struct lista
{
    nodeLista   *head;
    int         elementos;
} lista;
