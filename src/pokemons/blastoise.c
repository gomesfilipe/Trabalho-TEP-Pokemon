#include "../../include/pokemons/blastoise.h"

Pokemon* criaBlastoise(){
    fptrAtaque atk1 = armaDeAgua;
    fptrAtaque atk2 = proteger;
    fptrAtaque atk3 = baterBlastoise;
    
    Pokemon *blastoise = criaPokemon("Blastoise", 280, 180, 200, AGUA, atk1, atk2, atk3, "Arma de agua", "Proteger", "Bater");
    return blastoise;
}

void armaDeAgua(Pokemon *blastoise, Pokemon *defensor){
    if(estaImune(defensor) == 0){
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
}

void proteger(Pokemon *blastoise, Pokemon *defensor){
    blastoise = setEstado(blastoise, PROTEGIDO, 1); 
    blastoise = setTurnosNumEstado(blastoise, PROTEGIDO , 2);
    blastoise = setEstado(blastoise, NORMAL, 0);
}

void baterBlastoise(Pokemon *blastoise, Pokemon *defensor){
    if(estaImune(defensor) == 0) {
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
}
