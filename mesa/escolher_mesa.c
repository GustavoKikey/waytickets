#include <stdio.h>
#include "mesa.h"

void escolher_mesa ()
{
    while (1 == 1) {
        int mesa_escolhida;
        int qtd_lugares;
        printf("Digite o codigo da mesa que voce deseja: ");
        scanf("%d", &mesa_escolhida);
        printf("Digite quantos lugares você deseja: ");
        scanf("%d", &qtd_lugares);
        if (verificar_disponibilidade(mesa_escolhida, qtd_lugares) == 1) {
            desenha_preco_mesa(mesa_escolhida, qtd_lugares);
            printf("Digite 1 para adicionar\n");
            printf("Digite 0 para cancelar\n");
            int decisao;
            scanf("%d", &decisao);
            if (decisao == 1) {
                printf("Voce adicionou a mesa!\n");
                adicionar_mesa(mesa_escolhida, qtd_lugares);
            } else if (decisao == 2) {
                printf("Voce nao adicionou a messa %d\n", mesa_escolhida);
            } else {
                printf("Voce digitou um caractere invalido!\n");
            }
        }
        printf("Digite 1 para adicionar mais mesas\n");
        printf("Digite 2 para continuar\n");
        int decisao;
        scanf("%d", &decisao);
        if (decisao == 1) {
            continue;
        } else if (decisao == 2){
            break;
        } else {
            printf("Voce digitou um caractere invalido!\n");
            continue;
        }
    }
}