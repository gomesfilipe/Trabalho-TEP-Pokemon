#ifndef VENUSAUR_H
#define VENUSAUR_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"
#include "../jogo.h"

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Venusaur.
 * @return Pokemon Venusaur inicializado.
 **/
Pokemon* criaVenusaur();

/**
 * @brief Aplica o ataque Pó de Sono.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 * @param f Ponteiro para arquivo.
 **/
void poDeSono(Pokemon *venusaur, Pokemon *defensor, FILE *f);

/**
 * @brief Aplica o ataque Bomba de Semente.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 * @param f Ponteiro para arquivo.

 **/
void bombaDeSemente(Pokemon *venusaur, Pokemon *defensor, FILE *f);

/**
 * @brief Aplica o ataque Dois Gumes.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 * @param f Ponteiro para arquivo.
 **/
void doisGumes(Pokemon *venusaur, Pokemon *defensor, FILE *f);

#endif
