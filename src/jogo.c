#include "../include/jogo.h"

void iniciaTabelaCriacaoPokemons(){
    inicPokemons[BLASTOISE] = criaBlastoise;
    inicPokemons[CHARIZARD] = criaCharizard;
    inicPokemons[MEW] = criaMew;
    inicPokemons[PIKACHU] = criaPikachu;
    inicPokemons[STEELIX] = criaSteelix;
    inicPokemons[VENUSAUR] = criaVenusaur;
}

Pokemon* escolhePokemon(int code){
    fptrInic pokemonEscolhido = inicPokemons[code];
    return pokemonEscolhido();
}

void inicializaMatrizRelacaoTipos(float m[QTDTIPOS][QTDTIPOS]){
    m[ELETRICO][ELETRICO] = 0.5; 
    m[ELETRICO][FOGO]     = 1.0; 
    m[ELETRICO][AGUA]     = 2.0; 
    m[ELETRICO][PLANTA]   = 0.5; 
    m[ELETRICO][METAL]    = 1.0; 
    m[ELETRICO][PSIQUICO] = 1.0;
    
    m[FOGO][ELETRICO]  = 1.0; 
    m[FOGO][FOGO]      = 0.5; 
    m[FOGO][AGUA]      = 0.5; 
    m[FOGO][PLANTA]    = 2.0; 
    m[FOGO][METAL]     = 2.0; 
    m[FOGO][PSIQUICO]  = 1.0;
    
    m[AGUA][ELETRICO]  = 1.0; 
    m[AGUA][FOGO]      = 2.0; 
    m[AGUA][AGUA]      = 0.5; 
    m[AGUA][PLANTA]    = 0.5; 
    m[AGUA][METAL]     = 1.0; 
    m[AGUA][PSIQUICO]  = 1.0;
    
    m[PLANTA][ELETRICO] = 1.0; 
    m[PLANTA][FOGO]     = 0.5; 
    m[PLANTA][AGUA]     = 2.0; 
    m[PLANTA][PLANTA]   = 0.5 ; 
    m[PLANTA][METAL]    = 0.5; 
    m[PLANTA][PSIQUICO] = 1.0;
    
    m[METAL][ELETRICO] = 0.5; 
    m[METAL][FOGO]     = 0.5; 
    m[METAL][AGUA]     = 0.5; 
    m[METAL][PLANTA]   = 1.0; 
    m[METAL][METAL]    = 0.5; 
    m[METAL][PSIQUICO] = 1.0;
    
    m[PSIQUICO][ELETRICO] = 1.0; 
    m[PSIQUICO][FOGO]     = 1.0; 
    m[PSIQUICO][AGUA]     = 1.0; 
    m[PSIQUICO][PLANTA]   = 1.0; 
    m[PSIQUICO][METAL]    = 0.5; 
    m[PSIQUICO][PSIQUICO] = 0.5;
}

float calculaDano(float A, float D, float poder, float critico, float MT, float relacaoTipo){
    float modificador = critico * MT * relacaoTipo;
    return ((14.0 * poder * A / D) / 50.0 + 2.0) * modificador;
}

//batalha
//// funcao sorteia ataque (para o computador)
// funcao que controla o contador de turnosSemJogar e controle os  queimando
//// funcao que restaura 100% do HP do ataque dormirestados quando volta ao normal
//// funcao que aplica o dano de queimar depois de todo turno, caso esteja

//// funcao de ganhar pokebola, tem probabilidade nisso
//// funcao de capturar pokemon (acrescenta um pokemon na lista)
// funcao de fugir
//// funcao que tira pokemon da lista de jogador do jogador quando morre 
//// funcao que calcula porcentagem do hp atual em relacao ao hp maximo
//// sortear proximo pokemon a ser enfrentado
//// funcao de recuperar hp do pokemon entre batalhas

// funcoes de imprimir os menus
// implementar botoes como string e usar atoi quando conveniente

Pokemon* sorteiaPokemon(){ 
    int aleatorio = rand() % QTDPOKEMONS; // Escolhe um numero de 0 a 5.
    Pokemon *p = escolhePokemon(aleatorio);
    return p;
}

fptrAtaque sorteiaAtaque(Pokemon *p){ 
     int aleatorio = rand() % QTDATAQUESPOKEMON; // Escolhe um numero de 0 a 2.
     fptrAtaque atk = getAtaquePokemon(p , aleatorio);//vetor de ataques na posicao aleatoria
     return atk;
}

