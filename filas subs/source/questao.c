#include "questao.h"

/*funções fila*/

FILA *cria_fila(void)
{
    FILA *f = (FILA *)malloc(sizeof(FILA));
    f->ini = f->fim = NULL;
    return f;
}
void imprime(FILA *f)
{
    No *q;
    printf("|");
    for (q = f->ini; q != NULL; q = q->prox)
        printf("%d|", q->info);
}

int get_first(FILA *a)
{
    int b = a->ini->info;
    return b;
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
    int aux = size(a);
    int vet[aux + 1];
    No *q;
    int i = 0;
    for (q = a->ini; q != NULL; q = q->prox)
    {
        vet[i] = q->info;
        i++;
    }
    for (i = aux - 1; i >= 0; i--)
    {
        printf("%d,", vet[i]);
    }
    puts("");
}

void inverter(FILA *a, PILHA *b)
{

    if (!vazia_fila(a))
    {
        push(b, dequeue(a));
        inverter(a, b);
    }
    if (!pilha_vazia(b))
    {
        enqueue(a, pop(b));
    }
}

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
    f->ini = ret_ini_fila(f->ini);
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}
No *ret_ini_fila(No *ini)
{
    No *p = ini->prox;
    free(ini);
    return p;
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

void retira_impar(FILA *a, FILA *b)
{
    int aux;
    if (!vazia_fila(a))
    {
        aux = dequeue(a);
        if (aux % 2 == 0)
        {
            enqueue(b, aux);
        }

        retira_impar(a, b);
    }
    if (!vazia_fila(b))
    {
        enqueue(a, dequeue(b));
    }
}

/* funções Pilha*/
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

elementos *ret_ini_pilha(elementos *l)
{
    elementos *p = l->prox;
    free(l);
    return p;
}
PILHA *cria_pilha(void)
{
    PILHA *p = (PILHA *)malloc(sizeof(PILHA));
    p->prim = NULL;
    return p;
}