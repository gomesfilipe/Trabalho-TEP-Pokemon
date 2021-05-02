#include "../include/jogador.h"

struct jogador{
    char* nome;
    int qtdPokemons;
    int qtdPokebolas;
    int qtdVitorias;
    Lista *pokemons; //vetor de pokemons // usar lista encadeada nessa parte
};

Jogador* capturaPokebola(Jogador *jogador, int C){  //ver se ta certa, testar
    float probabilidade = C/12.0;
    float aleatorio = (float)rand()/(float)(RAND_MAX);

    if(aleatorio <= probabilidade){
        jogador->qtdPokebolas++;
    }

    return jogador;
}

int getQtdPokebolas(Jogador* jogador){
    return jogador->qtdPokebolas;
}

Lista* getListaPokemons(Jogador* jogador){
    return jogador->pokemons;
}

Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons){
    jogador->pokemons = listaPokemons;
    return jogador;
}


// FUNCAO DE JOGADOR ATACA
// tem que ver os estados que o pokemon esta
/**
 * dormir e turnos sem jogar != 0, nao pode jogar
 * paralisar e turnos sem jogar != 0, nao pode jogar
 * esconder nao pode jogar
 * 
 * normal, pode jogar
 * queimar pode jogar
 * protegido pode jogar
 * fullhp e turnos sem jogar = 0, hp vai pra 100%
 **/
//so pode tentar capturar o oponente se tiver pokebola e tbm fazer coisa da probabiblidade


//enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO, ESCONDER, FULLHP};

//no final chamar a função de capturar de capurar pokebola

//OBS: nao fazer o controle de turnosNumEstado para o steelix, ja fizemos na funcao.


