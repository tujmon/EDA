#include "produtos.h"

int adicionar(No **arv, int matricula, float preco)
{
    adicionar(arv, matricula, preco);
    if (arv == NULL)
    {
        return 1;
    }
    return 0;
}

No *inserir(No **arv, int matricula, float preco)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        return NULL;
    }
    novo->a->preco = preco;
    novo->a->matricula = matricula;
    novo->filho_esq = NULL;
    novo->filho_dir = NULL;

    if (*arv == NULL)
    {
        *arv = novo;
        return *arv;
    }

    if (matricula == (*arv)->a->matricula)
    {
        free(novo);
        return NULL;
    }

    else
    {

        if (matricula < (*arv)->a->matricula)
        {
            (*arv)->filho_esq = inserir(&(*arv)->filho_esq, matricula, preco);
        }

        else
        {
            (*arv)->filho_dir = inserir(&(*arv)->filho_dir, matricula, preco);
        }
    }

    return novo;
}

int preco(No **arv, int matricula)
{
    if (arv == NULL)
    {
        printf("produto %d não foi encontrado", matricula);
        return 1; /* árvore vazia: não encontrou */
    }

    else if ((*arv)->a->matricula == matricula || preco(&(*arv)->filho_esq, matricula) || preco(&(*arv)->filho_dir, matricula))
    {
        printf("o produto %d custa R$%f", matricula, (*arv)->a->preco);
        return 0;
    }
    return 1;
}

int num_nos(No *arv)
{
    if (arv == NULL)
        return 0;
    else
    {
        int conte = num_nos(arv->filho_esq);
        int contd = num_nos(arv->filho_dir);
        return conte + contd + 1;
    }
}
int num_folhas(No *arv)
{
    if (!arv)
        return (0);
    else if ((arv->filho_esq) == NULL && (arv->filho_dir) == NULL)
        return (1);
    return (num_folhas(arv->filho_esq) + num_folhas(arv->filho_dir));
}

int altura_arvore(No *arv)
{
    if (arv == NULL)
        return -1;
    else
    {
        int he = altura_arvore(arv->filho_esq);
        int hd = altura_arvore(arv->filho_dir);
        if (he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

int main(void)
{
    No *arv = NULL;
    int errorCode;
    int a = 100;
    float b = 5.90;

    errorCode = adicionar(&arv, a, 5.90);
    errorCode = adicionar(&arv, 200, 8.40);
    errorCode = adicionar(&arv, 250, 2.20);
    errorCode = adicionar(&arv, 500, 3.80);
    errorCode = adicionar(&arv, 400, 5.60);
    errorCode = adicionar(&arv, 150, 7.90);
    errorCode = preco(&arv, 400);
    errorCode = preco(&arv, 240);
    errorCode = preco(&arv, 150);
    return 0;
}