#include "huffman_privado.h"
#include <stdio.h>

nodeLista *novoNodeLista(nodeArvore *nArv);

nodeArvore *novoNodeArvore(byte c, int frequencia, nodeArvore *esquerda, nodeArvore *direita);

void insereLista(nodeLista *n, lista *l);

nodeArvore *popMinLista(lista *l);

void getByteFrequency(FILE *entrada, unsigned int *listaBytes);

int pegaCodigo(nodeArvore *n, byte c, char *buffer, int tamanho);

nodeArvore *BuildHuffmanTree(unsigned *listaBytes);

void FreeHuffmanTree(nodeArvore *n);

int geraBit(FILE *entrada, int posicao, byte *aux );

void erroArquivo();

void CompressFile(const char *arquivoEntrada, const char *arquivoSaida);

void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida);







