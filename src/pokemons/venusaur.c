#include "../../include/pokemons/venusaur.h"

Pokemon* criaVenusaur(){
    Pokemon *venusaur = criaPokemon("Venusaur", 300, 160, 160, NORMAL, PLANTA);
    return venusaur;
}

void poDeSono(Pokemon *venusaur, Pokemon *defensor){
    defensor = setEstado(defensor, DORMIR);
}

void bombaDeSemente(Pokemon *venusaur, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(venusaur);
    float D = getDefesa(defensor);
    float poder = 80;  
    float MT = 1.5;
    int tipoPokemonAtk = getTipo(venusaur);
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

void doisGumes(Pokemon *venusaur, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(venusaur);
    float D = getDefesa(defensor);
    float poder = 120;  
    float MT = 1.5;
    int tipoPokemonAtk = getTipo(venusaur);
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
    venusaur = setHPAtual(venusaur, novoHP / 3.0);
}
