#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

#define QTDPOKEBOLASINICIAIS 3
#define QTDPOKEMONSINICIAIS 3

typedef struct jogador Jogador;

typedef struct celulajogador celulaJogador;

typedef struct listaJogadores listaJog;

/**
 * @brief Cria um jogador
 * @param nome É o nome do jogador.
 * @param pokemons É a lista de pokemons de um jogador.
 * @return Retorna o jogador que foi criado.
**/
Jogador* criaJogador(char *nome, Lista *pokemons);

/**
 * @brief Libera um tipo Jogador da memória.
 * @param jogador Jogador que será desalocado da memória.
 **/
void destroiJogador(Jogador* jogador);

void imprimeJogador(Jogador *jogador); //! excluir depois, funcao apenas para ajudar a testar e debugar

/**
 * @brief Nessa função o jogador tenta capturar uma pokebola. A tentativa possui uma chance C/12 de ser efetiva.
 * @param jogador É o jogador que tentará capturar uma pokebola.
 * @param C É o número de batalhas vencidas desde a útima pokebola.
 * @return  É o jogador que talvez terá uma pokebola a mais.
**/
Jogador* capturaPokebola(Jogador* jogador, int C);

/**
 * @brief Captura a quantidade de pokebolas de um jogador.
 * @param jogador Jogador que terá o campo "qtdPokebolas" capturado.
 * @return Quantidade de pokebolas que o jogador possui.
 **/
int getQtdPokebolas(Jogador* jogador);

/**
 * @brief Captura a quantidade de pokemons de um jogador.
 * @param jogador Jogador que terá o campo "qtdPokemons" capturado.
 * @return Quantidade de pokemons que o jogador possui.
 **/
int getQtdPokemons(Jogador* jogador);

/**
 * @brief Captura a quantidade de vitórias de um jogador.
 * @param jogador Jogador que terá o campo "qtdVitorias" capturado.
 * @return Quantidade de vitórias que o jogador possui.
 **/
int getQtdVitorias(Jogador* jogador);

/**
 * @brief Seta uma quantidade de pokemons no campo "jogador->qtdPokemons".
 * @param jogador Jogador que terá seu campo "jogador->qtdPokemons" atualizado.
 * @param qtdPokemons Valor que será setado no campo "jogador->qtdPokemons".
 * @return Jogador com sua quantidade de pokemons atualizada.
 **/
Jogador* setQtdPokemons(Jogador* jogador , int qtdPokemons);

/**
 * @brief Captura o ponteiro para a lista de pokemons de um jogador.
 * @param jogador Jogador que terá sua lista de pokemons capturada.
 * @return Ponteiro para a lista de pokemons do jogador.
 **/
Lista* getListaPokemons(Jogador* jogador);

/**
 * @brief Seta uma quantidade de pokemons no campo "jogador->qtdVitorias".
 * @param jogador Jogador que terá seu campo "jogador->qtdVitorias" atualizado.
 * @param qtdVitorias Valor que será setado no campo "jogador->qtdVitorias".
 * @return Jogador com sua quantidade de vitórias atualizada.
 **/
Jogador* setQtdVitorias(Jogador* jogador , int qtdVitorias);

/**
 * @brief Atualiza a lista de pokemons de um jogador.
 * @param jogador Jogador que terá sua lista de pokemons atualizada.
 * @param listaPokemons Ponteiro para a lista de pokemons do jogador.
 * @return Jogador com sua lista de pokemons atualizada.
**/
Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons);

/**
 * @brief Retira o pokemon que morreu da lista de pokemons do jogador.
 * @param jogador Jogador que terá seu pokemon retirado da lista.
 * @return Jogador com sua lista de pokemons atualizada.
 **/
Jogador* morrePokemon(Jogador* jogador);

/**
 * @brief Adiciona um pokemon capturado na lista de pokemons do jogador.
 * @param jogador Jogador que terá o pokemon adicionado a sua lista.
 * @param p Pokemon capturado.
 * @return Jogador com sua lista de pokemons atualizada.
 **/
Jogador* capturaPokemon(Jogador* jogador, Pokemon *p);

/**
 * @brief Captura o primeiro pokemon da lista de pokemons de um jogador.
 * @param jogador É o jogador que possui a lista da qual capturaremos o primeiro pokemon.
 * @return Retorna o primeiro pokemon da lista de um jogador.
**/
Pokemon* getPrimeiroPokemonDoJogador(Jogador *jogador);


/**
 * @brief Coloca uma determinada quantidade de pokebolas no campo qtdPokebolas de um jogador.
 * @param qtdPokebolas É o valor que será colocado no campo qdtPokebolas de um jogador.
 * @param jogador É o jogador que terá sua quantidade de pokebolasatualizada.
 * @return Retorna o jogador que teve sua quantidade de pokebolas atualizada.
**/
Jogador* setQtdPokebolas(Jogador* jogador , int qtdPokebolas);

/**
 * @brief Verifica se uma lista de jogadores é vazia.
 * @param lista Lista de jogadores.
 * @return 1 caso a lista seja varia e 0, caso contrário.
 **/
int listaVazia(listaJog *lista);

/**
 * @brief Adiciona um jogador no final de uma lista encadeada de jogadores.
 * @param lista Ponteiro para a lista de jogadores.
 * @param jogador Jogador que será inserido no final da lista.
 * @return Ponteito para início da lista de jogadores atualizada.
 **/
listaJog* adicionaJogadorNaLista(listaJog* lista,  Jogador* jogador);

/**
 * @brief Libera da memória uma lista de jogadores.
 * @param inicio Ponteiro que faz referência ao início da lista de jogadores.
 **/
void destroiListaJogadores(listaJog *lista);

/**
 * @brief Inicializa uma lista encadeada de jogadores.
 * @return Lista de jogadores inicializada.
 **/
listaJog* criaListaJogadores();

/**
 * @brief Captura a quantidade de elementos que uma lista de jogadores possui.
 * @param inicio Ponteiro que faz referência ao início da lista de jogadores.
 * @return Tamanho da lista de jogadores.
 **/
int getTamanhoListaJogadores(listaJog *lista);

/**
 * @brief Ordena uma lista de jogadores em ordem decrescente de vitórias.
 * @param lista Ponteiro que faz referência a lista de jogadores.
 **/
void ordenaListaJogadores(listaJog *lista);

/**
 * @brief Imprime uma lista de jogadores num arquivo, mostrando na o nome de cada um e sua quantidade de vitórias.
 * @param lista Ponteiro que faz referência ao início da lista de jogadores.
 * @param f Ponteiro para arquivo cuja lista será impressa. Caso seja necessário imprimí-la no terminal, basta considerar f == stdout. 
 **/
void imprimeListaJogadores(listaJog *lista, FILE *f);

/**
* @brief  Imprime uma lista de jogadores, mostrando na tela o nome de cada um e sua quantidade de vitórias.
* @param lista Ponteiro que faz referência ao início da lista de jogadores.
**/
void imprimeListaJogadoresTerminal( listaJog *lista);

/**
*@brief Ordena uma lista de jogadores alfaticamente
*@param lista É a lista que será ordenada.
**/
void OrdenaListaJogadoresNome(listaJog *lista);

#endif
