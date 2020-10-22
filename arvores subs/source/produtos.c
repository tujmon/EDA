#include <stdio.h>
#include <stdlib.h>

#include "produtos.h"

No *cria_produto(int matricula, float preco)
{
    Prod *prod = (Prod *)malloc(sizeof(Prod));
    No *no = (No *)malloc(sizeof(No));
    prod->matricula = matricula;
    prod->preco = preco;
    no->dir = NULL;
    no->esq = NULL;
    no->dados = prod;
    return no;
}

int adicionar(No **raiz, int matricula, float preco)
{
    No *novo = cria_produto(matricula, preco);
    if (*raiz == NULL)
    {
        *raiz = novo;
        return 0;
    }
    else
    {
        if (novo->dados->matricula >= (*raiz)->dados->matricula)
        {
            if ((*raiz)->dir == NULL)
            {
                (*raiz)->dir = novo;
            }
            else
            {
                adicionar(&(*raiz)->dir, matricula, preco);
            }
        }
        else
        {
            if ((*raiz)->esq == NULL)
            {
                (*raiz)->esq = novo;
            }
            else
            {
                adicionar(&(*raiz)->esq, matricula, preco);
            }
        }
    }
    return 0;
}

int preco(No **arv, int matricula)
{
    while (*arv != NULL)
    {
        if (matricula > (*arv)->dados->matricula)
        {
            return preco(&(*arv)->dir, matricula);
        }
        else if (matricula < (*arv)->dados->matricula)
        {
            return preco(&(*arv)->esq, matricula);
        }
        else
        {
            printf("o produto %d custa %.2f.\n", (*arv)->dados->matricula, (*arv)->dados->preco);
            return 1;
        }
    }
    printf("Erro: produto %d nao encontrado!\n", matricula);
    return 0;
}

int num_nos(No *arv)
{
    if (arv == NULL)
        return 0;
    else
    {
        int conte = num_nos(arv->esq);
        int contd = num_nos(arv->dir);
        return conte + contd + 1;
    }
}
int num_folhas(No *arv)
{
    if (!arv)
        return (0);
    else if ((arv->esq) == NULL && (arv->dir) == NULL)
        return (1);
    return (num_folhas(arv->esq) + num_folhas(arv->dir));
}

int altura_arvore(No *arv)
{
    if (arv == NULL)
        return -1;
    else
    {
        int he = altura_arvore(arv->esq);
        int hd = altura_arvore(arv->dir);
        if (he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

float maior(No *subarvore)
{
    float maior_inf, inf_atual, inf_esquerda, inf_direita;

    inf_atual = subarvore->dados->preco;

    maior_inf = inf_atual;
    if (subarvore->esq != NULL)
    {
        inf_esquerda = maior(subarvore->esq);

        if (inf_esquerda > maior_inf)
        {
            maior_inf = inf_esquerda;
        }
    }
    if (subarvore->dir != NULL)
    {
        inf_direita = maior(subarvore->dir);

        if (inf_direita > maior_inf)
        {
            maior_inf = inf_direita;
        }
    }
    return maior_inf;
}

int elimina(No **arv, int matricula)
{
    while (*arv != NULL)
    {
        if (matricula > (*arv)->dados->matricula)
        {
            return preco(&(*arv)->dir, matricula);
        }
        else if (matricula < (*arv)->dados->matricula)
        {
            return preco(&(*arv)->esq, matricula);
        }
        else
        {
        }
    }
    return 0;
}

void remove_no(No **arv, int matricula)
{
    if ((*arv) == NULL)
        return;
    if (matricula < (*arv)->dados->matricula)
        remove_no(&(*arv)->esq, matricula);
    if (matricula > (*arv)->dados->matricula)
        remove_no(&(*arv)->dir, matricula);
    else if (matricula == (*arv)->dados->matricula)
    {

        No *aux = (*arv);
        if ((*arv)->esq == NULL && (*arv)->dir == NULL)
        {
            free(aux);
            (*arv) = NULL;
        }
        else if ((*arv)->esq == NULL)
        {
            (*arv) = (*arv)->dir;
            aux->dir = NULL;
            free(aux);
            aux = NULL;
        }
        else if ((*arv)->dir == NULL)
        {
            (*arv) = (*arv)->esq;
            aux->esq = NULL;
            free(aux);
            aux = NULL;
        }

        else
        {
            aux = MenorNo((*arv)->dir);

            aux->esq = (*arv)->esq;
            aux->dir = (*arv)->dir;

            free((*arv));
            (*arv)->esq = (*arv)->dir = NULL;
            (*arv) = aux;
            aux = NULL;
        }
    }
}

No *MenorNo(No *root)
{
    if (root->esq != NULL)
        return MenorNo(root->esq);
    else
    {
        No *aux = root;
        if (root->dir != NULL)
            root = root->dir;
        else
            root = NULL;
        return aux;
    }
}