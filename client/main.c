#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include "../include/telas.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();

    menuInicial();

    return 0;
}
