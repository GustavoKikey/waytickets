#include <stdio.h>
#include "mesa.h"

void cancela_mesa ()
{
    int i;
    for (i = 0; i <= 29; i++) {
        printf("%d", mesas[i]);
        mesas[i] = mesas[i] + mesas_escolhidas[i];
        mesas_escolhidas[i] = 0;
    }
}

void limpa_mesas_escolhidas ()
{
    int i;
    for (i = 0; i <= 29; i++) {
        mesas_escolhidas[i] = 0;
    }
}