#include "../../include/pokemons/mew.h"

Pokemon* criaMew(){
    Pokemon *mew = criaPokemon("Mew", 320, 200, 200, NORMAL, PSIQUICO);
    return mew;
}

void metronomo(Pokemon *mew, Pokemon *defensor){

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
    float MT = 1.5;
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