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