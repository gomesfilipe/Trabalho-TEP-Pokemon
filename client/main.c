#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    Pokemon *b = escolhePokemon('B');
    // Pokemon *c = escolhePokemon('C');
    // Pokemon *m = escolhePokemon('M');
    Pokemon *p = escolhePokemon('P');
    // Pokemon *s = escolhePokemon('S');
    // Pokemon *v = escolhePokemon('V');
    imprimePokemon(b);
    imprimePokemon(p);

    choqueDoTrovao(p, b);

    // imprimePokemon(c);
    // imprimePokemon(m);
    // imprimePokemon(s);
    // imprimePokemon(v);
    
    imprimePokemon(b);


    destroiPokemon(b);
    // destroiPokemon(c);
    // destroiPokemon(m);
    destroiPokemon(p);
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

    return 0;
}
