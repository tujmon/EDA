#include <stdio.h>
typedef struct no
{
    struct no *esq;
    int info;
    struct no *dir;
} No;

int verificaAVL(No *ptr);
int peso(No *ptr);