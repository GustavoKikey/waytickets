#include <stdio.h>
#include "desenha.h"


void desenha_preco_mesa (int mesa, int qtd_lugares)
{
    printf("##########################\n");
    printf("# MESA # LUGARES # PRECO #\n");
    printf("##########################\n");
    printf("# %d # %d # R$%d\n", mesa, qtd_lugares, calcula_preco(mesa, qtd_lugares));
    printf("##########################\n");
}

void desenha_preco_total ()
{
    printf("##########################\n");
    printf("# MESAS # LUGARES # PRECO #\n");
    int i;
    int total = 0;
    for (i = 0; i <= 29; i++) {
        int mesa_escolhida = mesas_escolhidas[i];
        if (mesa_escolhida > 0) {
            int preco = calcula_preco(i +100, mesa_escolhida);
            total += preco;
            printf("# %d # %d # R$%d\n", i + 100, mesa_escolhida, preco);
        } else {
            continue;
        }
    }
    printf("##########################\n");
    printf("### TOTAL = R$ %d\n", total);
    printf("##########################\n");
}