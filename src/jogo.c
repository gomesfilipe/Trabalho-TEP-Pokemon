#include "../include/jogo.h"

void iniciaTabelaCriacaoPokemons(){
    inicPokemons[BLASTOISE] = criaBlastoise;
    inicPokemons[CHARIZARD] = criaCharizard;
    inicPokemons[MEW] = criaMew;
    inicPokemons[PIKACHU] = criaPikachu;
    inicPokemons[STEELIX] = criaSteelix;
    inicPokemons[VENUSAUR] = criaVenusaur;
}

Pokemon* escolhePokemon(int code){
    fptrInic pokemonEscolhido = inicPokemons[code];
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

//batalha
//// funcao sorteia ataque (para o computador)
// funcao que controla o contador de turnosSemJogar e controle os  queimando
//// funcao que restaura 100% do HP do ataque dormirestados quando volta ao normal
//// funcao que aplica o dano de queimar depois de todo turno, caso esteja

//// funcao de ganhar pokebola, tem probabilidade nisso
//// funcao de capturar pokemon (acrescenta um pokemon na lista)
// funcao de fugir
//// funcao que tira pokemon da lista de jogador do jogador quando morre 
//// funcao que calcula porcentagem do hp atual em relacao ao hp maximo
//// sortear proximo pokemon a ser enfrentado
//// funcao de recuperar hp do pokemon entre batalhas

// funcoes de imprimir os menus
// implementar botoes como string e usar atoi quando conveniente

Pokemon* sorteiaPokemon(){
    int aleatorio = rand() % QTDPOKEMONS; // Escolhe um numero de 0 a 5.
    Pokemon *p = escolhePokemon(aleatorio);
    return p;
}

fptrAtaque sorteiaAtaque(Pokemon *p){
     int aleatorio = rand() % QTDATAQUESPOKEMON; // Escolhe um numero de 0 a 2.
     fptrAtaque atk = getAtaquePokemon(p , aleatorio);//vetor de ataques na posicao aleatoria
     return atk;
}

Pokemon* sofreQueimar(Pokemon *p){
    int queimando = getEstado(p, QUEIMAR);
    if(queimando == 1){
        float hpMax = getHPMaximo(p);
        float dano = hpMax / 16.0;
        float hpAtual = getHPAtual(p);
        p = setHPAtual(p, hpAtual - dano);
    }

    return p;
}

// FUNCAO DE JOGADOR ATACA
// tem que ver os estados que o pokemon esta
/**
 * normal, pode jogar
 * dormir e turnos sem jogar != 0, nao pode jogar
 * queimar pode jogar
 * paralisar e turnos sem jogar != 0, nao pode jogar
 * protegido pode jogar
 * esconder nao pode jogar
 * fullhp e turnos sem jogar = 0, hp vai pra 100%
 **/
//so pode tentar capturar o oponente se tiver pokebola e tbm fazer coisa da probabiblidade


//enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO, ESCONDER, FULLHP};

//no final chamar a função de capturar de capurar pokebola
