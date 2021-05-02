#include "../../include/pokemons/venusaur.h"



void poDeSono(Pokemon *venusaur, Pokemon *defensor){
    int turnosDormindo = rand() % 3;
    defensor = setEstado(defensor, DORMIR, 1);
    defensor = setEstado(defensor, NORMAL, 0);
    defensor = setTurnosNumEstado(defensor, DORMIR, turnosDormindo + 1);
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
    
    float hpAtualAtacante = getHPAtual(venusaur);
    novoHP = hpAtualAtacante - dano / 3.0;
    venusaur = setHPAtual(venusaur, novoHP);
}

Pokemon* criaVenusaur(){
    fptrAtaque atk1 = poDeSono;
    fptrAtaque atk2 = bombaDeSemente;
    fptrAtaque atk3 = doisGumes;
    
    Pokemon *venusaur = criaPokemon("Venusaur", 300, 160, 160,  PLANTA, atk1, atk2, atk3);
    return venusaur;
}
