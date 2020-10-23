#include <stdio.h>
#include <stdlib.h>

#ifndef questao_H
#define questao_H
/*struct com elementos da fila*/
struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no No;

/*fila*/
typedef struct fila
{
    No *ini;
    No *fim;
} FILA;

/*struct com elementos da pilha*/
struct elem
{
    int info;
    struct elem *prox;
};
typedef struct elem elementos;

/*pilhas*/
typedef struct pilha
{
    elementos *prim;
} PILHA;

/*funções filas*/
FILA *cria_fila(void);
int get_first(FILA *a);
void inverter(FILA *a, PILHA *b);
No *ins_fim(No *fim, float v);
No *ret_ini_fila(No *ini);
void clear(FILA *f);
int size(FILA *f);
void exibir_inverso(FILA *a);
int dequeue(FILA *f);
void enqueue(FILA *f, int info);
int vazia_fila(FILA *f);
void imprime(FILA *f);
void retira_impar(FILA *a, FILA *b);
/* Funções pilhas*/
PILHA *cria_pilha(void);
int pop(PILHA *a);
void push(PILHA *p, int v);
int pilha_vazia(PILHA *a);
elementos *ret_ini_pilha(elementos *l);
elementos *ins_ini(elementos *l, float v);

#endif