#include <stdio.h>
#include "mesa.h"

int verificar_disponibilidade (int mesa, int qtd_lugares)
{
    if (mesa > 129 || mesa < 100) {
        printf("Essa mesa nao existe\n");
        return 0;
    }

    if (mesas[mesa -100] >= qtd_lugares) {
        return 1;
    } else {
        printf("Essa mesa nao tem %d lugares\n", qtd_lugares);
        return 0;
    }
}