#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDTIPOS 6

// Convencionando tipos de pokemons.
enum tipos {ELETRICO = 0, FOGO, AGUA, PLANTA, METAL, PSIQUICO};

// Convencionando possíveis estados do pokemon durante uma batalha.
enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO};

typedef struct pokemon Pokemon;

typedef void (*fptrAtaque) (Pokemon*, Pokemon*);

/**
 * @brief Aloca memória para um pokemon e inicializa um pokemon genérico.
 * @param nome Nome do pokemon.
 * @param hpMax Máximo de HP do pokemon.
 * @param ataque Força de ataque do pokemon.
 * @param defesa Resistência de defesa do pokémon.
 * @param estado Estado atual do pokémon durante a batalha.
 * @param tipo Tipo do pokemon.
 * @param atk1 Ponteiro para função do ataque 1 do pokemon. 
 * @param atk2 Ponteiro para função do ataque 2 do pokemon. 
 * @param atk3 Ponteiro para função do ataque 3 do pokemon. 
 * @return Retorna um pokemon genérico.
**/
//Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3);
Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo);

//! funcao para testes, excluir depois
void imprimePokemon(Pokemon *p);

/**
 * @brief Atualiza o campo "hpAtual" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param hpAtual Novo valor do campo p->hpAtual.
 * @return Pokemon com o campo "hpAtual" atualizado.
 **/
Pokemon* setHPAtual(Pokemon* p, float hpAtual);


/**
 * @brief Atualiza o campo "estado" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param estado Novo valor do campo p->estado.
 * @return Pokemon com o campo "estado" atualizado.
 **/
Pokemon* setEstado(Pokemon *p, int estado);

/**
 * @brief Captura o valor do campo "p->ataque" de um dado pokemon.
 * @param p Pokemon que terá seu valor de ataque capturado.
 * @return Valor de "p->ataque".
 **/
float getAtaque(Pokemon *p);

/**
 * @brief Captura o valor do campo "p->hpAtual" de um dado pokemon.
 * @param p Pokemon que terá seu valor de hpAtual capturado.
 * @return Valor de "p->hpAtual".
 **/
float getHPAtual(Pokemon* p);

/**
 * @brief Captura o valor do campo "p->defesa" de um dado pokemon.
 * @param p Pokemon que terá seu valor de defesa capturado.
 * @return Valor de "p->defesa".
 **/
float getDefesa(Pokemon *p);

/**
 * @brief Captura o valor do campo "p->tipo" de um dado pokemon.
 * @param p Pokemon que terá seu valor de tipo capturado.
 * @return Valor de "p->tipo".
 **/
int getTipo(Pokemon *p);

/**
 * @brief Libera um pokemon da memória.
 * @param p Pokemon que será liberado da memória.
 **/
void destroiPokemon(Pokemon *p);

float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo);


#endif