#include "../include/pokemon.h"
#include "../include/jogador.h"
#include "../include/jogo.h"
#include <time.h>

int main(){
    srand(time(NULL));
    iniciaTabelaCriacaoPokemons();
    inicializaVetorComTodosAtaques();
    //Pokemon *b = escolhePokemon(BLASTOISE);
    Pokemon *c = escolhePokemon(CHARIZARD);
    Pokemon *m = escolhePokemon(MEW);
    //Pokemon *p = escolhePokemon(PIKACHU);
    Pokemon *s = escolhePokemon(STEELIX);
    //Pokemon *v = escolhePokemon(VENUSAUR);

    // lancaChamas(c, p);
    // imprimePokemon(p);
    
    // p = recuperaHPEntreBatalhas(p);
    // imprimePokemon(p);

    Lista* listaFilipe = criaLista(m); //inicialmente so tem pikachu na lista
    listaFilipe = adicicionaFinalLista(listaFilipe, s);
    listaFilipe = adicicionaFinalLista(listaFilipe, c);
    Jogador* filipe = criaJogador("filipe", listaFilipe);
    int aux, aux1;
    
    while(1){
        scanf("%d", &aux1);
        if(aux1 == 6){
            break;
        }
        
        aux = jogadorAtaca(c, aux1, filipe); //atacando o charizard

        imprimeJogador(filipe);
        printf("---------\n");
        imprimePokemon(c);
        printf("\n");
        switch(aux){
            case ATKNORMAL: printf("atk normal\n"); break;
            case ATKMORREU: printf("atk e morreu\n"); break;
            case ATKMATOUMORREU: printf("atk matou e morreu\n"); break;
            case ATKMATOU: printf("atk matou\n"); break;
            case CAPTUROU: printf("capturou\n"); break;
            case NAOCAPTUROU: printf("nao capturou\n"); break;
            case FUGIU: printf("fugiu\n"); break;
            case NAOFUGIU: printf("nao fugiu\n"); break;
        }
        transicaoEntreTurnos(c); //!TESTAR MAIS BATALHAS
    }
    
    //computadorAtaca(Pokemon *atacante, Jogador *jogador);


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
    
    //destroiPokemon(b);
    //destroiPokemon(c);
    //destroiPokemon(m);
    //destroiPokemon(p);
    //destroiPokemon(s);
    //destroiPokemon(v);

    
    return 0;
}