Pokemon* sofreQueimar(Pokemon *p){  
    int queimando = getEstado(p, QUEIMAR);
    if(queimando == 1){
        float hpMax = getHPMaximo(p);
        float dano = hpMax / 16.0;
        float hpAtual = getHPAtual(p);
        p = setHPAtual(p, hpAtual - dano);
    }

    return p;
}

int podeJogar(Pokemon *atacante){  
    int estado[QTDESTADOS]; 
    estado[DORMIR] = getEstado(atacante, DORMIR);
    estado[PARALISAR] = getEstado(atacante, PARALISAR);
    estado[ESCONDER] = getEstado(atacante, ESCONDER);
    estado[FULLHP] = getEstado(atacante, FULLHP);
    estado[PROTEGIDO] = getEstado(atacante, PROTEGIDO);

    if(estado[DORMIR] == 0 && estado[PARALISAR]== 0 && estado[ESCONDER] == 0 && estado[FULLHP]== 0 && estado[PROTEGIDO]==0){
        return 1;
    }

    return 0;
}

int vaiCapturarPokemonOuNao(Pokemon *p){  
    float hpMax = getHPMaximo(p);
    float hpAtual = getHPAtual(p); 
    
    float probabilidade = (hpMax / hpAtual) / 20.0;
    float aleatorio = (float)rand()/(float)(RAND_MAX);

    if(aleatorio <= probabilidade) {
        return 1;
    } else {
        return 0;
    }
}

 int jogadorAtaca(Pokemon* defensor, int escolheAtaque, Jogador* jogador){
    Pokemon* atacante = getPrimeiroPokemonDoJogador(jogador); //! ficar atento aqui

    if(escolheAtaque == 1 || escolheAtaque == 2 || escolheAtaque == 3){
        fptrAtaque atk = getAtaquePokemon(atacante, escolheAtaque - 1);
        atk(atacante, defensor);

        float hpAtacante = getHPAtual(atacante);
        float hpDefensor = getHPAtual(defensor);
        
        if(hpAtacante <= 0 && hpDefensor <= 0){
            jogador = morrePokemon(jogador);
            int qtdVitorias = getQtdVitorias(jogador);
            qtdVitorias--;
            jogador = setQtdVitorias(jogador, qtdVitorias);
            return ATKMATOUMORREU; 
        
        } else if(hpDefensor <= 0){
            int qtdVitorias = getQtdVitorias(jogador);
            qtdVitorias--;
            jogador = setQtdVitorias(jogador, qtdVitorias);
            return ATKMATOU;
        
        } else if(hpAtacante <= 0){
            jogador = morrePokemon(jogador);
            return ATKMORREU;
        
        } else{
            return ATKNORMAL;
        }

    }else if(escolheAtaque == 4){
        int qtdPokebolas = getQtdPokebolas(jogador);
        qtdPokebolas--;
        jogador = setQtdPokebolas(jogador, qtdPokebolas);
        
        if(vaiCapturarPokemonOuNao(defensor) == 1){
            jogador = capturaPokemon(jogador, defensor);
            int qtdPokemons = getQtdPokemons(jogador);
            qtdPokemons++;
            jogador = setQtdPokemons(jogador, qtdPokemons);
            return CAPTUROU;     
        }
        else{
            return NAOCAPTUROU;
        }   
    }else if(escolheAtaque == 5){
        if(fogeOuNao() == 1){
            return FUGIU;
        
        } else{
            return NAOFUGIU;
        }
    }
}   
    
