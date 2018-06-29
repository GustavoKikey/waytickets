#ifndef _MESA_
#define _MESA_

#include "../desenha/desenha.h"

int mesas[30];
int precos[5];
int mesas_escolhidas[30];
int lugares_escolhidos[30];

int mesas_reservadas;

void inicia_mesas();
void escolher_mesa();
int verificar_disponibilidade (int mesa, int qtd_lugares);
void adicionar_mesa (int mesa, int qtd_lugares);
int calcula_preco (int mesa, int qtd_lugares);
void confirma_mesa();
void cancela_mesa();
void limpa_mesas_escolhidas();
#endif