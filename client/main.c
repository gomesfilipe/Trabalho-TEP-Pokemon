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
    //Pokemon *m = escolhePokemon(MEW);
    Pokemon *p = escolhePokemon(PIKACHU);
    //Pokemon *s = escolhePokemon(STEELIX);
    //Pokemon *v = escolhePokemon(VENUSAUR);

    lancaChamas(c, p);
    imprimePokemon(p);
    
    p = recuperaHPEntreBatalhas(p);
    imprimePokemon(p);
    
    


    //float porcentagem =  porcentagemDeVida(p);
    //printf("\nporentagem [%.2f]\n", porcentagem);
    
    // Lista *listaElaine = criaLista(c);
    // listaElaine = adicicionaFinalLista(listaElaine, m);
    // listaElaine = adicicionaFinalLista(listaElaine, p);

    // Jogador* jogadorElaine = criaJogador("Elaine", listaElaine);
    // jogadorElaine = capturaPokemon( jogadorElaine, s );
    // jogadorElaine = morrePokemon( jogadorElaine);

    // imprimeJogador(jogadorElaine);


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
    //destroiPokemon(c);
    //destroiPokemon(m);
    //destroiPokemon(p);
    //destroiPokemon(s);
    // destroiPokemon(v);

    
    return 0;
}
