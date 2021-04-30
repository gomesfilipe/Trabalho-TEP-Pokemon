#ifndef STEELIX_H
#define STEELIX_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Steelix.
 * @return Pokemon Steelix inicializado.
 **/
Pokemon* criaSteelix();

/**
 * @brief Aplica o ataque Rabo de Ferro.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void raboDeFerro(Pokemon *steelix, Pokemon *defensor);

/**
 * @brief Aplica o ataque Dormir.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void dormir(Pokemon *steelix, Pokemon *defensor);

/**
 * @brief Aplica o ataque Cavar.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void cavar(Pokemon *steelix, Pokemon *defensor);

#endif