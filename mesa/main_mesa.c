#include <stdio.h>
#include "mesa.h"

int mesas[30];
int precos[5] = {1000, 800, 600, 400, 200};
int mesas_escolhidas[30];

int mesas_reservadas = 0;

void inicia_mesas ()
{
    for (int i = 0; i < 30; i++) {
        mesas[i] = 5;
        mesas_escolhidas[i] = 0;
    }
}