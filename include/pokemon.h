#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDTIPOS 6
#define QTDESTADOS 7
#define QTDATAQUESPOKEMON 3

// Convencionando tipos de pokemons.
enum tipos {ELETRICO = 0, FOGO, AGUA, PLANTA, METAL, PSIQUICO};

// Convencionando possíveis estados do pokemon durante uma batalha.
enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO, ESCONDER, FULLHP};

typedef struct pokemon Pokemon;

typedef struct listaPokemon Lista;

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
 * @param nomeAtk1 Nome do primeiro ataque do pokemon.
 * @param nomeAtk2 Nome do segundo ataque do pomemon.
 * @param nomeAtk3 Nome do terceiro ataque do pokemon.
 * @return Retorna um pokemon genérico.
**/
Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3, char *nomeAtk1, char *nomeAtk2, char *nomeAtk3);

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
 * @brief Atualiza o campo "turnosNumEstado" na posição "posVetor" de um dado pokemon.
 * @param p Pokemon que terá o campo atualizado.
 * @param turnosNumEstado Novo valor do campo "p->turnosNumEstado[posVetor]".
 * @return Pokemon com o campo "p->turnosNumEstado[posVetor]" atualizado.
 **/
Pokemon* setTurnosNumEstado(Pokemon *p, int posVetor, int turnosNumEstado);

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
 * @brief Captura o valor do campo "p->hpMax" de um dado pokemon.
 * @param p Pokemon que terá seu valor de hpMax capturado.
 * @return Valor de "p->hpMax".
 **/
float getHPMaximo(Pokemon* p);

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
 * @brief Captura o valor de uma posição do vetor de estados de um pokemon.
 * @param p Pokemon que terá um dos seus valores de estado capturado.
 * @param posVetor Posicao do vetor que terá seu valor capturado.
 * @return Valor de "p->estado".
 **/
int getEstado(Pokemon *p, int posVetor);

/**
 * @brief Captura o valor de uma posição do vetor de "turnos num estado" de um pokemon.
 * @param p Pokemon que terá um dos seus valores de "turnos num estado" capturado.
 * @param posVetor Posicao do vetor que terá seu valor capturado.
 * @return Valor de "p->turnosNumEstado[posVetor]".
 **/
int getTurnosNumEstado(Pokemon *p, int posVetor);

/**
 * @brief Captura o ponteiro da função de ataque de um pokemon na posição posVetor.
 * @param p Pokemon que terá o ponteiro de ataque capturado.
 * @param posVetor Posição do vetor de ataques que terá o ataque capturado.
 * @return Ponteiro de ataque da respectiva função de ataque.
 **/
fptrAtaque getAtaquePokemon(Pokemon* p, int posVetor);

/**
 * @brief Libera um pokemon da memória.
 * @param p Pokemon que será liberado da memória.
 **/
void destroiPokemon(Pokemon *p);

/**
 * @brief Calcula o dano de um determinado ataque com base em diversos fatores.
 * @param A Ataque base do pokemon atacante.
 * @param D Defesa base do pokemon defensor.
 * @param poder Poder do ataque do pokemon atacante.
 * @param critico Valor que indica se o dano será dobrado ou não.
 * @param MT Valor que fortalece o ataque do pokemon atacante caso ele seja do mesmo tipo que o pokemon.
 * @param relacaoTipo Valor que indica a força de um pokemon sobre o outro com base em seus tipos.
 * @return Dano causado pelo ataque.
 **/
float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo);

/**
 * @brief Inicializa uma lista encadeada de pokemons com 1 elemento.
 * @param pokemon Conteudo da primeira celula.
 * @return Lista de pokemons inicializada.
 **/
Lista* criaLista(Pokemon *pokemon);

/**
 * @brief Adiciona um pokemon no final de uma lista encadeada de pokemons.
 * @param inicio Ponteiro para o primeiro elemento da lista.
 * @param pokemon Pokemon que será inserido no final da lista.
 * @return Ponteito para início da lista de pokemons atualizada.
 **/
Lista* adicicionaFinalLista(Lista *inicio, Pokemon* pokemon);

/**
 * @brief Remove um pokemon da primeira posição de uma lista encadeada de pokemons.
 * @param inicio Ponteiro para o primeiro elemento da lista.
 * @return Ponteiro para início da lista de pokemons atualizada.
 **/
Lista* removePrimeiroLista(Lista *inicio);

/**
 * @brief Imprime uma lista de pokemons.
 * @param inicio É a primeira célula da lista.
 **/
void imprimeLista(Lista* inicio); //! talvez nao use

/**
 * @brief Libera da memória uma lista encadeada de pokemons.
 * @param inicio Ponteiro para o início da lista de pokemons.
 **/
void destroiLista(Lista *inicio);


/**
 * @brief Restaura 10 pontos de HP após uma batalha vencida. Caso essa quantia ultrapasse o HP máximo de um pokemon, o pokemon fica com HP máximo.
 * @param p Pokemon que terá seu HP restaurado parcialmente.
 * @return Pokemon com seu HP atual atualizado.
 **/
Pokemon* recuperaHPEntreBatalhas(Pokemon *p);

/**
 * @brief Calcula a porcentagem de vida de um pokemon.
 * @param p Pokemon que terá seu percentual de vida calculado.
 * @return Porcentagem do hpAtual em relação ao hpMax.
 **/
float porcentagemDeVida(Pokemon *p);

/**
 * @brief Restaura o campo HP de um pokemon após o mesmo ter dormido.
 * @param p Pokemon que terá seu HP restaurado.
 * @return Pokemon que teve seu HP restaurado.
 **/
Pokemon* restauraHPAposDormir(Pokemon* p);

/**
 * @brief Função genérica que efetua o ataque de um pokemon atacante sobre um pokemon defensor.
 * @param code Numero do ataque do pokemon. Por exemplo, o choque do trovão do pikachu seria 1, e assim por diante.
 * @param atacante Pokemon que aplica o ataque.
 * @param defensor Pokemon que sofre o ataque.
 **/
void ataque(int code, Pokemon *atacante, Pokemon *defensor);

/**
 * @brief Pega o primeiro pokemon de uma lista de pokemons.
 * @param lista Ponteiro para o primeiro elemento de uma lista de pokemons.
 * @return Primeiro pokemon dessa lista de pokemons.
 **/
Pokemon* getPrimeiroPokemon(Lista* lista);

#endif