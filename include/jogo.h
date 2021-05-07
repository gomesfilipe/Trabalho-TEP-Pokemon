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
#include "telas.h"

#define QTDPOKEMONS 6

enum possibilidadesAoAtacar{ATKNORMAL = 0, ATKMORREU, ATKMATOU, ATKMATOUMORREU, CAPTUROU, NAOCAPTUROU, FUGIU, NAOFUGIU, GAMEOVER};

// #define ATKNORMAL 0
// #define ATKMORREU 1
// #define ATKMATOU 2
// #define ATKMATOUMORREU 3
// #define CAPTUROU 4
// #define NAOCAPTUROU 5
// #define FUGIU 6
// #define NAOFUGIU 7

typedef Pokemon* (*fptrInic) (); // Vetor de ponteiros de função com as funções de criação de pokemons.
//fptrInic inicPokemons['V' + 1];

//enum personagens{BLASTOISE = 0, CHARIZARD, MEW, PIKACHU, STEELIX, VENUSAUR};
#define BLASTOISE 0
#define CHARIZARD 1
#define VENUSAUR 2
#define PIKACHU 3
#define STEELIX 4
#define MEW 5

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
 * Também colocamos aqui parte da impressao do ataque do computador pois não havia como capturar a referencia do numero aleatório
 * que era necessário para imprimir o ataque do computador, pois essa função já retorna um ponteiro de função.
 * @param p Pokemon que terá um de seus ataques sorteado.
 * @param f Ponteiro que aponta para arquivo.
 * @return Ponteiro da função do ataque que será sorteado.
 **/
fptrAtaque sorteiaAtaque(Pokemon *p,  FILE* f);

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

/**
 *@brief  Calcula a probabilidade de capturar um pokemon.
 *@param p Pokemon que pode ser capturado ou não.
 *@return Retorna 1 se for possível capturar o pokemon e retorna 0 se não for possível.
**/
int vaiCapturarPokemonOuNao(Pokemon *p);

/**
 * @brief Calcula a probabiblidade de um pokemon fugir.
 * @return Retorna 1 caso o pokemon consiga fugir e 0 caso não conseguir fugir.
**/
 int fogeOuNao();

/**
 * @brief Efetua o ataque do jogador. Caso algum dos pokemons morra nesse ataque, a função faz os devidos tratamentos,
 * como retirar o pokemon da lista do jogador caso ele morra, controlar a quantidade de pokemons e de pokebolas do jogador, etc.
 * @param defensor Pokemon que sofrerá o ataque. Nessa função, é o pokemon do computador.
 * @param escolheAtaque Número da opção que o usuário irá escolher para seu ataque (1,2,3,4 ou 5).
 * @param jogador Jogador que irá comandar seu pokemon para atacar.
  *@param f Ponteiro para arquivo.
 * @return Um número inteiro entre 0 e 8 que indica o que aconteceu após o ataque, como por exemplo se capturou um pokemon, se matou
 * o pokemon inimigo, se seu pokemon morreu ou fugiu, etc. 
 **/
int jogadorAtaca(Pokemon* defensor, int escolheAtaque, Jogador* jogador, FILE *f);

/**
 * @brief Efetua o ataque do computador. Caso algum dos pokemons morra nesse ataque, a função faz os devidos tratamentos,
 * como retirar o pokemon da lista do jogador caso ele morra, controlar a quantidade de pokemons do jogador, etc.
 * @param atacante É o pokemon do computador que no momento está atacando.
 * @param jogador É o usuário que está possui o primeiro pokemon de sua lista sendo atacado.
 * @param f Ponteiro que aponta para arquivo.
 * @return Um número inteiro entre 0 e 8 que indica o que aconteceu após o ataque, se a partida acabou, se matou o pokemon inimigo, etc.
**/
int computadorAtaca(Pokemon *atacante, Jogador *jogador,  FILE* f);

/**
 * @brief Decreta o final de uma partida. Essa função libera da memória a lista de pokemons do computador, o arquivo do log de batalhas
 * e direciona para o menu principal do jogo.
 * @param listaPC É a lista de pokemons do computador que será liberada da memória.
 * @param f Ponteiro para o arquivo que será liberado da memória.
 * @param listaComJogadores Ponteiro para uma lista de jogadores.
 * @param placar Ponteiro para o arquivo de placar dos jogadores.
 * @param fileNameLog String que recebe o caminho para o arquivo de log de batalhas.
 **/
void gameOver(Lista* listaPC, FILE *f, listaJog *listaComJogadores, FILE *placar, char* fileNameLog);

/**
 * @brief Cria a lista de pokemons que possui todos que foram implementados. Essa função servirá de auxílio
 * no momento que o usuário estiver escolhendo seus pokemons antes de iniciar uma partida.
 * @return Lista de pokemons com todos os pokemons existentes no jogo.
 **/
Lista* criaListaPokemonsTela();

/**
 *@brief Captura o nome de um jogador.
 *@param jogador É o jogador que terá seu nome capturado.
 @return Ponteiro que aponta para a primeira posição da string do nome do jogador.
**/
char* getNomeJogador(Jogador* jogador);


#endif
