#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDTIPOS 6
#define QTDESTADOS 7

// int normal;
// int paralisado;
// int dormindo;
// int queimando;
// int protegido;
// int escondido;
// int restauraHP;

// Convencionando tipos de pokemons.
enum tipos {ELETRICO = 0, FOGO, AGUA, PLANTA, METAL, PSIQUICO};

// Convencionando possíveis estados do pokemon durante uma batalha.
enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO, ESCONDER, FULLHP};

typedef struct pokemon Pokemon;

typedef void (*fptrAtaque) (Pokemon*, Pokemon*);

/**
 * @brief Aloca memória para um pokemon e inicializa um pokemon genérico.
 * @param nome Nome do pokemon.
 * @param hpMax Máximo de HP do pokemon.
 * @param ataque Força de ataque do pokemon.
 * @param defesa Resistência de defesa do pokémon.
 * @param tipo Tipo do pokemon.
 * @param atk1 Ponteiro para função do ataque 1 do pokemon. 
 * @param atk2 Ponteiro para função do ataque 2 do pokemon. 
 * @param atk3 Ponteiro para função do ataque 3 do pokemon. 
 * @return Retorna um pokemon genérico.
**/
//Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3);
Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int tipo);

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
 * @brief Atualiza uma das posições do vetor "estado" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param posVetor Posição do vetor de estados que será atualizado.
 * @param valor Valor que será inserido (pode ser 0 ou 1). 
 * @return Pokemon com o campo "p->estados[posVetor]" atualizado.
 **/
Pokemon* setEstado(Pokemon *p, int posVetor, int valor);

/**
 * @brief Atualiza o campo "turnosSemJogar" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param turnosSemJogar Novo valor do campo p->turnosSemJogar.
 * @return Pokemon com o campo "turnosSemJogar" atualizado.
 **/
Pokemon* setTurnosSemJogar(Pokemon *p, int turnosSemJogar);

/**
 * @brief Atualiza o campo "queimando" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param queimando Novo valor do campo p->queimando.
 * @return Pokemon com o campo "queimando" atualizado.
 **/
Pokemon* setQueimando(Pokemon *p, int queimando);

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
 * @brief Captura o valor do campo "p->estado" de um dado pokemon.
 * @param p Pokemon que terá seu valor de estado capturado.
 * @return Valor de "p->estado".
 **/
int getEstado(Pokemon *p);

/**
 * @brief Libera um pokemon da memória.
 * @param p Pokemon que será liberado da memória.
 **/
void destroiPokemon(Pokemon *p);

float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo);


#endif