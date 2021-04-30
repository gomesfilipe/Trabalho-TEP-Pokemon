#include "../../include/pokemons/steelix.h"

Pokemon* criaSteelix(){
    Pokemon *steelix = criaPokemon("Steelix", 280, 170, 400,  METAL);
    return steelix;
}

void raboDeFerro(Pokemon *steelix, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    
    float A = getAtaque(steelix);
    float D = getDefesa(defensor);
    float poder = 100;  
    float MT = 1.5;
    int tipoPokemonAtk = getTipo(steelix);
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

void dormir(Pokemon *steelix, Pokemon *defensor){
    steelix = setEstado(steelix, DORMIR, 1);
    steelix = setEstado(steelix, NORMAL, 0);
    steelix = setEstado(steelix, FULLHP, 1);
    steelix = setTurnosSemJogar(steelix, 2);
}

void cavar(Pokemon *steelix, Pokemon *defensor){ 
    int estado = getEstado(steelix);
    if(estado == ESCONDER){
        float matriz[QTDTIPOS][QTDTIPOS];
        inicializaMatrizRelacaoTipos(matriz);
        
        float A = getAtaque(steelix);
        float D = getDefesa(defensor);
        float poder = 80;  
        float MT = 1;
        int tipoPokemonAtk = getTipo(steelix);
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
        steelix = setEstado(steelix, NORMAL, 1);
        steelix = setEstado(steelix, ESCONDER, 0);
    
    } else{
        steelix = setEstado(steelix, ESCONDER, 1);
        steelix = setEstado(steelix, NORMAL, 0);
    }
}



