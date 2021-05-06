#include "../include/telas.h"

void batalha(Jogador* jogador, Lista *listaPC, FILE *f){
    char escolheAtaqueDoJogadorChar[TAM];
    int escolheAtaqueDoJogador;
    char* nomeJogador = getNomeJogador(jogador);
    int vezJogador = 1;
    int direciona1;
    int direciona2;
    int qtdPokebolas; 
    Pokemon *pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
    int qtdVitorias = getQtdVitorias(jogador);
    Pokemon *pokemonDoPC = getPokemonLista(listaPC, 1);
    if(qtdVitorias > 0){
        pokemonDoPC = sorteiaPokemon();
        listaPC = adicicionaFinalLista(listaPC, pokemonDoPC);
    }

    char* nomePokemonJogador = getNomePokemon(pokemonJogador); 
    char* nomePokemonPC = getNomePokemon(pokemonDoPC);
    
    printf("\tUm ");
    imprimeNomePokemon(pokemonDoPC, stdout);
    printf(" selvagem aparece!\n\n");

    //! COLOCAR NUMERO DA BATALHA E PARTIDA COM FPRINTF AQUI DEPOIS DE FAZER A LISTA ENCADEADA DE JOGADORES
    fprintf(f, "x.x- %s vs %s\n", nomePokemonJogador , nomePokemonPC); //log de batalhas
    sleep(TIME);
    
    while(1){
        limpaTela();
        pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
        if(podeJogar(pokemonJogador) == 1 || vezJogador == 0){
            if(vezJogador == 1){
                printf("\tVez do jogador:\n\n");
                imprimeMenuAtaque(jogador, pokemonDoPC);
                
                scanf("%s", escolheAtaqueDoJogadorChar);
                getchar(); // Consome o \n.

                escolheAtaqueDoJogador = atoi(escolheAtaqueDoJogadorChar);
                if (escolheAtaqueDoJogador <= 0 || escolheAtaqueDoJogador > 5){
                    printf("\tEscolha uma opcao valida!\n");
                    sleep(TIME);
                    continue; 
                }
                if(escolheAtaqueDoJogador == 4 ){
                    qtdPokebolas = getQtdPokebolas(jogador);
                    if(qtdPokebolas <= 0 ){
                        printf("\tVoce nao tem pokebolas suficientes para realizar essa acao!\n");
                        printf("\tJogue novamente!\n");
                        sleep(TIME);
                        vezJogador = 1;
                        continue;
                    }
                }
            
                limpaTela();
                direciona1 = jogadorAtaca(pokemonDoPC, escolheAtaqueDoJogador, jogador);          
                pokemonDoPC = sofreQueimar(pokemonDoPC);
                imprimeAtaqueJogador(pokemonJogador, pokemonDoPC, escolheAtaqueDoJogador, f);
                imprimeAtaqueJogador(pokemonJogador, pokemonDoPC, escolheAtaqueDoJogador, stdout); 
                transicaoEntreTurnos(pokemonJogador);
                //getchar();
            } 
            
            if(direciona1 == ATKNORMAL || direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU || direciona1 == ATKMORREU || vezJogador == 0){
                if(direciona1 == ATKMORREU){
                    limpaTela();
                    fprintf(f,"\t%s perde!\n\n", nomeJogador);
                    printf("\t%s perde!\n\n", nomeJogador);
                    printf("\tO proximo pokemon de sua lista ira substitui-lo.\n\n");
                    jogador = morrePokemon(jogador);
                    pokemonJogador = getPrimeiroPokemonDoJogador(jogador);
                    getchar();
                
                } else if(direciona1 == NAOCAPTUROU || direciona1 == NAOFUGIU){
                    printf("\tFracasso\n\n");
                    fprintf(f, "\tFracasso\n\n");
                    getchar();
                }

                vezJogador = 1;
                limpaTela();
                printf("\tVez do computador:\n\n");
                if(podeJogar(pokemonDoPC) == 1){
                    direciona2 = computadorAtaca(pokemonDoPC, jogador, f); 
                    pokemonJogador = sofreQueimar(pokemonJogador);
                    imprimeHPs(pokemonJogador, pokemonDoPC, f);
                    imprimeHPs(pokemonJogador, pokemonDoPC, stdout);
                    transicaoEntreTurnos(pokemonDoPC);
                    getchar();
                    
                    if(direciona2 == ATKNORMAL){
                        continue;

                    }else if(direciona2 == ATKMATOU){
                        limpaTela();
                        fprintf(f,"\t%s perde!\n\n", nomeJogador);
                        printf("\t%s perde!\n\n", nomeJogador);
                        printf("\tO proximo pokemon de sua lista ira substitui-lo.\n\n");
                        jogador = morrePokemon(jogador);
                        getchar();
                        continue;
                    }
                    else if(direciona2 == GAMEOVER){
                        printf("\tFim do jogo <numero_da_partida> %s sobreviveu %d batalhas\n\n", nomeJogador, qtdVitorias);
                        fprintf(f,"\tFim do jogo <numero_da_partida> %s sobreviveu %d batalhas\n\n", nomeJogador, qtdVitorias);
                        //! fazer o numero da partida.
                        
                        jogador = morrePokemon(jogador);
                        getchar();
                        gameOver(jogador, listaPC, f);

                    }else if(direciona2 == ATKMATOUMORREU){
                        limpaTela();
                        fprintf(f, "\t%s vence!\n\n", nomeJogador);
                        fprintf(stdout, "\t%s vence!\n\n", nomeJogador);
                        jogador = morrePokemon(jogador);
                        //destroiPokemon(pokemonDoPC);
                        getchar();
                        batalha(jogador, listaPC, f);
                    }
                    else if(direciona2 == ATKMORREU){
                        limpaTela();
                        fprintf(f, "\t%s vence!\n\n", nomeJogador);
                        fprintf(stdout, "\t%s vence!\n\n", nomeJogador);
                        getchar();
                        batalha(jogador, listaPC, f);
                    }
                }else{
                    limpaTela();
                    printf("\tComputador nao pode atacar!\n");
                    imprimeEstadoQuandoNaoPodeJogar(pokemonDoPC, pokemonJogador);
                    pokemonJogador = sofreQueimar(pokemonJogador);
                    transicaoEntreTurnos(pokemonDoPC);
                    getchar();
                }

            } else if(direciona1 == GAMEOVER){
                fprintf(stdout,"\tFim do jogo <numero_da_partida> %s sobreviveu %d batalhas\n\n", nomeJogador, qtdVitorias);
                fprintf(f,"\tFim do jogo <numero_da_partida> %s sobreviveu %d batalhas\n\n", nomeJogador, qtdVitorias);
                jogador = morrePokemon(jogador);
                getchar();
                gameOver(jogador, listaPC, f);

            } else if(direciona1 == FUGIU || direciona1 == CAPTUROU || direciona1 == ATKMATOU){
                if(direciona1 == CAPTUROU  || direciona1 == FUGIU){
                    fprintf(f,"\tSucesso\n\n");
                    fprintf(stdout,"\tSucesso\n\n");
                }
                else if(direciona1 == ATKMATOU){
                    fprintf(f, "\t%s vence!\n\n", nomeJogador);
                    fprintf(stdout, "\t%s vence!\n\n", nomeJogador);
                }
                
                getchar();
                batalha(jogador, listaPC, f); 
                
            }
            else if(direciona1 == ATKMATOUMORREU){
                limpaTela();
                printf("\tSeu pokemon e o pokemon do computador morreram!\n");
                printf("\tO proximo pokemon de sua lista ira iniciar a proxima batalha.\n\n");
                jogador = morrePokemon(jogador);
                getchar();
                batalha(jogador, listaPC, f); 
            }
        }else{
            limpaTela();
            printf("\tVoce nao pode atacar!\n");
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

    //char *fileNameLog = "logDeBatalhas1";
    char *fileNameLog = "arquivos_de_saida/logDeBatalhas";
    FILE *log = fopen(fileNameLog, "a"); // Abrindo arquivo do log de batalhas.
    if(log == NULL){
       printf("Erro na abertura do arquivo\n");
       exit(1); 
    }

    while(1){
        limpaTela();
        printf("\tQual o seu nome?\n");
        scanf("%s", nome);

        if(!ehStringAlfabetica(nome)){
            printf("\tDigite um nome valido!\n");
            sleep(TIME);
        
        } else{
            while(tamListaJogador <= QTDPOKEMONSINICIAIS){
                limpaTela();
                printf("\tEscolha um pokemon da lista:\n");
                imprimeListaDePokemons(listaPokemons);
                scanf("%s", botao);
                botaoint = atoi(botao);

                if(botaoint == 0 || botaoint > tamListaOpcoes){ // Verifica se a entrada do usuário é válida.
                    printf("\tDigite uma opcao valida.\n");
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
                        batalha(jogador, listaPC, log);
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
        limpaTela();
        printf("\tMenu Inicial\n");
        printf("\tDigite um numero de 1 a 3 para selecionar uma opcao.\n");
        printf("\t1- Jogar\n");
        printf("\t2- Melhores pontuacoes\n");
        printf("\t3- Sair\n");
        
        scanf("%s", botao);
        botaoint = atoi(botao);
        
        if(botaoint == 1){
            jogar();

        } else if(botaoint == 2){
            melhoresPontuacoes();

        } else if(botaoint == 3){
            //sair();
            exit(0);

        } else{
            printf("\tEscolha uma opcao valida.\n");
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
        printf("\t");
        imprimeNomePokemon(pokemon, stdout);
        printf(" esta dormindo!\n");
    }
    
    if(paralisar == 1){
        printf("\t");
        imprimeNomePokemon(pokemon, stdout);
        printf(" esta paralisado!\n");
    }
    
    if(esconder == 1){
        printf("\tSegundo turno do ataque cavar!\n\n"); 
        cavar(pokemon,defensor);
    }

    imprimeHPs(pokemon, defensor, stdout);  //olhar dnv steelix vs steelix
}

void imprimeMenuAtaque(Jogador *jogador, Pokemon* pokemonDoPC){
    int qtdPokebolas = getQtdPokebolas(jogador);
    Pokemon *atacante = getPrimeiroPokemonDoJogador(jogador);
    float hpPC = porcentagemDeVida(pokemonDoPC);
    float hpJogador = porcentagemDeVida(atacante);
    
    printf("\t");
    imprimeNomePokemon(pokemonDoPC, stdout);
    printf(": %.2f%% HP\n", hpPC);
    printf("\t");
    imprimeNomePokemon(atacante, stdout);
    printf(": %.2f%% HP\n\n", hpJogador);
    
    printf("\tEscolha um movimento:\n");
    imprimeAtaquesPokemon(atacante);
    if(qtdPokebolas == 1){
        printf("\t4- Pokebolas (%d disponivel)\n", qtdPokebolas);

    }else{
        printf("\t4- Pokebolas (%d disponiveis)\n", qtdPokebolas);
    }   
    printf("\t5- Fugir\n");
}

void imprimeAtaqueJogador(Pokemon *pokemonJogador, Pokemon *pokemonDoPC, int numAtk, FILE *f){
    if(numAtk >= 1 && numAtk <= 3){
        fprintf(f, "\t");
        imprimeNomePokemon(pokemonJogador, f);
        fprintf(f," usa ");
        imprimeAtaque(pokemonJogador, numAtk, f);
        imprimeHPs(pokemonJogador, pokemonDoPC, f);
        
        if(f == stdout){
            getchar();
        }
        
    } else if(numAtk == 4){
        fprintf(f, "\tTentativa de captura\n");
    
    } else if(numAtk == 5){
        fprintf(f, "\tTentativa de fuga\n");
    }
}

void imprimeHPs(Pokemon *pokemonJogador, Pokemon *pokemonDoPC , FILE *f){
    float hpPC = porcentagemDeVida(pokemonDoPC);
    float hpJogador = porcentagemDeVida(pokemonJogador);
    
    fprintf(f, "\t");
    imprimeNomePokemon(pokemonDoPC, f);
    if(hpPC < 0){
        fprintf(f, ": 0.00%% HP "); 
        
    }else{ 
        fprintf(f, ": %.2f%% HP ", hpPC);
    }
    imprimeEstadosLog(pokemonDoPC, f);
    fprintf(f, "\n\t");
    imprimeNomePokemon(pokemonJogador, f);
     if(hpJogador < 0){
        fprintf(f, ": 0.00%% HP ");
    }else{ 
        fprintf(f, ": %.2f%% HP ", hpJogador);
    }
    imprimeEstadosLog(pokemonJogador, f);
    fprintf(f, "\n\n");
}

int ImprimeAtaqueMetronomo(){
    int aleatorio = rand() % 13;
    printf("\tMetronomo sorteou ");
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

void imprimeEstadosLog(Pokemon *p, FILE *f){
    int paralisado = getEstado(p, PARALISAR);
    int dormindo = getEstado(p, DORMIR);
    int queimando = getEstado(p, QUEIMAR);
    
    if(paralisado == 1 || queimando == 1 || dormindo == 1){
        fprintf(f,"(");
    }
    if(paralisado == 1){
        fprintf(f, "paralisado");
    }
    if(dormindo == 1){
        if(paralisado == 1){
            fprintf(f, ", ");
        }
        fprintf(f, "dormindo");
    }
    
    if(queimando == 1){
        if(dormindo == 1 || paralisado == 1){
            fprintf(f, ", ");
        }
        fprintf(f, "queimando");
    }

    if(paralisado == 1 || queimando == 1 || dormindo == 1){
        fprintf(f, ")");
    }
}





//// imprimir qual atk o metronomo sorteou
//// resolver problema do nome do jogador, ta imprimindo nome do pokemon quando vence
//// imprimir na captura de pokemon e na fuga se foi fracasso ou sucesso
//// ver se ainda falta getchar ou algo relacionado
//// fazer gameover
// fazer classificacao e ranking
//readme
// fazer lista encadeada de jogadores
// imprimir algo do tipo "voce esta na sua batalha x, partida y"
// argc e argv
// makefile
