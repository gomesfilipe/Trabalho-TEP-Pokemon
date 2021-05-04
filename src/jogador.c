#include "../include/jogador.h"

struct jogador{
    char* nome;
    int qtdPokemons;
    int qtdPokebolas;
    int qtdVitorias;
    Lista *pokemons; //vetor de pokemons // usar lista encadeada nessa parte
};

Jogador* criaJogador(char *nome, Lista *pokemons){
    Jogador *jogador = (Jogador*) malloc(sizeof(Jogador));
    jogador->nome = strdup(nome);
    jogador->qtdPokemons = QTDPOKEMONSINICIAIS;
    jogador->qtdPokebolas = QTDPOKEBOLASINICIAIS;
    jogador->qtdVitorias = 0;
    jogador->pokemons = pokemons;
}

void destroiJogador(Jogador* jogador){
    free(jogador->nome);
    destroiLista(jogador->pokemons);
    free(jogador);
}

void imprimeJogador(Jogador *jogador){
    printf("nome [%s]\n", jogador->nome);
    printf("qtdPokemons [%d]\n", jogador->qtdPokemons);
    printf("qtdPokebolas [%d]\n", jogador->qtdPokebolas);
    printf("qtdVitorias [%d]\n", jogador->qtdVitorias);
    imprimeListaDePokemons(jogador->pokemons);
}

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

int getQtdPokemons(Jogador* jogador){
    return jogador->qtdPokemons;
}

int getQtdVitorias(Jogador* jogador){
    return jogador->qtdVitorias;
}

Jogador* setQtdPokebolas(Jogador* jogador , int qtdPokebolas){
    jogador->qtdPokebolas = qtdPokebolas;
}

Jogador* setQtdPokemons(Jogador* jogador , int qtdPokemons){
    jogador->qtdPokemons = qtdPokemons;
}

Jogador* setQtdVitorias(Jogador* jogador , int qtdVitorias){
    jogador->qtdVitorias = qtdVitorias;
}

Lista* getListaPokemons(Jogador* jogador){
    return jogador->pokemons;
}

Pokemon* getPrimeiroPokemonDoJogador(Jogador *jogador){
    Pokemon* p =  getPrimeiroPokemon(jogador->pokemons);
    return p;
}

Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons){
    jogador->pokemons = listaPokemons;
    return jogador;
}

Jogador* morrePokemon(Jogador* jogador){ //passar para o .h 
    jogador->pokemons = removePrimeiroLista(jogador-> pokemons);
    return jogador;
}

Jogador* capturaPokemon(Jogador* jogador, Pokemon *p){  //passar .h
    float hpMax = getHPMaximo(p);//Quando captura um pokemom, seu HpAtual esta no máximo
    p = setHPAtual(p, hpMax);
    jogador->pokemons= adicicionaFinalLista(jogador->pokemons , p);
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


