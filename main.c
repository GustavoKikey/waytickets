#include <stdio.h>
#include <stdlib.h>

int mesas[30];
int precos[5] = {1000, 800, 600, 400, 200};

int main () {
    int close = 1;
    int mesas_reservadas = 0;
    // popular o vetor mesas com a quantidade de lugares disponiveis
    for (int i = 0; i < 30; i++) {
        mesas[i] = 5;
    }
    while( !(close == 0) ) {
        printf(" ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄\n");
        printf("▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n");
        printf("▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌\n");
        printf("▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
        printf("▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
        printf("▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
        printf("▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
        printf("▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
        printf("▐░▌          ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌\n");
        printf("▐░▌          ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n");
        printf(" ▀            ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ \n");
        printf("\n");
        int d = 0;
        for(int i = 0; i < 30; i++) {
            printf("Mesa %d[%d/5] ", i + 100, mesas[i]);
            d = d + 1;
            if (i == 5) {
                printf(" R$ %d\n", precos[0]);
            }
            if (i == 11) {
                printf(" R$ %d\n", precos[1]);
            }
            if (i == 17) {
                printf(" R$ %d\n", precos[2]);
            }
            if (i == 23) {
                printf(" R$ %d\n", precos[3]);
            }
            if (i == 29) {
                printf(" R$ %d\n", precos[4]);
            }
        }
        printf("\n");

        int mesa_escolhida;
        int qtd_lugares;
        int verificador_mesa_escolhida = 0;
        while (verificador_mesa_escolhida == 0) {
            printf("Digite o codigo da mesa que voce deseja: ");       
            scanf("%d", &mesa_escolhida);
            if (verifica_mesa(mesa_escolhida) == 1) {
                verificador_mesa_escolhida = 1;
            }
        }

        int verificador_lugares = 0;
        while (verificador_lugares == 0) {
            printf("A mesa escolhida tem %d lugares disponiveis\n", mesas[mesa_escolhida -100]);
            printf("Quantos lugares voce deseja? ");
            scanf("%d", &qtd_lugares);
            if (verifica_lugares(mesa_escolhida, qtd_lugares) == 1) {
                verificador_lugares = 1;
            }
        }

        confirma_mesa(mesa_escolhida, qtd_lugares);

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

int confirma_mesa (int mesa_escolhida, int qtd_lugares) {
    int decisao;
    printf("#########################################\n");
    printf("# Você escholheu a mesa %d e %d lugares #\n", mesa_escolhida, qtd_lugares);
    printf("#########################################\n");
    printf("# TOTAL:  R$ %d,00\n", calcula_preco(mesa_escolhida, qtd_lugares));
    printf("#########################################\n");
    int verifica_decisao = 0;
    while (verifica_decisao == 0) {
        printf("Para confirmar, digite 1. Para cancelar, digite 0: ");
        scanf("%d", &decisao);
        if (decisao == 1) {
            mesas[mesa_escolhida - 100] = mesas[mesa_escolhida - 100] - qtd_lugares;
            verifica_decisao = 1;
            printf("Mesa confirmada!\n");
        } else if (decisao == 0) {
            verifica_decisao = 1;
            printf("Voce cancelou a reserva!\n");
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