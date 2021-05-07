#include "../include/pokemon.h"

struct pokemon{   
    char *nome;      
    float hpMax;    
    float hpAtual; 
    float ataque;   
    float defesa;   
    int estados[QTDESTADOS];  
    int tipo;               
    int turnosNumEstado[QTDESTADOS];   
    fptrAtaque ataques[QTDATAQUESPOKEMON]; 
    char **nomeAtaques; 
};

struct listaPokemon{
    Pokemon *pokemon;
    struct listaPokemon *prox;
};

Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3, char *nomeAtk1, char *nomeAtk2, char *nomeAtk3){
    Pokemon *p = (Pokemon*) malloc(sizeof(Pokemon));
    p->nome = strdup(nome);
    p->hpMax = hpMax;
    p->hpAtual = hpMax;
    p->ataque = ataque;
    p->defesa = defesa;
    p->tipo = tipo;
    
    for(int i = 0; i < QTDESTADOS; i++){
        if(i == NORMAL){
            p->estados[i] = 1;
            p->turnosNumEstado[i] = 0;
        }else{ 
            p->estados[i] = 0; 
            p->turnosNumEstado[i] = 0;
        }
    }  
    
    p->ataques[0] = atk1;
    p->ataques[1] = atk2;
    p->ataques[2] = atk3;

    p->nomeAtaques = (char**) malloc(sizeof(char*) * QTDATAQUESPOKEMON);
    p->nomeAtaques[0] = strdup(nomeAtk1); 
    p->nomeAtaques[1] = strdup(nomeAtk2);
    p->nomeAtaques[2] = strdup(nomeAtk3);
    return p;
}

void imprimeNomePokemon(Pokemon *p, FILE* f){
    fprintf(f, "%s", p->nome);
}

void imprimeAtaquesPokemon(Pokemon *p){  
    for(int i = 0; i < QTDATAQUESPOKEMON; i++){   
        printf("\t%d- %s\n", i + 1, p->nomeAtaques[i]);
    }

}

Pokemon* setHPAtual(Pokemon* p, float hpAtual){
    p->hpAtual= hpAtual;
    return p;
}

Pokemon* setEstado(Pokemon *p, int posVetor, int valor){ 
    p->estados[posVetor] = valor;
    return p;
}

Pokemon* setTurnosNumEstado(Pokemon *p, int posVetor, int turnosNumEstado){
    p->turnosNumEstado[posVetor] = turnosNumEstado;
    return p;
}

float getHPAtual(Pokemon* p){
    return p->hpAtual;
}

float getHPMaximo(Pokemon* p){
    return p->hpMax;
}

float getAtaque(Pokemon *p){
    return p->ataque;
}

float getDefesa(Pokemon *p){
    return p->defesa;
}

int getEstado(Pokemon *p, int posVetor){
    return p->estados[posVetor];
}

int getTurnosNumEstado(Pokemon *p, int posVetor){
    return p->turnosNumEstado[posVetor];
}

int getTipo(Pokemon *p){
    return p->tipo;
}

Pokemon* getPrimeiroPokemon(Lista* lista){
    return lista->pokemon;
}

fptrAtaque getAtaquePokemon(Pokemon* p , int posVetor){
    fptrAtaque atk = p->ataques[posVetor];
    return atk;
}

void destroiPokemon(Pokemon *p){
    free(p->nome);
    free(p->nomeAtaques[0]);
    free(p->nomeAtaques[1]);
    free(p->nomeAtaques[2]);
    free(p->nomeAtaques);
    free(p);
}

void ataqueGenerico(int code, Pokemon *atacante, Pokemon *defensor, FILE *f){
    fptrAtaque ataque  =  atacante->ataques[code - 1];
    ataque(atacante, defensor, f);
}

Lista* criaLista(Pokemon *pokemon){
    Lista *inicio = (Lista*) malloc(sizeof(Lista));
    inicio->pokemon = pokemon;
    inicio->prox = NULL;
    return inicio;
}

