#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

typedef struct jogador Jogador;


/**
 * @brief Nessa função o jogador tenta capturar uma pokebola. A tentativa possui uma chance C/12 de ser efetiva.
 * @param jogador É o jogador que tentará capturar uma pokebola.
 * @param C É o número de batalhas vencidas desde a útima pokebola.
 * @return  É o jogador que talvez terá uma pokebola a mais.
**/
Jogador* capturaPokebola(Jogador* jogador, int C);

/**
 * @brief Captura a quantidade de pokebolas de um jogador.
 * @param jogador Jogador que terá o campo "qtdPokebolas" capturado.
 * @return Quantidade de pokebolas que o jogador possui.
 **/
int getQtdPokebolas(Jogador* jogador);

#endif