#include "verificaAVL.h"
int verificaAVL(No *ptr)
{
    int peso_esq, peso_dir, diferenca;
    if (ptr == NULL)
        return 1;
    peso_esq = peso(ptr->esq);
    peso_dir = peso(ptr->dir);
    diferenca = peso_esq > peso_dir ? peso_esq - peso_dir : peso_dir - peso_esq;
    if (diferenca <= 1 && verificaAVL(ptr->esq) && verificaAVL(ptr->dir))
        return 1;
    return 0;
}

int peso(No *ptr)
{
    int peso_esq, peso_dir;

    if (ptr == NULL)
        return 0;

    peso_esq = peso(ptr->esq);
    peso_dir = peso(ptr->dir);

    if (peso_esq > peso_dir)
        return 1 + peso_esq;
    else
        return 1 + peso_dir;
}