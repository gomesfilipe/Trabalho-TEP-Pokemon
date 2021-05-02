#include "../include/pokemon.h"

struct pokemon{   
    char *nome;
    float hpMax;
    float hpAtual;
    float ataque;
    float defesa;
    int estados[QTDESTADOS];
    int tipo;
    //int turnosSemJogar;
    int turnosNumEstado[QTDESTADOS];
    fptrAtaque ataques[QTDATAQUESPOKEMON]; // Vetor para ponteiros de funções de ataque do pokemon
};

struct listaPokemon{
    Pokemon *pokemon;
    struct listaPokemon *prox;
};

Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3){
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
    return p;
}

void imprimePokemon(Pokemon *p){
    printf("nome [%s]\n", p->nome);
    printf("hp max [%.2f]\n", p->hpMax);
    printf("hp Atual [%.2f]\n", p->hpAtual);
    //printf("ataque [%.2f]\n", p->ataque);
    //printf("defesa [%.2f]\n", p->defesa);
    //printf("tipo [%d]\n", p->tipo);
    
    printf("normal    [%d] turnos num estado [%d]\n", p->estados[NORMAL], p->turnosNumEstado[NORMAL]);
    printf("dormir    [%d] turnos num estado [%d]\n", p->estados[DORMIR], p->turnosNumEstado[DORMIR]);
    printf("queimar   [%d] turnos num estado [%d]\n", p->estados[QUEIMAR], p->turnosNumEstado[QUEIMAR]);
    printf("paralisar [%d] turnos num estado [%d]\n", p->estados[PARALISAR], p->turnosNumEstado[PARALISAR]);
    printf("protegido [%d] turnos num estado [%d]\n", p->estados[PROTEGIDO], p->turnosNumEstado[PROTEGIDO]);
    printf("esconder  [%d] turnos num estado [%d]\n", p->estados[ESCONDER], p->turnosNumEstado[ESCONDER]);
    printf("fullhp    [%d] turnos num estado [%d]\n", p->estados[FULLHP], p->turnosNumEstado[FULLHP]);

    // for(int i = 0; i < QTDESTADOS; i++){
    //     printf("estado [%d] turnos num estado [%d]\n", p->estados[i], p->turnosNumEstado[i]);
    // }

    //printf("ponteiro de funcao atk1 [%p]\n", p->ataques[0]);
    //printf("ponteiro de funcao atk2 [%p]\n", p->ataques[1]);
    //printf("ponteiro de funcao atk3 [%p]\n\n", p->ataques[2]);
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
    //if(turnosNumEstado > p->turnosNumEstado[posVetor]){
        p->turnosNumEstado[posVetor] = turnosNumEstado;
    //}
    
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

fptrAtaque getAtaquePokemon(Pokemon* p , int posVetor){
    fptrAtaque atk = p->ataques[posVetor];
    return atk;
}

void destroiPokemon(Pokemon *p){
    free(p->nome);
    free(p);
}

void ataque(int code, Pokemon *atacante, Pokemon *defensor){
    fptrAtaque ataque  =  atacante->ataques[code - 1];
    ataque(atacante, defensor);
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

void imprimeLista(Lista* inicio){
    Lista* aux;
    for(aux=inicio; aux != NULL; aux= aux->prox){
        imprimePokemon(aux->pokemon);
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


Lista* morrePokemon(Lista* inicio){
    inicio = removePrimeiroLista(inicio);
    return inicio;  
}

// int sorteiaCaptura(int C){

// }

Lista* capturaPokemon(Lista *inicio, Pokemon *p){ //testar
    p->hpAtual = p->hpMax;
    inicio = adicicionaFinalLista(inicio, p);
    return inicio;
}

Pokemon* recuperaHPEntreBatalhas(Pokemon *p){  //testar
    if(p->hpAtual += 10 > p->hpMax){
        p->hpAtual = p->hpMax;
    
    } else{
        p->hpAtual += 10;
    }

    return p;
}

float porcentagemDeVida(Pokemon *p){ //testar
    return p->hpAtual / p->hpMax * 100.0;
}

Pokemon* restauraHPAposDormir(Pokemon* p){  //testar
    float HPMax = getHPMaximo(p);
    p = setHPAtual(p, HPMax); 
    return p;
}