#include "../include/telas.h"

void batalha(Jogador* jogador){
    char escolheAtaqueDoJogadorChar[TAM];
    int escolheAtaqueDoJogador;
    int vezJogador = 1;
    int direciona1;
    int direciona2;
    Pokemon *pokemonJogador; //= getPrimeiroPokemonDoJogador(jogador);
    Pokemon *pokemonDoPC = sorteiaPokemon();
    printf("Um ");
    imprimeNomePokemon(pokemonDoPC);
    printf(" selvagem aparece!\n\n");
    
    while(1){
        pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
        if(podeJogar(pokemonJogador) == 1 || vezJogador == 0){
            if(vezJogador == 1){
                
                printf("Vez do jogador:\n");
                printf("Digite um numero de 1 a 5:\n");
                imprimeMenuAtaque(jogador, pokemonDoPC);
                
                scanf("%s", escolheAtaqueDoJogadorChar);
                escolheAtaqueDoJogador = atoi(escolheAtaqueDoJogadorChar);
                if (escolheAtaqueDoJogador <= 0 || escolheAtaqueDoJogador > 5){
                    printf("Escolha uma opcao valida!\n");
                    continue; 
                }
            
                direciona1 = jogadorAtaca(pokemonDoPC, escolheAtaqueDoJogador, jogador);          
                pokemonDoPC = sofreQueimar( pokemonDoPC );
                imprimeAtaqueJogador(pokemonJogador, pokemonDoPC, escolheAtaqueDoJogador);
                transicaoEntreTurnos(pokemonJogador);
            }
          
            if(direciona1 == ATKNORMAL || direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU || direciona1 == ATKMORREU || vezJogador == 0){
                if(vezJogador == 0){
                    vezJogador = 1;
                } else if(vezJogador == 1){
                    vezJogador = 0;
                }
                
                printf("Vez do computador:\n");
                if(podeJogar(pokemonDoPC) == 1){
                    direciona2 = computadorAtaca(pokemonDoPC, jogador); 
                    pokemonJogador = sofreQueimar(pokemonJogador);
                    imprimeHPs(pokemonJogador, pokemonDoPC);
                    transicaoEntreTurnos(pokemonDoPC);
                    
                    if(direciona2 == ATKNORMAL){
                        continue;

                    }else if(direciona2 == ATKMATOU){
                        printf("Seu pokemon foi derrotado!\n");
                        printf("O proximo pokemon de sua lista ira substitui-lo.\n\n");
                        jogador = morrePokemon(jogador);
                        continue;
                    }
                    else if(direciona2 == GAMEOVER ){
                        printf("Todos os seus pokemons foram derrotados! GAME OVER!\n");
                        
                        gameOver(jogador, pokemonDoPC);

                    }else if(direciona2 == ATKMORREU || direciona2 == ATKMATOUMORREU ){
                        batalha(jogador);
                    }
                }else{
                    printf("Computador nao pode atacar!\n");
                    imprimeEstadoQuandoNaoPodeJogar(pokemonDoPC);
                  
                    pokemonJogador = sofreQueimar( pokemonJogador );
                    transicaoEntreTurnos(pokemonDoPC);
            
                    //getc(stdin);
                    //getchar();
                }

            } else if(direciona1 == GAMEOVER ){
                gameOver(jogador, pokemonDoPC );

            } else if(direciona1 == FUGIU || direciona1 == CAPTUROU || direciona1 == ATKMATOU || direciona1 == ATKMATOUMORREU ){
                batalha(jogador); 
                
            }
        }else{
            printf("Voce nao pode atacar!\n");
            imprimeEstadoQuandoNaoPodeJogar(pokemonJogador);
            pokemonDoPC = sofreQueimar(pokemonDoPC);
            transicaoEntreTurnos(pokemonDoPC);
            if(vezJogador == 1){
                vezJogador = 0;
            }

            //getchar();
            //getc(stdin);
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
                    Pokemon *escolhidoAux = getPokemonLista(listaPokemons, botaoint);
                    char *nome = getNomePokemon(escolhidoAux);
                    float hpMax = getHPMaximo(escolhidoAux);
                    float ataque = getAtaque(escolhidoAux);
                    float defesa = getDefesa(escolhidoAux);
                    float tipo = getTipo(escolhidoAux);
                    fptrAtaque atk1 = getPonteiroAtaque(escolhidoAux, 0);
                    fptrAtaque atk2 = getPonteiroAtaque(escolhidoAux, 1);;
                    fptrAtaque atk3 = getPonteiroAtaque(escolhidoAux, 2);;
                    char *nomeAtk1 = getNomeAtaque(escolhidoAux, 0);
                    char *nomeAtk2 = getNomeAtaque(escolhidoAux, 1);
                    char *nomeAtk3 = getNomeAtaque(escolhidoAux, 2) ;
                    Pokemon* escolhido = criaPokemon(nome, hpMax, ataque, defesa, tipo, atk1, atk2, atk3, nomeAtk1, nomeAtk2, nomeAtk3);
                    
                    
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

    while(1){
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
}   

void limpaTela(){
    system("clear"); // clear pra linux, cls pra windows.
}

void imprimeEstadoQuandoNaoPodeJogar(Pokemon *pokemon){
    int dormir = getEstado(pokemon, DORMIR);
    int paralisar = getEstado(pokemon, PARALISAR);
    int esconder = getEstado(pokemon, ESCONDER);
    if(dormir  == 1){
        imprimeNomePokemon(pokemon);
        printf(" esta dormindo!\n");
    }
    else if(paralisar == 1){
        imprimeNomePokemon(pokemon);
        printf(" esta paralisado!\n");
    }
    else if(esconder == 1){
        printf("Segundo turno do ataque cavar!\n");
    }
}

void imprimeMenuAtaque(Jogador *jogador, Pokemon* pokemonDoPC){
    int qtdPokebolas = getQtdPokebolas(jogador);
    Pokemon *atacante = getPrimeiroPokemonDoJogador(jogador);
    float hpPC = porcentagemDeVida(pokemonDoPC);
    float hpJogador = porcentagemDeVida(atacante);
    
    imprimeNomePokemon(pokemonDoPC);
    printf(": %.2f%% HP\n", hpPC);
    imprimeNomePokemon(atacante);
    printf(": %.2f%% HP\n\n", hpJogador);
    
    printf("Escolha um movimento:\n");
    imprimeAtaquesPokemon(atacante);
    if(qtdPokebolas == 1){
        printf("4- Pokebolas (%d disponivel)\n", qtdPokebolas);

    }else{
        printf("4- Pokebolas (%d disponiveis)\n", qtdPokebolas);
    }   
    printf("5- Fugir\n");
}

void imprimeAtaqueJogador(Pokemon *pokemonJogador, Pokemon *pokemonDoPC, int numAtk){
    if(numAtk >= 1 && numAtk <= 3){
        imprimeNomePokemon(pokemonJogador);
        printf(" usou ");
        imprimeAtaque(pokemonJogador, numAtk);
        printf("\n");
        imprimeHPs(pokemonJogador, pokemonDoPC);
    
    } else if(numAtk == 4){
        printf("Tentativa de captura\n");
    
    } else if(numAtk == 5){
        printf("Tentativa de fuga\n");

    }
}

void imprimeHPs(Pokemon *pokemonJogador, Pokemon *pokemonDoPC){
    float hpPC = porcentagemDeVida(pokemonDoPC);
    float hpJogador = porcentagemDeVida(pokemonJogador);
    
    imprimeNomePokemon(pokemonDoPC);
    printf(": %.2f%% HP\n", hpPC);
    imprimeNomePokemon(pokemonJogador);
    printf(": %.2f%% HP\n\n", hpJogador);
}


//controlar fluxo
//log de batalhas
//ranking
//readme


