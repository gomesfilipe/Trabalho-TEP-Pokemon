#ifndef PIKACHU_H
#define PIKACHU_H

#include <stdio.h>
#include <stdlib.h>
#include "../pokemon.h"
#include "../jogo.h"

/**
 * @brief Chama a função criaPokemon e inicializa com os atributos do Pikachu.
 * @return Pokemon Pikachu inicializado.
 **/
Pokemon* criaPikachu();

/**
 * @brief Aplica o ataque Choque do Trovão.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void choqueDoTrovao(Pokemon *pikachu, Pokemon *defensor);

/**
 * @brief Aplica o ataque Onda de Choque.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void ondaDeChoque(Pokemon *pikachu, Pokemon *defensor);

/**
 * @brief Aplica o ataque bater. Como outros pokemons também possuem esse ataque, estamos implementando esse daqui apenas nessa biblioteca.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void bater(Pokemon *atacante, Pokemon *defensor);

#endif