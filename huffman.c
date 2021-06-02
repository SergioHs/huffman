#include "huffman_interface.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

nodeLista *novoNodeLista(nodeArvore *nArv)
{
    nodeLista *novo;
    if ( (novo = malloc(sizeof(*novo))) == NULL ) return NULL;

    novo->n = nArv;
    novo->proximo = NULL;

    return novo;
}

nodeArvore *novoNodeArvore(byte c, int frequencia, nodeArvore *esquerda, nodeArvore *direita)
{
    nodeArvore *novo;

    if ( ( novo = malloc(sizeof(*novo)) ) == NULL ) return NULL;

    novo->c = c;
    novo->frequencia = frequencia;
    novo->esquerda = esquerda;
    novo->direita = direita;

    return novo;
}

void insereLista(nodeLista *n, lista *l)
{
    if (!l->head)
    {
        l->head = n;
    }

    else if (n->n->frequencia < l->head->n->frequencia)
    {
        n->proximo = l->head;
        l->head = n;
    }
    else
    {
        nodeLista *aux = l->head->proximo;
        nodeLista *aux2 = l->head;

        while (aux && aux->n->frequencia <= n->n->frequencia)
        {
            aux2 = aux;
            aux = aux2->proximo;
        }

        aux2->proximo = n;
        n->proximo = aux;
    }

    l->elementos++;
}

nodeArvore *popMinLista(lista *l)
{
    nodeLista *aux = l->head;

    nodeArvore *aux2 = aux->n;

    l->head = aux->proximo;

    free(aux);
    aux = NULL;

    l->elementos--;

    return aux2;
}

void getByteFrequency(FILE *entrada, unsigned int *listaBytes)
{

    byte c;

    while (fread(&c, 1, 1, entrada) >= 1)
    {
        listaBytes[(byte)c]++;
    }
    rewind(entrada);

}

int pegaCodigo(nodeArvore *n, byte c, char *buffer, int tamanho)
{
    if (!(n->esquerda || n->direita) && n->c == c)
    {
        buffer[tamanho] = '\0';
        return true;
    }
    else
    {
        bool encontrado = false;

        if (n->esquerda)
        {
            buffer[tamanho] = '0';
            encontrado = pegaCodigo(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita)
        {
            buffer[tamanho] = '1';
            encontrado = pegaCodigo(n->direita, c, buffer, tamanho + 1);
        }
        if (!encontrado)
        {
            buffer[tamanho] = '\0';
        }
        return encontrado;
    }

}

nodeArvore *BuildHuffmanTree(unsigned *listaBytes)
{
    lista l = {NULL, 0};

    for (int i = 0; i < 256; i++)
    {
        if (listaBytes[i]) // Se existe ocorrência do byte
        {
            insereLista(novoNodeLista(novoNodeArvore(i, listaBytes[i], NULL, NULL)), &l);
        }
    }

    while (l.elementos > 1)
    {
        nodeArvore *nodeEsquerdo = popMinLista(&l);

        nodeArvore *nodeDireito = popMinLista(&l);

        nodeArvore *soma = novoNodeArvore(
            '#',
            nodeEsquerdo->frequencia + nodeDireito->frequencia, nodeEsquerdo, nodeDireito
        );
        insereLista(novoNodeLista(soma), &l);
    }

    return popMinLista(&l);
}

void FreeHuffmanTree(nodeArvore *n)
{
    if (!n) return;
    else
    {
        nodeArvore *esquerda = n->esquerda;
        nodeArvore *direita = n->direita;
        free(n);
        FreeHuffmanTree(esquerda);
        FreeHuffmanTree(direita);
    }
}

int geraBit(FILE *entrada, int posicao, byte *aux )
{
    (posicao % 8 == 0) ? fread(aux, 1, 1, entrada) : NULL == NULL ;

    return !!((*aux) & (1 << (posicao % 8)));
}

void erroArquivo()
{
    printf("Arquivo nao encontrado\n");
    exit(0);
}

void CompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    getByteFrequency(entrada, listaBytes);

    nodeArvore *raiz = BuildHuffmanTree(listaBytes);

    fwrite(listaBytes, 256, sizeof(listaBytes[0]), saida);

    fseek(saida, sizeof(unsigned int), SEEK_CUR);

    byte c;
    unsigned tamanho = 0;
    byte aux = 0;

    while (fread(&c, 1, 1, entrada) >= 1)
    {

        char buffer[1024] = {0};

        pegaCodigo(raiz, c, buffer, 0);

        for (char *i = buffer; *i; i++)
        {
            if (*i == '1')
            {
                aux = aux | (1 << (tamanho % 8));
            }

            tamanho++;

            if (tamanho % 8 == 0)
            {
                fwrite(&aux, 1, 1, saida);
                aux = 0;
            }
        }
    }

    fwrite(&aux, 1, 1, saida);

    fseek(saida, 256 * sizeof(unsigned int), SEEK_SET);

    fwrite(&tamanho, 1, sizeof(unsigned), saida);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    FreeHuffmanTree(raiz);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de compressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(entrada);
    fclose(saida);

}

void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    fread(listaBytes, 256, sizeof(listaBytes[0]), entrada);

    nodeArvore *raiz = BuildHuffmanTree(listaBytes);

    unsigned tamanho;
    fread(&tamanho, 1, sizeof(tamanho), entrada);

    unsigned posicao = 0;
    byte aux = 0;

    while (posicao < tamanho)
    {
        nodeArvore *nodeAtual = raiz;

        while ( nodeAtual->esquerda || nodeAtual->direita )
        {
            nodeAtual = geraBit(entrada, posicao++, &aux) ? nodeAtual->direita : nodeAtual->esquerda;
        }

        fwrite(&(nodeAtual->c), 1, 1, saida);
    }

    FreeHuffmanTree(raiz);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de descompressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(saida);
    fclose(entrada);
}