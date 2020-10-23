#include <stdio.h>
#include <stdlib.h>
struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
#ifndef questao1a5_H
#define questao1a5_H
typedef struct no No;

typedef struct fila
{
    No *ini;
    No *fim;
} FILA;

struct elem
{
    int info;
    struct elem *prox;
};
typedef struct elem elementos;

typedef struct pilha
{
    elementos *prim;
} PILHA;

No *get_first(No *a);
void clear(FILA *f);
int size(FILA *f);
void exibir_inverso(FILA *a);
int pop(PILHA *a);
elementos *ret_ini_pilha(elementos *l);
void push(PILHA *p, int v);
int pilha_vazia(PILHA *a);
elementos *ins_ini(elementos *l, float v);
No *ins_fim(No *fim, float v);
No *ret_ini_fila(No *ini);
int dequeue(FILA *f);
void enqueue(FILA *f, int info);
int vazia_fila(FILA *f);
FILA *inverter(FILA *a, PILHA *b);
#endif