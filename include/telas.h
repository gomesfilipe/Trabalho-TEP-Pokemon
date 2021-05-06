#ifndef TELAS_H
#define TELAS_H

#include "pokemon.h"
#include "jogador.h"
#include "jogo.h"
#include "utils.h"
#include <unistd.h>

#define TAM 100
#define TIME 2

/**
 *@brief Função que realiza a batalha, chama o ataque do jogador e o ataque do computador. Caso o jogador vença a batalha,
 essa função é chamada novamente. Esse ciclo só encerra quando o último  pokemon do jogador está com 0 de HP e chamamos a função GAMEOVER.
 @param jogador É jogador que batalhará com o computador.
 @param listaPC Lista de pokemons do computador.
 @param f Ponteiro que apontará para o arquivo de log de batalhas.
**/

void batalha(Jogador* jogador, Lista *listaPC, FILE *f);

/**
 * 
 **/
void melhoresPontuacoes(); //! DOCUMENTAR


/**
 * 
 **/
void sair(); //! DOCUMENTAR

/**
 * @brief É função que é chamada quando o usúario digita 1 no menuInicial. Essa função trata dos aspectos de quando um usúario quer jogar,
 * como ler o nome do jogador, os pokemons que ele quer adicionar em sua lista, etc.
**/
void jogar();

/**
 * @brief Controla o menu inicial do programa, direcionando o usuário para o início de uma partida, ver a classificação ou encerrar o programa.
 * Essa função faz tratamento de entradas inválidas do usuário.
 **/
void menuInicial();

/**
 * @brief Limpa o terminal. Essa função servirá para deixar os menus do programa mais amigáveis.
 **/
void limpaTela();

/**
 * @brief Imprime os motivos de um pokemon não poder efetuar um ataque, seja devido a estar paralisado, dormindo ou escondido.
 * @param pokemon Pokemon que terá seus motivos impressos.
 * @param defensor Pokemon que defenderá no ataque cavar do steelix. Foi necessário colocar essa parametro para fazer o controle correto
 * de quando steelix não pode jogar, mas mesmo assim aplica o dano do seu ataque cavar.
 **/
void imprimeEstadoQuandoNaoPodeJogar(Pokemon *pokemon, Pokemon *defensor);

/**
 * @brief Imprime o menu de ataque, mostrando ao usuário o HP dos pokemons e suas opções de movimentos para jogar.
 * @param jogador Jogador da partida.
 * @param pokemonDoPc Pokemon do computador.
 **/
void imprimeMenuAtaque(Jogador *jogador, Pokemon* pokemonDoPC);

/**
 * @brief Imprime o ataque que o pokemon do jogador fez. Em seguida, imprime os HPs dos pokemons que estão batalhando.
 * @param pokemonJogador Pokemon do jogador.
 * @param pokemonDoPC Pokemon do computador.
 * @param numAtk Número do ataque do pokemon em seu vetor de ponteiros de funções de ataque.
 *@param f Ponteiro que aponta para o arquivo de log de batalhas.
 **/
void imprimeAtaqueJogador(Pokemon *pokemonJogador, Pokemon *pokemonDoPC, int numAtk,  FILE *f);

/**
 * @brief Imprime os HPS dos pokemons que estão batalhando.
 * @param pokemonJogador Pokemon do jogador que terá HP impresso na tela.
 * @param pokemonDoPC Pokemon do computador que terá HP impresso na tela.
 *@param f Ponteiro que aponta para o arquivo de log de batalhas.
 **/
void imprimeHPs(Pokemon *pokemonJogador, Pokemon *pokemonDoPC,  FILE *f);

/**
 *@brief Imprime o nome de um ataque que o metronomo sorteou.
 *@return Retorna o numero de qual ataque o metronomo sorteou. 
**/
int ImprimeAtaqueMetronomo();

/**
*@brief Imprime os estados(paralizado, dormindo e/ou queimando) de um pokemon no log de batalhas.
*@param p Pokemon que terá seus estados imprimessos.
*@param f Ponteiro que aponta para o arquivo de log de batalhas.
**/
void imprimeEstadosLog(Pokemon *p, FILE *f);

#endif
