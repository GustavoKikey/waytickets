#include <stdio.h>
#include "mesa.h"

int calcula_preco (int mesa, int qtd_lugares)
{
    int i = mesa - 100;
    int preco = 0;
    if (i <= 5) {
        preco = (precos[0] / 5) * qtd_lugares;
    } else if (i <= 11) {
        preco = (precos[1] / 5) * qtd_lugares;
    } else if (i <= 17) {
        preco = (precos[2] / 5) * qtd_lugares;
    } else if (i <= 23) {
        preco = (precos[3] / 5) * qtd_lugares;
    } else if (i <= 29) {
        preco = (precos[4] / 5) * qtd_lugares;
    }
    return preco;
}