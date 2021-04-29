#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convencionando tipos de pokemons.
enum tipos {ELETRICO = 1, FOGO, AGUA, PLANTA, METAL, PSIQUICO};

// Convencionando possíveis estados do pokemon durante uma batalha.
enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR};

typedef struct pokemon Pokemon;

/**
 * @brief Aloca memória para um pokemon e inicializa um pokemon genérico.
 * @param nome Nome do pokemon.
 * @param hpMax Máximo de HP do pokemon.
 * @param ataque Força de ataque do pokemon.
 * @param defesa Resistência de defesa do pokémon.
 * @param estado Estado atual do pokémon durante a batalha.
 * @param tipo Tipo do pokemon.
 * @return Retorna um pokemon genérico.
**/
Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo);

//! funcao para testes, excluir depois
void imprimePokemon(Pokemon *p);

#endif