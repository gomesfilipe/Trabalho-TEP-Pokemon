#include "../../include/pokemons/blastoise.h"

Pokemon* criaBlastoise(){
    Pokemon *blastoise = criaPokemon("Blastoise", 280, 180, 200, AGUA);
    return blastoise;
}

void armaDeAgua(Pokemon *blastoise, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(blastoise);
    float D = getDefesa(defensor);
    float poder = 40;  
    float MT = 1.5;
    int tipoPokemonAtk = getTipo(blastoise);
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

void proteger(Pokemon *blastoise, Pokemon *defensor){
    blastoise = setEstado(blastoise, PROTEGIDO, 1); 
    blastoise = setEstado(blastoise, NORMAL, 0);
}

void bater(Pokemon *blastoise, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(blastoise);
    float D = getDefesa(defensor);
    float poder = 40;  
    float MT = 1;
    int tipoPokemonAtk = getTipo(blastoise);
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



