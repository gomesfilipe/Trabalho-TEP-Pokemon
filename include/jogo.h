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

/**
 * @brief Inicializa a matriz que indica o valor de "relacaoTipo" numa batalha entre pokemons.
 * @param m Matriz que relaciona o pokemon atacante vs o pokemon defensor para descobrir o valor de "relacaoTipo".
 **/
void inicializaMatrizRelacaoTipos(float m[QTDTIPOS][QTDTIPOS]);

/**
 * @brief Calcula o dano de um ataque de um pokemon com base em seus parâmetros.
 * @param A Ataque base do pokemon.
 * @param D Defesa base do pokemon.
 * @param poder Poder do ataque.
 * @param critico Valor que indica se o dano dobrará ou não.
 * @param MT Valor que relaciona um determinado ataque com o tipo do pokemón que o usa.
 * @param relacaoTipo Valor que indica a "força" de um pokemon sobre o outro.
 * @return Dano causado ao pokemon defensor por um ataque.
 **/
float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo);

#endif