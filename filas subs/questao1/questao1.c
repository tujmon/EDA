#include "questao1.h"
No *get_first(No *a)
{
    No *p = a->prox;
    free(a);
    return p;
}
void clear(FILA *f)
{
    No *q = f->ini;
    while (q != NULL)
    {
        No *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}
int size(FILA *f)
{
    No *q;
    int count = 0;
    for (q = f->ini; q != NULL; q = q->prox)
        count++;
    return count;
}

void exibir_inverso(FILA *a)
{
    No *q;
    for (q = a->fim; q != NULL; q = q->ant)
        printf("%d\n", q->info);
}

FILA *inverter(FILA *a, PILHA *b)
{
    pilha_vazia(b);
    while (a != NULL)
        push(b, dequeue(a));
    while (b != NULL)
        enqueue(a, pop(b));
    return a;
}

//FILAS

void enqueue(FILA *f, int info)
{
    f->fim = ins_fim(f->fim, info);
    if (f->ini == NULL)
        f->ini = f->fim;
}
int dequeue(FILA *f)
{
    float v;
    if (vazia_fila(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    v = f->ini->info;
    f->ini = get_first(f->ini);
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}
No *ins_fim(No *fim, float v)
{
    No *p = (No *)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;
    return p;
}

int vazia_fila(FILA *f)
{
    return (f->ini == NULL);
}
//pilha
void push(PILHA *p, int v)
{
    p->prim = ins_ini(p->prim, v);
}

int pop(PILHA *p)
{
    float v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->prim->info;
    p->prim = ret_ini_pilha(p->prim);
    return v;
}
elementos *ret_ini_pilha(elementos *l)
{
    elementos *p = l->prox;
    free(l);
    return p;
}
int pilha_vazia(PILHA *a)
{
    return (a->prim == NULL);
}
elementos *ins_ini(elementos *l, float v)
{
    elementos *p = (elementos *)malloc(sizeof(elementos));
    p->info = v;
    p->prox = l;
    return p;
}