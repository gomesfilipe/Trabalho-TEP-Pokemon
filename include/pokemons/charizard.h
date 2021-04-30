#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"
#include "../jogo.h"

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Charizard.
 * @return Pokemon Charizard inicializado.
 **/
Pokemon* criaCharizard();

/**
 * @brief Aplica o ataque Lança Chamas.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void lancaChamas(Pokemon *charizard, Pokemon *defensor);

/**
 * @brief Aplica o ataque Dormir.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void dormirCharizard(Pokemon* charizard, Pokemon* defensor);

/**
 * @brief Aplica o ataque Bater.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void baterCharizard(Pokemon *charizard, Pokemon *defensor);

#endif