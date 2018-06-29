#include <stdio.h>
#include "mesa.h"

void confirma_mesa ()
{
    desenha_preco_total();
    printf("Para confirmar a escolha, digite 1\n");
    printf("Para cancelar, digite 2\n");
    int decisao;
    while (1 == 1) {
        scanf("%d", &decisao);
        if (decisao == 1) {
            limpa_mesas_escolhidas();
            printf("Voce confirmou a mesa!\n");
            break;
        } else if (decisao == 2) {
            cancela_mesa();
            printf("Voce cancelou a compra");
            break;
        } else {
            printf("Voce digitou um caractere invalido!\n");
            printf("Para confirmar a escolha, digite 1\n");
            printf("Para cancelar, digite 2\n");
        }
    }
    
}