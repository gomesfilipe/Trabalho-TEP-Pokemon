#include "../include/jogo.h"

void iniciaTabelaCriacaoPokemons(){
    inicPokemons['B' - 'B'] = criaBlastoise;
    inicPokemons['C' - 'B'] = criaCharizard;
    inicPokemons['M' - 'B'] = criaMew;
    inicPokemons['P' - 'B'] = criaPikachu;
    inicPokemons['S' - 'B'] = criaSteelix;
    inicPokemons['V' - 'B'] = criaVenusaur;
}

Pokemon* escolhePokemon(char code){
    fptrInic pokemonEscolhido = inicPokemons[code - 'B'];
    return pokemonEscolhido();
}

void inicializaMatrizRelacaoTipos(float m[QTDTIPOS][QTDTIPOS]){
    m[ELETRICO][ELETRICO] = 0.5; 
    m[ELETRICO][FOGO]     = 1.0; 
    m[ELETRICO][AGUA]     = 2.0; 
    m[ELETRICO][PLANTA]   = 0.5; 
    m[ELETRICO][METAL]    = 1.0; 
    m[ELETRICO][PSIQUICO] = 1.0;
    
    m[FOGO][ELETRICO]  = 1.0; 
    m[FOGO][FOGO]      = 0.5; 
    m[FOGO][AGUA]      = 0.5; 
    m[FOGO][PLANTA]    = 2.0; 
    m[FOGO][METAL]     = 2.0; 
    m[FOGO][PSIQUICO]  = 1.0;
    
    m[AGUA][ELETRICO]  = 1.0; 
    m[AGUA][FOGO]      = 2.0; 
    m[AGUA][AGUA]      = 0.5; 
    m[AGUA][PLANTA]    = 0.5; 
    m[AGUA][METAL]     = 1.0; 
    m[AGUA][PSIQUICO]  = 1.0;
    
    m[PLANTA][ELETRICO] = 1.0; 
    m[PLANTA][FOGO]     = 0.5; 
    m[PLANTA][AGUA]     = 2.0; 
    m[PLANTA][PLANTA]   = 0.5 ; 
    m[PLANTA][METAL]    = 0.5; 
    m[PLANTA][PSIQUICO] = 1.0;
    
    m[METAL][ELETRICO] = 0.5; 
    m[METAL][FOGO]     = 0.5; 
    m[METAL][AGUA]     = 0.5; 
    m[METAL][PLANTA]   = 1.0; 
    m[METAL][METAL]    = 0.5; 
    m[METAL][PSIQUICO] = 1.0;
    
    m[PSIQUICO][ELETRICO] = 1.0; 
    m[PSIQUICO][FOGO]     = 1.0; 
    m[PSIQUICO][AGUA]     = 1.0; 
    m[PSIQUICO][PLANTA]   = 1.0; 
    m[PSIQUICO][METAL]    = 0.5; 
    m[PSIQUICO][PSIQUICO] = 0.5;
}

float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo){
    int modificador = critico * MT * relacaoTipo;
    return ((14.0 * poder * A / D) / 50.0 + 2.0) * modificador;
}

