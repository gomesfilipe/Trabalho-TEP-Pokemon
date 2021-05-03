#include "../../include/pokemons/steelix.h"

Pokemon* criaSteelix(){
    fptrAtaque atk1 = raboDeFerro;
    fptrAtaque atk2 = dormirSteelix;
    fptrAtaque atk3 = cavar;
    
    Pokemon *steelix = criaPokemon("Steelix", 280, 170, 400,  METAL, atk1, atk2, atk3, "Rabo de Ferro", "Dormir", "Cavar");
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

void dormirSteelix(Pokemon *steelix, Pokemon *defensor){
    steelix = setEstado(steelix, DORMIR, 1);
    steelix = setEstado(steelix, NORMAL, 0);
    steelix = setEstado(steelix, FULLHP, 1);
    steelix = setTurnosNumEstado(steelix, DORMIR, 2);
    steelix = setTurnosNumEstado(steelix, FULLHP, 2);
}

void cavar(Pokemon *steelix, Pokemon *defensor){ 
    int estado = getEstado(steelix, ESCONDER);
    if(estado == 1){
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
        steelix = setTurnosNumEstado(steelix, ESCONDER , 0);
    
    } else{
        steelix = setEstado(steelix, ESCONDER, 1);
        steelix = setTurnosNumEstado(steelix, ESCONDER , 1);
        steelix = setEstado(steelix, NORMAL, 0);
    }
}



