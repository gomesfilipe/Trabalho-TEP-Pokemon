#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include "../include/telas.h"
#include <time.h>

void imprimeArquivo(FILE *f);

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();

    menuInicial();
    //char string[100];
    // int x;
    // FILE *f = fopen("testando.txt", "a");
    // if(f == NULL){
    //     printf("erro\n");
    //     exit(1);
    // }

    
    // while(1){
    //     scanf("%d", &x);
    //     fprintf(f, "[%d]\n", x);
    //     if(x == 5){
    //         break;
    //     }
    // }
    // imprimeArquivo(stdout);
    // imprimeArquivo(f);
    // fprintf(f, "1\n");
    // getchar();
    // fprintf(f, "2\n");
    // getchar();

    // fclose(f);
    return 0;
}

void imprimeArquivo(FILE *f){
    fprintf(f, "\ttestando\n");
}
