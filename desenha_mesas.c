#include <stdio.h>
#include "desenha.h"

void desenha_mesas (int mesas[], int precos[])
{
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
}