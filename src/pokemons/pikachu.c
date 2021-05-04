#include "../../include/pokemons/pikachu.h"

Pokemon* criaPikachu(){
    fptrAtaque atk1 = choqueDoTrovao;
    fptrAtaque atk2 = ondaDeChoque;
    fptrAtaque atk3 = baterPikachu;
    Pokemon *pikachu = criaPokemon("Pikachu", 200, 110, 100,  ELETRICO, atk1, atk2, atk3, "Choque do Trovao", "Onda de Choque", "Bater");
    return pikachu;
}

void choqueDoTrovao(Pokemon *pikachu, Pokemon *defensor){
    if(estaImune(defensor) == 0 ){
        float matriz[QTDTIPOS][QTDTIPOS];
        inicializaMatrizRelacaoTipos(matriz);
        
        float A = getAtaque(pikachu);
        float D = getDefesa(defensor);
        float poder = 40;  
        float MT = 1.5;
        int tipoPokemonAtk = getTipo(pikachu);
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
        if(aleatorio == 0){
            defensor = setEstado(defensor, PARALISAR, 1);
            defensor = setEstado(defensor, NORMAL, 0);
            defensor = setTurnosNumEstado(defensor, PARALISAR , 1);
        }
    }    
}

void ondaDeChoque(Pokemon *pikachu, Pokemon *defensor){
    if(estaImune(defensor) == 0){
        defensor = setEstado(defensor, PARALISAR, 1);
        defensor = setEstado(defensor, NORMAL, 0);
        defensor = setTurnosNumEstado(defensor, PARALISAR , 1);
    }
}

void baterPikachu(Pokemon *pikachu, Pokemon *defensor){
    if(estaImune(defensor == 0)){
        float matriz[QTDTIPOS][QTDTIPOS];
        inicializaMatrizRelacaoTipos(matriz);
        
        float A = getAtaque(pikachu);
        float D = getDefesa(defensor);
        float poder = 40;  
        float MT = 1;
        int tipoPokemonAtk = getTipo(pikachu);
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

//! ACRESCENTAR PARAMETROS DA CRIAPOKEMON NO POKEMON.H