Lista* adicicionaFinalLista(Lista *inicio, Pokemon* pokemon){
    Lista* aux;
    Lista* final = criaLista(pokemon);
    for(aux= inicio; aux->prox != NULL; aux= aux->prox){
        continue;
    }
    aux->prox = final;
    return inicio;
}

Lista* removePrimeiroLista(Lista *inicio){
    Lista* aux = inicio;
    inicio = inicio->prox;
    destroiPokemon(aux->pokemon);
    free(aux);
    return inicio;
}

Lista* removePokemonQualquerLista(Lista *inicio, int pos, int tamLista){
    Lista *centro = inicio;
    Lista *sucessor = centro->prox, *antecessor = NULL;
    int posAtual;
    for(posAtual = 1, centro = inicio; posAtual <= pos; posAtual++, centro = centro->prox, sucessor = sucessor->prox){
        if(posAtual == 1 && pos == 1){ // Caso seja o primeiro pokemon.
            sucessor = centro->prox;
            destroiPokemon(centro->pokemon);
            free(centro);
            return sucessor; // Novo início da lista.

        } else if(posAtual == tamLista && pos == tamLista){ // Caso seja o último pokemon.
            destroiPokemon(centro->pokemon);
            free(centro);
            antecessor->prox = NULL;
            return inicio; 
        
        } else if(posAtual == pos){ //Caso o pokemon se encontrar no meio da lista
            antecessor->prox = sucessor;
            destroiPokemon(centro->pokemon);
            free(centro);
            return inicio;  
        }

        antecessor = centro;
    }
}

Pokemon* getPokemonLista(Lista* inicio, int pos){
    Lista *aux;
    int posAtual;
    for(posAtual = 1, aux = inicio; posAtual <= pos; posAtual++, aux = aux->prox){
        if(posAtual == pos){
            return aux->pokemon;
        }
    }
}

void imprimeListaDePokemons(Lista* inicio){
    Lista* aux;
    int i = 1;
    for(aux=inicio; aux != NULL; aux= aux->prox){
        printf("\t%d- ", i);
        imprimeNomePokemon(aux->pokemon, stdout);
        printf("\n");
        i++;
    }
}

void destroiLista(Lista *inicio){
    Lista* aux = inicio;
    Lista* anterior;
   
    if(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        destroiPokemon(anterior->pokemon);
        free(anterior);
        destroiLista(aux);
    }
}

Pokemon* recuperaHPEntreBatalhas(Pokemon *p){  
    if(p->hpAtual + 10 > p->hpMax){
        p->hpAtual = p->hpMax;
    
    } else{
        p->hpAtual += 10;
    }

    return p;
}

float porcentagemDeVida(Pokemon *p){ 
    return p->hpAtual / p->hpMax * 100.0;
}

Pokemon* restauraHPAposDormir(Pokemon* p){  
    if(p->turnosNumEstado[FULLHP] == 1){
        float HPMax = getHPMaximo(p);
        p = setHPAtual(p, HPMax); 
        return p;
    }
}

int estaImune(Pokemon *defensor){
    if(defensor->estados[PROTEGIDO] == 1 || defensor->estados[ESCONDER] == 1){
        return 1;
    }
    return 0;
}

void imprimeAtaque(Pokemon* pokemon, int pos, FILE *f){
    fprintf(f,"%s\n", pokemon->nomeAtaques[pos - 1]);
}

char* getNomePokemon(Pokemon* pokemon){
    char* nome;
    nome = pokemon->nome;
    return nome; 
}

char* getNomeAtaque(Pokemon* pokemon, int posVetor){
    char* nomeAtaque = pokemon->nomeAtaques[posVetor];
    return nomeAtaque;
}

fptrAtaque getPonteiroAtaque(Pokemon *pokemon, int posVetor){
    return pokemon->ataques[posVetor];
}
