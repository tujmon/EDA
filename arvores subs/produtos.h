#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdio.h>
#include <stdlib.h>

struct prod
{
    int matricula;
    float preco;
};
typedef struct prod produto;

struct arv
{
    produto *a;
    struct arv *filho_esq;
    struct arv *filho_dir;
};
typedef struct arv No;

int adicionar(No **arv, int matricula, float preco);
No *inserir(No **arv, int matricula, float preco);
int preco(No **arv, int matricula);
int num_folhas(No *arv);
int altura_arvore(No *arv);
int num_nos(No *arv);

#endif