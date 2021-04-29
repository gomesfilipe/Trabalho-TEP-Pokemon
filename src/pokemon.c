#include "../include/pokemon.h"

struct pokemon{
    char *nome;
    float hpMax;
    float hpAtual;
    float ataque;
    float defesa;
    int estado;
    int tipo;
};

Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo){
    Pokemon *p = (Pokemon*) malloc(sizeof(Pokemon));
    p->nome = strdup(nome);
    p->hpMax = hpMax;
    p->hpAtual = hpMax;
    p->ataque = ataque;
    p->defesa = defesa;
    p->tipo = tipo;
    return p;
}

//TODO FAZER FUNÇÕES SET

void imprimePokemon(Pokemon *p){
    printf("nome [%s]\n", p->nome);
    printf("hp max [%.2f]\n", p->hpMax);
    printf("hp Atual [%.2f]\n", p->hpAtual);
    printf("ataque [%.2f]\n", p->ataque);
    printf("defesa [%.2f]\n", p->defesa);
    printf("estado [%d]\n", p->estado);
    printf("tipo [%d]\n\n", p->tipo);
}



