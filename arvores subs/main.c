#include "produtos.h"
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