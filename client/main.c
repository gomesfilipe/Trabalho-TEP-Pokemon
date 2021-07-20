#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include "../include/telas.h"
#include <time.h>

int main(int argc, char** argv){

    if ( argc < 4 ) {
        printf("Numero de argumentos incorreto");
        return 0;
    }

    char fileNamePlacar[TAM];
    strcpy(fileNamePlacar, argv[1]);
    
    char fileNameLog[TAM];
    strcpy(fileNameLog, argv[2]);
    
    int semente = atoi(argv[3]); 
    srand(semente);
 
    // char *fileNameLog = "arquivos_de_saida/logs.txt";
    // char *fileNamePlacar = "arquivos_de_saida/placares.txt";
    
    //srand(time(NULL));

    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    jogoPokemon(fileNamePlacar, fileNameLog);
    
    return 0;
}

