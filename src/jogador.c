#include "../include/jogador.h"



struct jogador{
    char* nome;
    int qtdPokemons;
    int qtdPokebolas;
    int qtdVitorias;
    Lista *pokemons; //vetor de pokemons // usar lista encadeada nessa parte
};

Jogador* capturaPokebola(Jogador *jogador, int C){  //ver se ta certa, testar
    float probabilidade = C/12;
    float aleatorio = (float)rand()/(float)(12);

    if(aleatorio <= probabilidade){
      jogador->qtdPokebolas++;
    }

    return jogador;
}


