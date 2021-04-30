#include "../include/pokemon.h"

struct pokemon{   
    char *nome;
    float hpMax;
    float hpAtual;
    float ataque;
    float defesa;
    int estados[QTDESTADOS];
    int tipo;
    int turnosSemJogar;
    
    //fptrAtaque ataques[3]; // Vetor para ponteiros de funções de ataque do pokemon
};

// Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int estado, int tipo, fptrAtaque atk1, fptrAtaque atk2, fptrAtaque atk3)
Pokemon* criaPokemon(char *nome, float hpMax, float ataque, float defesa, int tipo){
    Pokemon *p = (Pokemon*) malloc(sizeof(Pokemon));
    p->nome = strdup(nome);
    p->hpMax = hpMax;
    p->hpAtual = hpMax;
    p->ataque = ataque;
    p->defesa = defesa;
    p->tipo = tipo;
    p->turnosSemJogar = 0;
    
    for(int i = 0; i < QTDESTADOS; i++){
        if(i == NORMAL) 
            p->estados[NORMAL] = 1;
        else 
            p->estados[i] = 0;
    }  
    
    //p->ataques[0] = atk1;
    //p->ataques[1] = atk2;
    //p->ataques[2] = atk3;
    return p;
}

void imprimePokemon(Pokemon *p){
    printf("nome [%s]\n", p->nome);
    printf("hp max [%.2f]\n", p->hpMax);
    printf("hp Atual [%.2f]\n", p->hpAtual);
    printf("ataque [%.2f]\n", p->ataque);
    printf("defesa [%.2f]\n", p->defesa);
    printf("tipo [%d]\n\n", p->tipo);
    printf("turnos sem jogar [%d]\n", p->turnosSemJogar);
    for(int i = 0; i < QTDESTADOS; i++){
        printf("estado [%d]\n", p->estados[i]);
    }
}

Pokemon* setHPAtual(Pokemon* p, float hpAtual){
    p->hpAtual= hpAtual;
    return p;
}

Pokemon* setEstado(Pokemon *p, int posVetor, int valor){ //passar .h  filipe n gostou do nome
    p->estados[posVetor] = valor;
    return p;
}

Pokemon* setTurnosSemJogar(Pokemon *p, int turnosSemJogar){
    p->turnosSemJogar = turnosSemJogar;
    return p;
}

// Pokemon* setQueimando(Pokemon *p, int queimando){
//     p->queimando = queimando;
//     return p;
// }

float getHPAtual(Pokemon* p){
    return p->hpAtual;
}

float getAtaque(Pokemon *p){
    return p->ataque;
}

float getDefesa(Pokemon *p){
    return p->defesa;
}

// int getEstado(Pokemon *p){
//     return p->estado;
// }

int getTipo(Pokemon *p){
    return p->tipo;
}

void destroiPokemon(Pokemon *p){
    free(p->nome);
    free(p);
}

void ataque(char code, Pokemon *atacante, Pokemon *defensor){
    
}


