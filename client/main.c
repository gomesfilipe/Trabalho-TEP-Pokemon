#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    // Pokemon *b = escolhePokemon(BLASTOISE);
    Pokemon *c = escolhePokemon(CHARIZARD);
    Pokemon *m = escolhePokemon(MEW);
    Pokemon *p = escolhePokemon(PIKACHU);
    // Pokemon *s = escolhePokemon(STEELIX);
    //Pokemon *v = escolhePokemon(VENUSAUR);
    
    Lista *listaElaine;
    listaElaine = criaLista(p);
    listaElaine = capturaPokemon(listaElaine, m);
    listaElaine = capturaPokemon(listaElaine, c);
    Jogador* elaine = criaJogador("Elaine", listaElaine);
    imprimeJogador(elaine);

    //Lista* listaAux;
    //listaAux= getListaPokemons(elaine);
    //listaElaine
    listaElaine = morrePokemon(listaElaine);  //mudar dps

    imprimeJogador(elaine);

    //capturaPokebola(Jogador *jogador, int C);

   
    //imprimePokemon(v);
    //imprimePokemon(p);
    

    // imprimePokemon(b);
    // imprimePokemon(c);
    // imprimePokemon(m);
    // imprimePokemon(p);
    // imprimePokemon(s);
    // imprimePokemon(v);
    
    //destroiPokemon(b);
    destroiPokemon(c);
    destroiPokemon(m);
    //destroiPokemon(p);
    // destroiPokemon(s);
    // destroiPokemon(v);

    
    return 0;
}
