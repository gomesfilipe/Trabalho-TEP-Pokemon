#include "../include/jogador.h"

struct jogador{
    char* nome;
    int qtdPokemons;
    int qtdPokebolas;
    int qtdVitorias;
    Lista *pokemons; //vetor de pokemons // usar lista encadeada nessa parte
};

struct celulajogador{
    Jogador *jogador;
    struct celulajogador *prox;   
};

struct listaJogadores{
    struct celulajogador *primeiro; 
    struct celulajogador *ultimo;  
    int tamanho;
};

Jogador* criaJogador(char *nome, Lista *pokemons){
    Jogador *jogador = (Jogador*) malloc(sizeof(Jogador));
    jogador->nome = strdup(nome);
    jogador->qtdPokemons = QTDPOKEMONSINICIAIS;
    jogador->qtdPokebolas = QTDPOKEBOLASINICIAIS;
    jogador->qtdVitorias = 0;
    jogador->pokemons = pokemons;
}

void destroiJogador(Jogador* jogador){
    free(jogador->nome);
    destroiLista(jogador->pokemons);
    free(jogador);
}

void imprimeJogador(Jogador *jogador){
    printf("nome [%s]\n", jogador->nome);
    printf("qtdPokemons [%d]\n", jogador->qtdPokemons);
    printf("qtdPokebolas [%d]\n", jogador->qtdPokebolas);
    printf("qtdVitorias [%d]\n", jogador->qtdVitorias);
    imprimeListaDePokemons(jogador->pokemons);
}

Jogador* capturaPokebola(Jogador *jogador, int C){  //ver se ta certa, testar
    float probabilidade = C/12.0;
    float aleatorio = (float)rand()/(float)(RAND_MAX);

    if(aleatorio <= probabilidade){
        jogador->qtdPokebolas++;
    }

    return jogador;
}

int getQtdPokebolas(Jogador* jogador){
    return jogador->qtdPokebolas;
}

int getQtdPokemons(Jogador* jogador){
    return jogador->qtdPokemons;
}

int getQtdVitorias(Jogador* jogador){
    return jogador->qtdVitorias;
}

char* getNomeJogador(Jogador* jogador){
    return jogador->nome;
}

Jogador* setQtdPokebolas(Jogador* jogador , int qtdPokebolas){
    jogador->qtdPokebolas = qtdPokebolas;
}

Jogador* setQtdPokemons(Jogador* jogador , int qtdPokemons){
    jogador->qtdPokemons = qtdPokemons;
}

Jogador* setQtdVitorias(Jogador* jogador , int qtdVitorias){
    jogador->qtdVitorias = qtdVitorias;
}

Lista* getListaPokemons(Jogador* jogador){
    return jogador->pokemons;
}

Pokemon* getPrimeiroPokemonDoJogador(Jogador *jogador){
    Pokemon* p = getPrimeiroPokemon(jogador->pokemons);
    return p;
}

Jogador* setListaPokemons(Jogador *jogador, Lista *listaPokemons){
    jogador->pokemons = listaPokemons;
    return jogador;
}

Jogador* morrePokemon(Jogador* jogador){ 
    jogador->pokemons = removePrimeiroLista(jogador->pokemons);
    return jogador;
}

Jogador* capturaPokemon(Jogador* jogador, Pokemon *p){ 
    //float hpMax = getHPMaximo(p);
    //p = setHPAtual(p, hpMax); //Quando captura um pokemon, seu HpAtual esta no máximo
    char *nomePokemon = getNomePokemon(p);
    float hpMax = getHPMaximo(p);
    float ataque = getAtaque(p);
    float defesa = getDefesa(p);
    float tipo = getTipo(p);
    fptrAtaque atk1 = getPonteiroAtaque(p, 0);
    fptrAtaque atk2 = getPonteiroAtaque(p, 1);
    fptrAtaque atk3 = getPonteiroAtaque(p, 2);
    char *nomeAtk1 = getNomeAtaque(p, 0);
    char *nomeAtk2 = getNomeAtaque(p, 1);
    char *nomeAtk3 = getNomeAtaque(p, 2);

    Pokemon* aux = criaPokemon(nomePokemon, hpMax, ataque, defesa, tipo, atk1, atk2, atk3, nomeAtk1, nomeAtk2, nomeAtk3);
    jogador->pokemons = adicicionaFinalLista(jogador->pokemons , aux);
    return jogador;
}

int listaVazia(listaJog *lista){
    if(lista->primeiro == NULL && lista->ultimo == NULL){
        return 1;
    }
    return 0;
}

listaJog* criaListaJogadores(){
    listaJog *lista = (listaJog*) malloc(sizeof(listaJog));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

listaJog* adicionaJogadorNaLista(listaJog* lista,  Jogador* jogador){
    celulaJogador *novo = (celulaJogador*) malloc (sizeof(celulaJogador));
    novo->jogador = jogador;
    novo->prox = NULL;

    if(listaVazia(lista)) {
        lista->primeiro = novo;
        lista->ultimo = novo;
    } else {
        lista->ultimo->prox = novo;
    }

    lista->tamanho++;

    return lista;
}

void destroiListaJogadores(listaJog *lista){
    celulaJogador *aux = lista->primeiro;
    celulaJogador *anterior;
   
    while(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        destroiJogador(anterior->jogador);
        free(anterior);
    }

    free(lista);
}

int getTamanhoListaJogadores(listaJog *lista){
    return lista->tamanho;
}

void ordenaListaJogadores(listaJog *lista){
    celulaJogador *i, *j;
    celulaJogador *aux;
    for(i = lista->primeiro; i != NULL;  i=  i->prox){
        for(j = i->prox; j != NULL   ; j = j->prox){
            if(i->jogador->qtdVitorias < j->jogador->qtdVitorias){
                aux = i;
                i->jogador = j->jogador;
                j->jogador = aux->jogador;
            }
        }
    }
}

void imprimeListaJogadores(listaJog *lista, FILE *f){ // Imprime no arquivo de pontuações.
    celulaJogador *aux;
    for(aux = lista->primeiro; aux != NULL; aux = aux->prox){
        fprintf(f, "%s %d\n", aux->jogador->nome, aux->jogador->qtdVitorias);
    }
}

void imprimeListaJogadoresTerminal(listaJog *lista){
    celulaJogador *aux;
    int i;
    if(listaVazia(lista)){
        printf("\tNenhuma partida foi jogada ainda!\n");

    } else{
        for(i = 1, aux = lista->primeiro; aux != NULL; i++, aux = aux->prox){
            printf("\t%d- %s: %d\n", i, aux->jogador->nome, aux->jogador->qtdVitorias);
        }
    }
    
}