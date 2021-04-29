#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include "pokemons/blastoise.h"
#include "pokemons/charizard.h"
#include "pokemons/mew.h"
#include "pokemons/pikachu.h"
#include "pokemons/steelix.h"
#include "pokemons/venusaur.h"

typedef Pokemon* (*fptrInic) ();
fptrInic inicPokemons['V' + 1];

/**
 * @brief Inicializa o vetor de ponteiros de função para criação dos pokemons implementados.
 **/
void iniciaTabelaCriacaoPokemons();

/**
 * @brief Escolhe uma pokémon com base em sua "chave".
 * @param code Caractere inicial do pokemon a ser escolhido. Por exemplo, se code == 'P', será escolhido o Pikachu.
 * @return Pokemon do determinado code criado e inicializado.
 **/
Pokemon* escolhePokemon(char code);

#endif