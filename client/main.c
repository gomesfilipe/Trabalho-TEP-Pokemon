#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include "../include/telas.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    // Pokemon *b = escolhePokemon(BLASTOISE);
    // Pokemon *c = escolhePokemon(CHARIZARD);
    // Pokemon *m = escolhePokemon(MEW);
    // Pokemon *p = escolhePokemon(PIKACHU);
    // Pokemon *s = escolhePokemon(STEELIX);
    // Pokemon *v = escolhePokemon(VENUSAUR);

    Lista* l = criaListaPokemonsTela();
    imprimeListaDePokemons(l);
    Pokemon *teste = getPokemonLista(l, 6);
    imprimeNomePokemon(teste);
    //imprimeListaDePokemons(l);
    //printf("---------\n");
    // l = removePokemonQualquerLista(l, 6, 6);
    // l = removePokemonQualquerLista(l, 1, 5);
    // l = removePokemonQualquerLista(l, 2, 4);
    // l = removePokemonQualquerLista(l, 3, 3);
    //imprimeListaDePokemons(l);

    //destroiLista(l); // 79 aloc, 44 fres antes
    // lancaChamas(c, p);
    // imprimePokemon(p);
    
    // p = recuperaHPEntreBatalhas(p);
    // imprimePokemon(p);

    // Lista* listaFilipe = criaLista(m); //inicialmente so o mew
    // //listaFilipe = adicicionaFinalLista(listaFilipe, s);
    // //listaFilipe = adicicionaFinalLista(listaFilipe, c);
    // Jogador* filipe = criaJogador("filipe", listaFilipe);
    // int aux, aux1;
    // int counter = 0;
    

    // while(1){
    //     counter++;
    //     printf("\nloop: [%d]\n", counter);
    //     getchar();
    //     getchar();
        
    //     if(aux1 == 6){
    //         break;
    //     }
        
    //     aux = computadorAtaca(p, filipe); //pikachu atacando filipe (mew)

    //     imprimeJogador(filipe);
    //     printf("---------\n");
    //     //imprimePokemon(p);
    //     printf("\n");
    //     switch(aux){
    //         case ATKNORMAL: printf("atk normal\n"); break;
    //         case ATKMORREU: printf("atk e morreu\n"); break;
    //         case ATKMATOUMORREU: printf("atk matou e morreu\n"); break;
    //         case ATKMATOU: printf("atk matou\n"); break;
    //         case CAPTUROU: printf("capturou\n"); break;
    //         case NAOCAPTUROU: printf("nao capturou\n"); break;
    //         case FUGIU: printf("fugiu\n"); break;
    //         case NAOFUGIU: printf("nao fugiu\n"); break;
    //         case GAMEOVER:printf("game over\n"); break;
    //     }
    //     transicaoEntreTurnos(m); //!TESTAR MAIS BATALHAS
    // }
    


    //imprimePokemon(v);

    //float porcentagem =  porcentagemDeVida(p);
    //printf("\nporentagem [%.2f]\n", porcentagem);
    
    // Lista *listaElaine = criaLista(c);

    // Jogador* jogadorElaine = criaJogador("Elaine", listaElaine);
    // jogadorElaine = morrePokemon( jogadorElaine);

    // imprimeJogador(jogadorElaine);


    //capturaPokebola(Jogador *jogador, int C);   
    //imprimePokemon(p);
    

    //imprimePokemon(b);
    //imprimePokemon(c);
    //imprimePokemon(m);
    //imprimePokemon(p);
    //imprimePokemon(s);
    //imprimePokemon(v);
    
    // destroiPokemon(b);
    // destroiPokemon(c);
    // destroiPokemon(m);
    // destroiPokemon(p);
    // destroiPokemon(s);
    // destroiPokemon(v);

    
    return 0;
}
