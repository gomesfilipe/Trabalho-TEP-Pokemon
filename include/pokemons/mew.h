#ifndef MEW_H
#define MEW_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"
#include "blastoise.h"
#include "charizard.h"
#include "pikachu.h"
#include "steelix.h"
#include "venusaur.h"

fptrAtaque todosAtaques[13];

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Mew.
 * @return Pokemon Mew inicializado.
 **/
Pokemon* criaMew();

/**
 * @brief Aplica o ataque Metronomo.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void metronomo(Pokemon *mew, Pokemon *defensor);

/**
 * @brief Aplica o ataque Bater.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void bater(Pokemon *mew, Pokemon *defensor);

/**
 * @brief Aplica o ataque Auto-Destruir.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void autoDestruir(Pokemon *mew, Pokemon *defensor);

void inicializaVetorComTodosAtaques();

#endif