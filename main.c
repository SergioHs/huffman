#include "huffman_interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char *strdup(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n");
        printf("Opcoes:\n");
        printf("\t-c\tComprime\n");
        printf("\t-x\tDescomprime\n");
        printf("\nExemplo: ./huffman -c comprima.isso nisso.hx\n");
        return 0;
    }

    if (strcmp("-c", argv[1]) == 0)
    {
        if (strstr(argv[3], ".hx"))
        {
            CompressFile(argv[2], argv[3]);
        }
        else
        {
            printf("O arquivo resultante da compressao deve ter a extensao '.hx'.\n");
            printf("Exemplo: \n\t./huffman -c comprima.isso nisso.hx\n");
            return 0;
        }
    }
    else if (strcmp("-x", argv[1]) == 0)
    {
        if (strstr(argv[2], ".hx"))
        {
            DecompressFile(argv[2], argv[3]);
        }
        else
        {
            printf("O arquivo a ser descomprimido deve ter a extensao '.hx'.\n");
            printf("Exemplo: \n\t./huffman -x descomprime.hx nisso.extensao\n");
            return 0;
        }
    }
    else
    {
        printf("Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n");
        printf("Opcoes:\n");
        printf("\t-c\tComprime\n");
        printf("\t-x\tDescomprime\n");
        printf("\nExemplo: ./huffman -c comprima.isso nisso.hx\n");
        return 0;
    }

    //CompressFile("meslo.ttf", "meslo.hx");
    //DecompressFile("meslo.hx", "meslo_copy.ttf");

    return 0;
}