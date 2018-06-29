#include <stdio.h>
#include "mesa.h"

void adicionar_mesa (int mesa, int qtd_lugares) 
{
    mesas[mesa - 100] = mesas[mesa - 100] - qtd_lugares;
    mesas_escolhidas[mesa - 100] = mesas_escolhidas[mesa - 100] + qtd_lugares;
}