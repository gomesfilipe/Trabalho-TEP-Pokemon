#ifndef TELAS_H
#define TELAS_H

#include "pokemon.h"
#include "jogador.h"
#include "jogo.h"
#include "utils.h"

#define TAM 100

void batalha(Jogador* jogador);

void melhoresPontuacoes();

void sair();

void jogar();

void menuInicial();

void limpaTela();

void imprimeEstadoQuandoNaoPodeJogar(Pokemon *pokemon);

#endif