#include "../../include/pokemons/charizard.h"

Pokemon* criaCharizard(){
    fptrAtaque atk1 = lancaChamas;
    fptrAtaque atk2 = dormirCharizard;
    fptrAtaque atk3 = baterCharizard;
    
    Pokemon *charizard = criaPokemon("Charizard", 260, 160, 150, FOGO, atk1, atk2, atk3, "Lanca Chamas", "Dormir", "Bater");
    return charizard;
}

void lancaChamas(Pokemon *charizard, Pokemon *defensor){
    if(estaImune(defensor) == 0){
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
            defensor = setEstado(defensor, NORMAL, 0);
            defensor = setEstado(defensor, QUEIMAR, 1);
        }
    }    
}

//Full HP é um estado parecido com o de paralizar, mas a diferença é que ao final recupera todo o HP.
void dormirCharizard(Pokemon *charizard, Pokemon *defensor){
    charizard = setEstado(charizard, NORMAL, 0); 
    charizard = setEstado(charizard, FULLHP, 1); 
    charizard = setEstado(charizard, DORMIR, 1);
    charizard = setTurnosNumEstado(charizard, DORMIR, 3);
    charizard = setTurnosNumEstado(charizard, FULLHP, 3);
}

void baterCharizard(Pokemon *charizard, Pokemon *defensor){
    if(estaImune(defensor) == 0){
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
}





