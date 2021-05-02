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
#include "jogador.h"

#define QTDPOKEMONS 6

typedef Pokemon* (*fptrInic) (); // Vetor de ponteiros de função com as funções de criação de pokemons.
//fptrInic inicPokemons['V' + 1];

//enum personagens{BLASTOISE = 0, CHARIZARD, MEW, PIKACHU, STEELIX, VENUSAUR};
#define BLASTOISE 0
#define CHARIZARD 1
#define MEW 2
#define PIKACHU 3
#define STEELIX 4
#define VENUSAUR 5

fptrInic inicPokemons[QTDPOKEMONS];

/**
 * @brief Inicializa o vetor de ponteiros de função para criação dos pokemons implementados.
 **/
void iniciaTabelaCriacaoPokemons();

/**
 * @brief Escolhe uma pokémon com base em sua "chave".
 * @param code Caractere inicial do pokemon a ser escolhido. Por exemplo, se code == 'P', será escolhido o Pikachu.
 * @return Pokemon do determinado code criado e inicializado.
 **/
Pokemon* escolhePokemon(int code);

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

/**
 * @brief Sorteia um pokemon dentre todos os disponíveis para o computador enfrentar o usuário numa batalha.
 * @return Pokemon sorteado.
 **/
Pokemon* sorteiaPokemon();

/**
 * @brief Sorteia um dos ataques de um determinado pokemon para o computador jogar contra o usuário.
 * @param p Pokemon que terá um de seus ataques sorteado.
 * @return Ponteiro da função do ataque que será sorteado.
 **/
fptrAtaque sorteiaAtaque(Pokemon *p);

/**
 * @brief Aplica o dano de QUEIMAR caso o pokemon esteja neste estado.
 * @param p Pokemon que sofrerá esse dano.
 * @return Pokemon com seu hpAtual atualizado.
 **/
Pokemon* sofreQueimar(Pokemon *p);

/**
 * @brief Controla os estados dos pokemons entre os ataques, bem como o tempo em que eles ficam em cada estado.
 * @param p Pokemon que terá seus estados e quantidade de turnos nesse estado atualizados.
 **/
void transicaoEntreTurnos(Pokemon *p);

/**
 * @brief Função que diz se o jogador pode ou não atacar, dependendo dos estados do pokemon atacante.
 * @param atacante Pokemon que fará ou não seu ataque.
 * @return 1, caso possa atacar e 0 caso contrário.
 **/
int podeJogar(Pokemon *atacante);

void jogadorAtaca(Pokemon* atacante, Pokemon* defensor, int escolheAtaque, Jogador* jogador);

int vaiCapturarPokemonOuNao(Pokemon *p);

#endif