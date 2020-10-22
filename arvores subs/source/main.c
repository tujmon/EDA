#include <stdio.h>
#include "produtos.h"
int main(void)
{
    No *arv = NULL;
    int errorCode;
    errorCode = adicionar(&arv, 100, 5.90);
    errorCode = adicionar(&arv, 90, 8.40);
    errorCode = adicionar(&arv, 250, 2.20);
    errorCode = adicionar(&arv, 500, 3.80);
    errorCode = adicionar(&arv, 400, 5.60);
    errorCode = adicionar(&arv, 150, 7.90);
    errorCode = preco(&arv, 400);
    errorCode = preco(&arv, 240);
    errorCode = preco(&arv, 150);
    errorCode = num_nos(arv);
    errorCode = num_folhas(arv);
    errorCode = altura_arvore(arv);
    printf("%d\n", errorCode);
    errorCode = preco(&arv, 90);
    remove_no(&arv, 90);
    errorCode = preco(&arv, 90);
    return 0;
}