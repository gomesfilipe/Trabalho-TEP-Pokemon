#include "../include/telas.h"

void batalha(Jogador* jogador, Lista *listaPC){
    char escolheAtaqueDoJogadorChar[TAM];
    int escolheAtaqueDoJogador;
    char* nomeJogador = getNomeJogador(jogador);
    int vezJogador = 1;
    int direciona1;
    int direciona2;
    int qtdPokebolas; 
    Pokemon *pokemonJogador;
    int qtdVitorias = getQtdVitorias(jogador);
    Pokemon *pokemonDoPC = getPokemonLista(listaPC, 1);
    if(qtdVitorias > 0){
        pokemonDoPC = sorteiaPokemon();
        listaPC = adicicionaFinalLista(listaPC, pokemonDoPC);
    }
   
    printf("Um ");
    imprimeNomePokemon(pokemonDoPC);
    printf(" selvagem aparece!\n\n");
    sleep(TIME);
    
    while(1){
        limpaTela();
        pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
        if(podeJogar(pokemonJogador) == 1 || vezJogador == 0){
            if(vezJogador == 1){
                
                printf("Vez do jogador:\n");
                imprimeMenuAtaque(jogador, pokemonDoPC);
                
                scanf("%s", escolheAtaqueDoJogadorChar);
                getchar(); // Consome o \n.

                escolheAtaqueDoJogador = atoi(escolheAtaqueDoJogadorChar);
                if (escolheAtaqueDoJogador <= 0 || escolheAtaqueDoJogador > 5){
                    printf("Escolha uma opcao valida!\n");
                    sleep(TIME);
                    continue; 
                }
                if(escolheAtaqueDoJogador == 4 ){
                    qtdPokebolas = getQtdPokebolas(jogador);
                    if(qtdPokebolas <= 0 ){
                        printf("Voce nao tem pokebolas suficientes para realizar essa acao!\n");
                        printf("Jogue novamente!\n");
                        sleep(TIME);
                        vezJogador = 1;
                        continue;
                    }
                }
            
                limpaTela();
                direciona1 = jogadorAtaca(pokemonDoPC, escolheAtaqueDoJogador, jogador);          
                pokemonDoPC = sofreQueimar( pokemonDoPC );
                imprimeAtaqueJogador(pokemonJogador, pokemonDoPC, escolheAtaqueDoJogador); 
                transicaoEntreTurnos(pokemonJogador);
                //getchar();
            } 
            
            if(direciona1 == ATKNORMAL || direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU || direciona1 == ATKMORREU || vezJogador == 0){
                if(direciona1 == ATKMORREU){
                    limpaTela();
                    printf("Seu pokemon foi derrotado!\n");
                    printf("O proximo pokemon de sua lista ira substitui-lo.\n\n");
                    jogador = morrePokemon(jogador);
                    pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
                    getchar();
                
                } else if(direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU){
                    printf("Fracasso\n");
                    getchar();
                }

                vezJogador = 1;
                limpaTela();
                printf("Vez do computador:\n");
                if(podeJogar(pokemonDoPC) == 1){
                    direciona2 = computadorAtaca(pokemonDoPC, jogador); 
                    pokemonJogador = sofreQueimar(pokemonJogador);
                    imprimeHPs(pokemonJogador, pokemonDoPC);
                    transicaoEntreTurnos(pokemonDoPC);
                    getchar();
                    
                    if(direciona2 == ATKNORMAL){
                        continue;

                    }else if(direciona2 == ATKMATOU){
                        limpaTela();
                        printf("Seu pokemon foi derrotado!\n");
                        printf("O proximo pokemon de sua lista ira substitui-lo.\n\n");
                        jogador = morrePokemon(jogador);
                        getchar();
                        continue;
                    }
                    else if(direciona2 == GAMEOVER){
                        printf("Todos os seus pokemons foram derrotados! GAME OVER!\n");
                        jogador = morrePokemon(jogador);
                        gameOver(jogador, listaPC);
                        getchar();

                    }else if(direciona2 == ATKMATOUMORREU){
                        limpaTela();
                        printf("%s venceu!\n", nomeJogador);
                        jogador = morrePokemon(jogador);
                        //destroiPokemon(pokemonDoPC);
                        getchar();
                        batalha(jogador, listaPC);
                    }
                    else if(direciona2 == ATKMORREU){
                        limpaTela();
                        printf("%s venceu!\n", nomeJogador);
                        getchar();
                        batalha(jogador, listaPC);
                    }
                }else{
                    limpaTela();
                    printf("Computador nao pode atacar!\n");
                    imprimeEstadoQuandoNaoPodeJogar(pokemonDoPC, pokemonJogador);
                    pokemonJogador = sofreQueimar(pokemonJogador);
                    transicaoEntreTurnos(pokemonDoPC);
                    getchar();
                }

            } else if(direciona1 == GAMEOVER){
                jogador = morrePokemon(jogador);
                gameOver(jogador, listaPC);

            } else if(direciona1 == FUGIU || direciona1 == CAPTUROU || direciona1 == ATKMATOU){
                if(direciona1 == CAPTUROU  || direciona1 == FUGIU){
                    printf("Sucesso\n");
                }
                else if(direciona1 == ATKMATOU){
                    printf("%s venceu!\n", nomeJogador);
                }
                
                getchar();
                batalha(jogador, listaPC); 
                
            }
            else if(direciona1 == ATKMATOUMORREU){
                limpaTela();
                printf("Seu pokemon e o pokemon do computador morreram!\n");
                printf("O proximo pokemon de sua lista ira iniciar a proxima batalha.\n\n");
                jogador = morrePokemon(jogador);
                getchar();
                batalha(jogador, listaPC); 
            }
        }else{
            limpaTela();
            printf("Voce nao pode atacar!\n");
            imprimeEstadoQuandoNaoPodeJogar(pokemonJogador, pokemonDoPC);
            pokemonDoPC = sofreQueimar(pokemonDoPC);
            transicaoEntreTurnos(pokemonJogador);
            if(vezJogador == 1){
                vezJogador = 0;
            }
            direciona1 = -1; // Resetando direciona
            getchar();
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
        limpaTela();
        printf("Qual o seu nome?\n");
        scanf("%s", nome);

        if(!ehStringAlfabetica(nome)){
            printf("Digite um nome valido!\n");
            sleep(TIME);
        
        } else{
            while(tamListaJogador <= QTDPOKEMONSINICIAIS){
                limpaTela();
                printf("Escolha um pokemon da lista:\n");
                imprimeListaDePokemons(listaPokemons);
                scanf("%s", botao);
                botaoint = atoi(botao);

                if(botaoint == 0 || botaoint > tamListaOpcoes){ // Verifica se a entrada do usuário é válida.
                    printf("Digite uma opcao valida.\n");
                    sleep(TIME);
                
                } else{
                    Pokemon *escolhidoAux = getPokemonLista(listaPokemons, botaoint);
                    char *nomePrimeiroPokemon = getNomePokemon(escolhidoAux);
                    float hpMax = getHPMaximo(escolhidoAux);
                    float ataque = getAtaque(escolhidoAux);
                    float defesa = getDefesa(escolhidoAux);
                    float tipo = getTipo(escolhidoAux);
                    fptrAtaque atk1 = getPonteiroAtaque(escolhidoAux, 0);
                    fptrAtaque atk2 = getPonteiroAtaque(escolhidoAux, 1);
                    fptrAtaque atk3 = getPonteiroAtaque(escolhidoAux, 2);
                    char *nomeAtk1 = getNomeAtaque(escolhidoAux, 0);
                    char *nomeAtk2 = getNomeAtaque(escolhidoAux, 1);
                    char *nomeAtk3 = getNomeAtaque(escolhidoAux, 2);

                    Pokemon* escolhido = criaPokemon(nomePrimeiroPokemon, hpMax, ataque, defesa, tipo, atk1, atk2, atk3, nomeAtk1, nomeAtk2, nomeAtk3);
                    
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
                        Pokemon *pokemonDoPC = sorteiaPokemon();
                        Lista *listaPC = criaLista(pokemonDoPC);
                        destroiLista(listaPokemons);
                        batalha(jogador, listaPC);
                    }
                }  
            }
        }
    }
}

