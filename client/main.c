#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include "../include/telas.h"
#include <time.h>

int main(){
    char *fileNamePlacar = "arquivos_de_saida/placares.txt";
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    jogoPokemon(fileNamePlacar);
    
    return 0;
}
