#include <stdio.h>
#include <stdlib.h>

#include "desenha.h"

int mesas[30];
int precos[5] = {1000, 800, 600, 400, 200};
int mesas_escolhidas[30];
int lugares_escolhidos[30];

int main () {
    int close = 1;
    int mesas_reservadas = 0;
    for (int i = 0; i < 30; i++) {
        mesas[i] = 5;
    }
    while( !(close == 0) ) {

        desenha_palco();
        desenha_mesas(mesas, precos);

        char mesa_escolhida_string[5];
        int mesa_escolhida;

        char qtd_lugares_string[5];
        int qtd_lugares;

        int i;
        for(i = 0; i <= 30; i++) {
            int verificador_mesa_escolhida = 0;
            while (verificador_mesa_escolhida == 0) {
                printf("Digite o codigo da mesa que voce deseja: ");       
                scanf("%s", mesa_escolhida_string);
                mesa_escolhida = atoi(mesa_escolhida_string);
                if (verifica_mesa(mesa_escolhida) == 1) {
                    verificador_mesa_escolhida = 1;
                }
            }

            int verificador_lugares = 0;
            while (verificador_lugares == 0) {
                printf("A mesa escolhida tem %d lugares disponiveis\n", mesas[mesa_escolhida -100]);
                printf("Quantos lugares voce deseja? ");
                scanf("%s", qtd_lugares_string);
                qtd_lugares = atoi(qtd_lugares_string);
                if (verifica_lugares(mesa_escolhida, qtd_lugares) == 1) {
                    verificador_lugares = 1;
                }
            }

            int compra_confirmada;
            compra_confirmada = confirma_mesa(mesa_escolhida, qtd_lugares, i);

            if (compra_confirmada == 1) {
                break;
            }
        }

        printf("Digite 0 para fechar o programa ou 1 para continuar comprando: ");
        scanf("%d", &close);
    }
}

int verifica_mesa (int mesa_escolhida) {
    if (mesa_escolhida < 100 || mesa_escolhida > 129) {
        printf("ESSA MESA MAO EXISTE!\n");
        printf("Por favor, escolha outra!\n");
        return 0;
    } else if (mesas[mesa_escolhida - 100] == 0) {
        printf("Essa mesa não tem lugares disponiveis\n");
        printf("Por favor, escolha outra!\n");
        return 0;
    } else {
        return 1;
    }
}

int verifica_lugares (int mesa, int qtd_lugares) {
    if (qtd_lugares == 0) {
        printf("Voce não escolheu nenhum lugar!");
        return 0;
    }
    if (mesas[mesa - 100] >= qtd_lugares) {
        return 1;
    } else {
        printf("A mesa %d não tem %d lugares disponiveis\n", mesa, qtd_lugares);
        return 0;
    }
}

int confirma_mesa (int mesa_escolhida, int qtd_lugares, int i) {
    int decisao;
    mesas[mesa_escolhida - 100] = mesas[mesa_escolhida - 100] - qtd_lugares;
    mesas_escolhidas[i] = mesa_escolhida;
    lugares_escolhidos[i] = qtd_lugares;
    printf("###########################\n");
    printf("# MESA # LUGARES # TOTAL #\n");
    printf("###########################\n");
    int j;
    int total = 0;
    for(j = i; j >=0; j--) {
        int preco = calcula_preco(mesas_escolhidas[j], lugares_escolhidos[j]);
        total = total + preco;
        printf("# %d   # %d      # R$%d #\n", mesas_escolhidas[j], lugares_escolhidos[j], preco);
    }
    printf("###########################\n");
    printf("# TOTAL            R$%d #\n", total);

    int verifica_decisao = 0;
    while (verifica_decisao == 0) {
        printf("Para adicionar mais uma mesa, digite 1\n");
        printf("Para confirmar a compra, digite 2\n");
        printf("Para cancelar a compra, digite 0\n");
        scanf("%d", &decisao);
        if (decisao == 1) {
            return 0;
        } else if (decisao == 2) {
            // CONFIRMAR COMPRA
            return 1;
        } else if (decisao == 0) {
            return 1;
        } else {
            printf("VOCE DIGITOU UM CARACTERE INVALIDO\n");
        }
    }
}

int calcula_preco (int mesa_escolhida, int qtd_lugares) {
    int i = mesa_escolhida - 100;
    if (i <= 5) {
        return (precos[0] / 5) * qtd_lugares;
    } else if (i <= 11) {
        return (precos[1] / 5) * qtd_lugares;
    } else if (i <= 17) {
        return (precos[2] / 5) * qtd_lugares;
    } else if (i <= 23) {
        return (precos[3] / 5) * qtd_lugares;
    } else if (i <= 29) {
        return (precos[4] / 5) * qtd_lugares;
    }
}