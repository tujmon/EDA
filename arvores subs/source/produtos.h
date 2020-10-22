#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    int matricula;
    float preco;
} Prod;

typedef struct arvore
{
    struct Produto *dados;
    struct arvore *dir, *esq;
} No;

int adicionar(No **raiz, int matricula, float preco);
int preco(No **arv, int matricula);
int num_nos(No *arv);
int num_folhas(No *arv);
int altura_arvore(No *arv);
float preco_maximo(No **arv);
void imprime(No *a);
float maior(No *subarvore);
No *MenorNo(No *root);
void remove_no(No **arv, int matricula);
#endif