void transicaoEntreTurnos(Pokemon *p){ 
    int estados[QTDESTADOS];
    int turnosNumEstado[QTDESTADOS];
    
    // Pegando os valores de turnos num estado.
    turnosNumEstado[DORMIR] = getTurnosNumEstado(p, DORMIR);
    turnosNumEstado[PARALISAR] = getTurnosNumEstado(p, PARALISAR);
    turnosNumEstado[PROTEGIDO] = getTurnosNumEstado(p, PROTEGIDO);
    turnosNumEstado[ESCONDER] = getTurnosNumEstado(p, ESCONDER);
    turnosNumEstado[FULLHP] = getTurnosNumEstado(p, FULLHP);

    // Decrementando eles pois passou um turno.
    if(turnosNumEstado[DORMIR] > 0) turnosNumEstado[DORMIR]--;
    if(turnosNumEstado[PARALISAR] > 0) turnosNumEstado[PARALISAR]--;
    if(turnosNumEstado[PROTEGIDO] > 0) turnosNumEstado[PROTEGIDO]--;
    if(turnosNumEstado[ESCONDER] > 0) turnosNumEstado[ESCONDER]--;
    if(turnosNumEstado[FULLHP] > 0) turnosNumEstado[FULLHP]--;

    // Pegando todos os estados de um pokemon. 
    estados[DORMIR] = getEstado(p, DORMIR);
    estados[PARALISAR] = getEstado(p, PARALISAR);
    estados[PROTEGIDO] = getEstado(p, PROTEGIDO);
    estados[ESCONDER] = getEstado(p, ESCONDER);
    estados[FULLHP] = getEstado(p, FULLHP);

    // Se o contador de turnos num estado cair pra 0, esse determinado estado acabou.
    if(turnosNumEstado[DORMIR] == 0) estados[DORMIR] = 0;
    if(turnosNumEstado[PARALISAR] == 0) estados[PARALISAR] = 0;
    if(turnosNumEstado[PROTEGIDO] == 0) estados[PROTEGIDO] = 0;
    if(turnosNumEstado[ESCONDER] == 0) estados[ESCONDER] = 0;
    if(turnosNumEstado[FULLHP] == 0) estados[FULLHP] = 0;

    // Setando novos valores de turnos num estado.
    p = setTurnosNumEstado(p, DORMIR, turnosNumEstado[DORMIR]);
    p = setTurnosNumEstado(p, PARALISAR, turnosNumEstado[PARALISAR]);
    p = setTurnosNumEstado(p, PROTEGIDO, turnosNumEstado[PROTEGIDO]);
    p = setTurnosNumEstado(p, ESCONDER, turnosNumEstado[ESCONDER]);
    p = setTurnosNumEstado(p, FULLHP, turnosNumEstado[FULLHP]);
    
    // Setando novos valores dos estados do pokemon.
    p = setEstado(p, DORMIR, estados[DORMIR]);
    p = setEstado(p, PARALISAR, estados[PARALISAR]);
    p = setEstado(p, PROTEGIDO, estados[PROTEGIDO]);
    p = setEstado(p, ESCONDER, estados[ESCONDER]);
    p = setEstado(p, FULLHP, estados[FULLHP]);

    int k = getTurnosNumEstado(p, DORMIR);
    //printf("aqui!!! [%d]", k); 
}

// FUNCAO DE JOGADOR ATACA
// tem que ver os estados que o pokemon esta
/**
 * normal, pode jogar
 * dormir e turnos sem jogar != 0, nao pode jogar
 * queimar pode jogar
 * paralisar e turnos sem jogar != 0, nao pode jogar
 * protegido pode jogar
 * esconder nao pode jogar
 * fullhp e turnos sem jogar = 0, hp vai pra 100%
 **/
//so pode tentar capturar o oponente se tiver pokebola e tbm fazer coisa da probabiblidade


//enum estados {NORMAL = 0, DORMIR, QUEIMAR, PARALISAR, PROTEGIDO, ESCONDER, FULLHP};

//no final chamar a função de capturar de capurar pokebola

//OBS: nao fazer o controle de turnosNumEstado para o steelix, ja fizemos na funcao.

// void computadorAtaca(Pokemon *atacante, Pokemon *defensor){
//     if(podeJogar(atacante)){
//         fptrAtaque atk = sorteiaAtaque(atacante);
//         atk(atacante, defensor);
    
//     } else{ // Se não pode atacar

//     }
// }


//int aleatorio = rand();  //sorteio entre 0 e RAND_MAX
//int aleatorio = rand()% 10 ;  //sorteio entre 0 e 9
//float aleatorio = (float)rand()/(float)(RAND_MAX); //calcula a probabilidade de sortear um  numero entre 0 e RAND_MAX

int fogeOuNao(){
    int aleatorio = rand() % 16;
    if(aleatorio == 1){ //Número arbitrário para fazer a comparação. Nesse caso, a probabilidade de sortear 1 é 1/16, que é a probabilidade desejada.
        return 1;
    }
    return 0;
}
