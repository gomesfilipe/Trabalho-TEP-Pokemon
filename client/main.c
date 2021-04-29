#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"

int main(){
    iniciaTabelaCriacaoPokemons();
    Pokemon *b = escolhePokemon('B');
    Pokemon *c = escolhePokemon('C');
    Pokemon *m = escolhePokemon('M');
    Pokemon *p = escolhePokemon('P');
    Pokemon *s = escolhePokemon('S');
    Pokemon *v = escolhePokemon('V');

    imprimePokemon(b);
    imprimePokemon(c);
    imprimePokemon(m);
    imprimePokemon(p);
    imprimePokemon(s);
    imprimePokemon(v);

    return 0;
}
