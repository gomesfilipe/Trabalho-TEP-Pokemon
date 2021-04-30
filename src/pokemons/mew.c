#include "../../include/pokemons/mew.h"

Pokemon* criaMew(){
    Pokemon *mew = criaPokemon("Mew", 320, 200, 200, NORMAL, PSIQUICO);
    return mew;
}

void metronomo(Pokemon *mew, Pokemon *defensor){
    int aleatorio = rand() % 13;
    fptrAtaque ataqueMew = todosAtaques[aleatorio];
    ataqueMew(mew, defensor);   
}

void bater(Pokemon *mew, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(mew);
    float D = getDefesa(defensor);
    float poder = 40;  
    float MT = 1;
    int tipoPokemonAtk = getTipo(mew);
    int tipoPokemonDef = getTipo(defensor);
    float relacaoTipo = matriz[tipoPokemonAtk][tipoPokemonDef];

    float critico;
    int aleatorio = rand() % 24;
    if(aleatorio == 2){
        critico = 2;
    } else{
        critico = 1;
    }

    float dano = calculaDano(A, D, poder, critico, MT, relacaoTipo);
    float hpAtualDefensor = getHPAtual(defensor);
    float novoHP = hpAtualDefensor - dano;
    
    defensor = setHPAtual(defensor, novoHP);
}

void autoDestruir(Pokemon *mew, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(mew);
    float D = getDefesa(defensor);
    float poder = 200;  
    float MT = 1;
    int tipoPokemonAtk = getTipo(mew);
    int tipoPokemonDef = getTipo(defensor);
    float relacaoTipo = matriz[tipoPokemonAtk][tipoPokemonDef];

    float critico;
    int aleatorio = rand() % 24;
    if(aleatorio == 2){
        critico = 2;
    } else{
        critico = 1;
    }

    float dano = calculaDano(A, D, poder, critico, MT, relacaoTipo);
    float hpAtualDefensor = getHPAtual(defensor);
    float novoHP = hpAtualDefensor - dano;
    
    defensor = setHPAtual(defensor, novoHP);
    mew = setHPAtual(mew, 0);
}

void inicializaVetorComTodosAtaques(){
    todosAtaques[0]  = choqueDoTrovao;
    todosAtaques[1]  = ondaDeChoque;
    todosAtaques[2]  = bater;
    todosAtaques[3]  = lancaChamas;
    todosAtaques[4]  = dormir;
    todosAtaques[5]  = armaDeAgua;
    todosAtaques[6]  = proteger;
    todosAtaques[7]  = poDeSono;
    todosAtaques[8]  = bombaDeSemente;
    todosAtaques[9]  = doisGumes;
    todosAtaques[10] = raboDeFerro;
    todosAtaques[11] = cavar;
    todosAtaques[12] = autoDestruir;
}

