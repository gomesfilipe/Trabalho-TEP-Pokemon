#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    Pokemon *b = escolhePokemon(BLASTOISE);
    Pokemon *c = escolhePokemon(CHARIZARD);
    Pokemon *m = escolhePokemon(MEW);
    Pokemon *p = escolhePokemon(PIKACHU);
    Pokemon *s = escolhePokemon(STEELIX);
    Pokemon *v = escolhePokemon(VENUSAUR);

    metronomo(m, p);
    
    imprimePokemon(m);
    printf("\n");
    imprimePokemon(p);

    // cavar(s, v);
    // printf("\nsegundo cavar!\n");
    // imprimePokemon(s);
    // printf("\n");
    // imprimePokemon(v);
    
    // Lista* l = criaLista(b);
    // l = adicicionaFinalLista(l, c);
    // l = adicicionaFinalLista(l, m);
    // l = adicicionaFinalLista(l, p);
    // l = adicicionaFinalLista(l, s);
    // l = adicicionaFinalLista(l, v);

    //imprimeLista(l);

    //l = removePrimeiroLista(l);

    //imprimeLista(l);
    
    //destroiLista(l);
    // imprimePokemon(b);
    // imprimePokemon(c);
    // imprimePokemon(m);
    // imprimePokemon(p);
    // imprimePokemon(s);
    // imprimePokemon(v);
    
    //destroiPokemon(b);
    // destroiPokemon(c);
    // destroiPokemon(m);
    //destroiPokemon(p);
    // destroiPokemon(s);
    // destroiPokemon(v);

    // float matriz[QTDTIPOS][QTDTIPOS];
    // inicializaMatrizRelacaoTipos(matriz);

    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < 6; j++){
    //         printf("%.1f  ", matriz[i][j]);
    //     }

    //     printf("\n");
    // }


    //testando a lista


    return 0;
}
