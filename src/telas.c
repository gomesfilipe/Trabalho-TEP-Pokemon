#include "../include/telas.h"

void batalha(Jogador* jogador){
    int escolheAtaqueDoJogador;
    int direciona1;
    int direciona2;
    Pokemon *pokemonJogador;
    Pokemon *pokemonDoPC = sorteiaPokemon();
    
    while(1){
        printf("Vez do jogador:\n");
        printf("Digite um numero de 1 a 5:\n");
        scanf("%d", &escolheAtaqueDoJogador);
        direciona1 = jogadorAtaca(pokemonDoPC, escolheAtaqueDoJogador, jogador);
        pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
        transicaoEntreTurnos(pokemonJogador);
        
        if( direciona1 == ATKNORMAL || direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU || direciona1 == ATKMORREU ){
            printf("Vez do computador:\n");
            direciona2 = computadorAtaca(pokemonDoPC, jogador);
            transicaoEntreTurnos(pokemonDoPC);
            
            if(direciona2 == ATKNORMAL || direciona2 == ATKMATOU){
                continue;
                //direciona1 = jogadorAtaca(pokemonDoPC, escolheAtaqueDoJogador, jogador);

            }else if(direciona2 == GAMEOVER ){
                gameOver(jogador, pokemonDoPC);

            }else if(direciona2 == ATKMORREU || direciona2 == ATKMATOUMORREU ){
                batalha(jogador);
            }

 
        } else if(direciona1 == GAMEOVER ){
            gameOver(jogador, pokemonDoPC );

        } else if(direciona1 == FUGIU || direciona1 == CAPTUROU || direciona1 == ATKMATOU || direciona1== ATKMATOUMORREU ){
            batalha(jogador); 
            
        }
    }
}

void melhoresPontuacoes(){

}

void sair(){

}

void jogar(){
    char nome[TAM];
    char botao[TAM];
    int botaoint, tamListaOpcoes = QTDPOKEMONS, tamListaJogador = 0;
    Lista *listaPokemons = criaListaPokemonsTela();
    Lista *listaJogador;
    Jogador* jogador;
    while(1){
        printf("Qual o seu nome?\n");
        scanf("%s", nome);

        if(!ehStringAlfabetica(nome)){
            printf("Digite um nome valido!\n");
        
        } else{
            while(tamListaJogador <= QTDPOKEMONSINICIAIS){
                printf("Escolha um pokemon da lista:\n");
                imprimeListaDePokemons(listaPokemons);
                scanf("%s", botao);
                botaoint = atoi(botao);

                if(botaoint == 0 || botaoint > tamListaOpcoes){ // Verifica se a entrada do usuário é válida.
                    printf("Digite uma opcao valida.\n");
                
                } else{
                    Pokemon *escolhido = getPokemonLista(listaPokemons, botaoint);
                    listaPokemons = removePokemonQualquerLista(listaPokemons, botaoint, tamListaOpcoes);
                    tamListaOpcoes--; // Controlando tamanho das listas.
                    tamListaJogador++;
                    if(tamListaJogador == 1){ // Se tiver 1 pokemon, cria a lista com o primeiro elemento.
                        listaJogador = criaLista(escolhido);
                    
                    } else if(tamListaJogador < QTDPOKEMONSINICIAIS){
                        listaJogador = adicicionaFinalLista(listaJogador, escolhido);
                    }
                   
                    else if(tamListaJogador == QTDPOKEMONSINICIAIS){ // Quando a lista de pokemons chega a 3, finalmente cria o jogador.
                        listaJogador = adicicionaFinalLista(listaJogador, escolhido);
                        jogador = criaJogador(nome, listaJogador);
                        batalha(jogador);
                    }
                }  
            }
        }
    }
}

void menuInicial(){
    char botao[TAM];
    int botaoint;
    printf("Menu Inicial\n");
    printf("Digite um numero de 1 a 3 para selecionar uma opcao.\n");
    printf("1- Jogar\n");
    printf("2- Melhores pontuacoes\n");
    printf("3- Sair\n");

    while(1);
        scanf("%s", botao);
        botaoint = atoi(botao);
        if(botaoint == 1){
            jogar();

        } else if(botaoint == 2){
            melhoresPontuacoes();

        } else if(botaoint == 3){
            sair();

        } else{
            printf("Escolha uma opcao valida.\n");
        }
}   

void limpaTela(){
    system("clear"); // clear pra linux, cls pra windows.
}






