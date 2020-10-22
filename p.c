/*

int adicionar(No **arv, int matricula, float preco)
{
    inserir(arv, matricula, preco);
    if (arv == NULL)
    {
        return 0;
    }
    return 1;
}

No *cria_no(int matricula, float preco)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->a->matricula = matricula;
    novo->a->preco = preco;
    return novo;
}

No *inserir(No **arv, int matricula, float preco)
{
    No *novo;
    novo = cria_no(matricula, preco);

    if (arv == NULL)
    {
        *arv = novo;
    }
    else
    {
        if (novo->a->matricula <= (*arv)->a->matricula)
        {
            if ((*arv)->filho_dir == NULL)
            {
                (*arv)->filho_dir = novo;
            }
            else
            {
                inserir(&(*arv)->filho_dir, matricula, preco);
            }
        }
        else
        {
            if ((*arv)->filho_esq == NULL)
            {
                (*arv)->filho_esq = novo;
            }
            else
            {
                inserir(&(*arv)->filho_dir, matricula, preco);
            }
        }
    }
    return *arv;
}

int preco(No **arv, int matricula)
{
    if (arv == NULL)
    {
        printf("produto %d não foi encontrado", matricula);
        return 0;
    }

    else if ((*arv)->a->matricula == matricula || preco(&(*arv)->filho_esq, matricula) || preco(&(*arv)->filho_dir, matricula))
    {
        printf("o produto %d custa R$%f", matricula, (*arv)->a->preco);
        return 1;
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
*/