void menuInicial(){
    char botao[TAM];
    int botaoint;

    while(1){
        //limpaTela();
        printf("Menu Inicial\n");
        printf("Digite um numero de 1 a 3 para selecionar uma opcao.\n");
        printf("1- Jogar\n");
        printf("2- Melhores pontuacoes\n");
        printf("3- Sair\n");
        
        scanf("%s", botao);
        botaoint = atoi(botao);
        
        if(botaoint == 1){
            jogar();

        } else if(botaoint == 2){
            melhoresPontuacoes();

        } else if(botaoint == 3){
            //sair();
            exit(1);

        } else{
            printf("Escolha uma opcao valida.\n");
            sleep(TIME);
        }
    }
}   

void limpaTela(){
    system("clear"); // clear pra linux, cls pra windows.
}

void imprimeEstadoQuandoNaoPodeJogar(Pokemon *pokemon, Pokemon *defensor){
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
        printf("Segundo turno do ataque cavar!\n\n"); 
        
        cavar(pokemon,defensor);
    }

    imprimeHPs(pokemon, defensor);  //olhar dnv steelix vs steelix
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
        getchar();
    
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
    if(hpPC < 0){
        printf(": 0.00%% HP\n");
    }else{ 
        printf(": %.2f%% HP\n", hpPC);
    }
    imprimeNomePokemon(pokemonJogador);
     if(hpJogador < 0){
        printf(": 0.00%% HP\n");
    }else{ 
        printf(": %.2f%% HP\n", hpJogador);
    }
}

int ImprimeAtaqueMetronomo(){
    int aleatorio = rand() % 13;
    printf("Metronomo sorteou ");
    switch(aleatorio){
        case  0: printf("Choque do trovao"); break;
        case  1: printf("Onda de choque"); break;
        case  2: printf("Bater"); break;
        case  3: printf("Lanca chamas"); break;
        case  4: printf("Dormir"); break;
        case  5: printf("Arma de agua"); break;
        case  6: printf("Proteger"); break;
        case  7: printf("Po de sono"); break;
        case  8: printf("Bomba de semente"); break;
        case  9: printf("Dois gumes"); break;
        case 10: printf("Rabo de ferro"); break;
        case 11: printf("Cavar"); break;
        case 12: printf("Auto-destruir"); break;
    } 
    printf("!\n");
    return aleatorio;
}


//ranking
//readme

//// imprimir qual atk o metronomo sorteou
//// resolver problema do nome do jogador, ta imprimindo nome do pokemon quando vence
//// imprimir na captura de pokemon e na fuga se foi fracasso ou sucesso
//// ver se ainda falta getchar ou algo relacionado
//// fazer gameover
// fazer classificacao e log de batalhas
// fazer lista encadeada de jogadores
// imprimir algo do tipo "voce esta na sua batalha x, partida y"
// argc e argv
// makefile
