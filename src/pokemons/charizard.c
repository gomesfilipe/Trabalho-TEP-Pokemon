#include "../../include/pokemons/charizard.h"

Pokemon* criaCharizard(){
    Pokemon *charizard = criaPokemon("Charizard", 260, 160, 150, NORMAL, FOGO);
    return charizard;
}

void lancaChamas(Pokemon *charizard, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    
    float A = getAtaque(charizard);
    float D = getDefesa(defensor);
    float poder = 90;  
    float MT = 1.5;
    int tipoPokemonAtk = getTipo(charizard);
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

    aleatorio = rand() % 10;
    if(aleatorio == 0 && tipoPokemonDef != FOGO){
     //   defensor = setEstado(defensor, QUEIMAR); //o estado de queimar n serve mais pra nada
        defensor = setQueimando(defensor, 1);
    }
}
//Full HP é um estado parecido com o de paralizar, mas a diferença é que ao final recupera todo o HP.
void dormir(Pokemon *charizard, Pokemon *defensor){
    defensor = setEstado(defensor, FULLHP); 
    defensor = setTurnosSemJogar(defensor, 2);
}

void bater(Pokemon *charizard, Pokemon *defensor){
    float matriz[QTDTIPOS][QTDTIPOS];
    inicializaMatrizRelacaoTipos(matriz);
    float A = getAtaque(charizard);
    float D = getDefesa(defensor);
    float poder = 40;  
    float MT = 1;
    int tipoPokemonAtk = getTipo(charizard);
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





