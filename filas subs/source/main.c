
#include "questao.h"
int main(void)
{
    int OP, aux;
    FILA *f;
    FILA *fb; /* inicializar f*/
    PILHA *g;
    g = cria_pilha();
    f = cria_fila();
    fb = cria_fila();

    while (1)
    {
        puts("");
        puts("");
        printf("digite o numero :\n"
               "1 - inserir na fila\n"
               "2 - retirar da fila\n"
               "3 - pegar primeiro numero da fila\n"
               "4 - liberar fila\n"
               "5 - imprime tamanho da fila\n"
               "6- imprime fila\n"
               "7 - exibe inverso da fila\n"
               "8 - retira impar\n" /* deu erro*/
               "9 - inverte fila\n"
               "0 - encerra programa\n");
        puts("");
        puts("");
        scanf("%d", &OP);
        switch (OP)
        {

        case 1:
            puts("Digite o número que deseja inserir");
            scanf("%d", &aux);
            enqueue(f, aux);
            printf("elemento %d inserido na fila\n", aux);
            break;
        case 2:
            aux = dequeue(f);
            printf("numero %d retirado da fila\n", aux);
            break;
        case 3:
            aux = get_first(f);
            printf("numero %d da fila armazenado em aux\n", aux);
            break;
        case 4:
            clear(f);
            break;
        case 5:
            printf("%d\n", size(f));
            break;
        case 6:
            imprime(f);
            break;
        case 7:
            exibir_inverso(f);
            break;
        case 8:
            retira_impar(f, fb); /* fila vazia*/
            break;
        case 9:
            inverter(f, g);
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}