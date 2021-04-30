#ifndef BLASTOISE_H
#define BLASTOISE_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Blastoise.
 * @return Pokemon Blastoise inicializado.
 **/
Pokemon* criaBlastoise();

/**
 * @brief Aplica o ataque Arma de Água.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void armaDeAgua(Pokemon *blastoise, Pokemon *defensor);

/**
 * @brief Aplica o ataque Proteger.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void proteger(Pokemon *blastoise, Pokemon *defensor);

/**
 * @brief Aplica o ataque Bater.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void bater(Pokemon *blastoise, Pokemon *defensor);

#endif