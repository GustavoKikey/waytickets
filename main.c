#include <stdio.h>
#include <stdlib.h>

#include "./desenha/desenha.h"
#include "./mesa/mesa.h"

// int mesas[30];
// int precos[5] = {1000, 800, 600, 400, 200};
// int mesas_escolhidas[30];
// int lugares_escolhidos[30];



int main ()
{
    inicia_mesas();
    int close = 1;

    while( !(close == 0) ) {
        desenha_palco();
        desenha_mesas(mesas, precos);

        escolher_mesa();

        confirma_mesa();

        printf("Digite 0 para fechar o programa ou 1 para continuar comprando: ");
        scanf("%d", &close);

    }
}