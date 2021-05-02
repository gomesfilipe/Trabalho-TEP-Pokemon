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

/**
 * @brief Captura o ponteiro para a lista de pokemons de um jogador.
 * @param jogador Jogador que terá sua lista de pokemons capturada.
 * @return Ponteiro para a lista de pokemons do jogador.
 **/
Lista* getListaPokemons(Jogador* jogador);

/**
 * @brief Atualiza a lista de pokemons de um jogador.
 * @param jogador Jogador que terá sua lista de pokemons atualizada.
 * @param listaPokemons Ponteiro para a lista de pokemons do jogador.
 * @return Jogador com sua lista de pokemons atualizada.
**/
Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons);

#endif