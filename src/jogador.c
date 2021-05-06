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

char* getNomeJogador(Jogador* jogador){
    return jogador->nome;
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
    Pokemon* p = getPrimeiroPokemon(jogador->pokemons);
    return p;
}

Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons){
    jogador->pokemons = listaPokemons;
    return jogador;
}

Jogador* morrePokemon(Jogador* jogador){ 
    jogador->pokemons = removePrimeiroLista(jogador->pokemons);
    return jogador;
}

Jogador* capturaPokemon(Jogador* jogador, Pokemon *p){ 
    //float hpMax = getHPMaximo(p);
    //p = setHPAtual(p, hpMax); //Quando captura um pokemon, seu HpAtual esta no máximo
    char *nomePokemon = getNomePokemon(p);
    float hpMax = getHPMaximo(p);
    float ataque = getAtaque(p);
    float defesa = getDefesa(p);
    float tipo = getTipo(p);
    fptrAtaque atk1 = getPonteiroAtaque(p, 0);
    fptrAtaque atk2 = getPonteiroAtaque(p, 1);
    fptrAtaque atk3 = getPonteiroAtaque(p, 2);
    char *nomeAtk1 = getNomeAtaque(p, 0);
    char *nomeAtk2 = getNomeAtaque(p, 1);
    char *nomeAtk3 = getNomeAtaque(p, 2);

    Pokemon* aux = criaPokemon(nomePokemon, hpMax, ataque, defesa, tipo, atk1, atk2, atk3, nomeAtk1, nomeAtk2, nomeAtk3);
    jogador->pokemons = adicicionaFinalLista(jogador->pokemons , aux);
    return jogador;
}




