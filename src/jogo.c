#include "../include/jogo.h"

void iniciaTabelaCriacaoPokemons(){
    inicPokemons[BLASTOISE] = criaBlastoise;
    inicPokemons[CHARIZARD] = criaCharizard;
    inicPokemons[VENUSAUR] = criaVenusaur;
    inicPokemons[PIKACHU] = criaPikachu;
    inicPokemons[STEELIX] = criaSteelix;
    inicPokemons[MEW] = criaMew;
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

Pokemon* sorteiaPokemon(){ 
    float random = (float)rand()/(float)(RAND_MAX);
    if(random <= 1.0 / 128.0){ // Sorteando ou não o mew.
        Pokemon *mew = criaMew();
        return mew;
    
    } else{ // Se não for o mew, sorteia entre os pokemons restantes.
        int aleatorio = rand() % (QTDPOKEMONS - 1); // Escolhe um numero de 0 a 4, pois estamos excluindo o mew nesse caso.
        Pokemon *p = escolhePokemon(aleatorio);
        return p;
    }

}

fptrAtaque sorteiaAtaque(Pokemon *p, FILE* f){ 
    int aleatorio = rand() % QTDATAQUESPOKEMON; // Escolhe um numero de 0 a 2.
    fptrAtaque atk = getAtaquePokemon(p , aleatorio); // Vetor de ataques na posicao aleatoria.
    fprintf(f, "\t"); // Imprimindo no log de batalhas.
    imprimeNomePokemon(p, f);
    fprintf(f," usa ");
    imprimeAtaque(p, aleatorio + 1, f);
    
    printf("\t"); // Imprimindo no terminal.
    imprimeNomePokemon(p, stdout);
    fprintf(stdout," usa ");
    imprimeAtaque(p, aleatorio + 1, stdout);
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

    if(estado[DORMIR] == 0 && estado[PARALISAR]== 0 && estado[ESCONDER] == 0){
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

int jogadorAtaca(Pokemon* defensor, int escolheAtaque, Jogador* jogador, FILE *f){
    Pokemon* atacante = getPrimeiroPokemonDoJogador(jogador);
    
    if(escolheAtaque == 1 || escolheAtaque == 2 || escolheAtaque == 3){
        fptrAtaque atk = getAtaquePokemon(atacante, escolheAtaque - 1);
        atk(atacante, defensor, f);

        float hpAtacante = getHPAtual(atacante);
        float hpDefensor = getHPAtual(defensor);
        
        if(hpAtacante <= 0 && hpDefensor <= 0){ // Os dois morreram.
            int qtdPokemons = getQtdPokemons(jogador);
            qtdPokemons--;
            jogador = setQtdPokemons(jogador, qtdPokemons);
            
            if(qtdPokemons > 0){ // Ainda não é o último pokemon.
                int qtdVitorias = getQtdVitorias(jogador);
                qtdVitorias++;
                jogador = setQtdVitorias(jogador, qtdVitorias);
                return ATKMATOUMORREU;
            
            } else if(qtdPokemons == 0){ // Chegou no último pokemon.
                return GAMEOVER;
            }
        } else if(hpDefensor <= 0){ // Pokemon do computador morreu.
            int qtdVitorias = getQtdVitorias(jogador);
            qtdVitorias++;
            jogador = setQtdVitorias(jogador, qtdVitorias);
            return ATKMATOU;
        
        } else if(hpAtacante <= 0){ // Pokemon do jogador morreu.
            int qtdPokemons = getQtdPokemons(jogador);
            qtdPokemons--;
            jogador = setQtdPokemons(jogador, qtdPokemons);
            
                if(qtdPokemons > 0){ // Ainda não é o último pokemon.
                    return ATKMORREU;
                
                } else if(qtdPokemons == 0){ // Chegou no último pokemon.
                    return GAMEOVER;
                }
        } else{ // Ninguém morreu.
            return ATKNORMAL;
        }

    }else if(escolheAtaque == 4){ // Tentativa de capturar pokemon adversário.
        int qtdPokebolas = getQtdPokebolas(jogador);
        qtdPokebolas--;
        jogador = setQtdPokebolas(jogador, qtdPokebolas);

        if(vaiCapturarPokemonOuNao(defensor) == 1 ){
            jogador = capturaPokemon(jogador, defensor);
            int qtdPokemons = getQtdPokemons(jogador);
            qtdPokemons++;
            jogador = setQtdPokemons(jogador, qtdPokemons);
            return CAPTUROU;     
        }
        else{
            return NAOCAPTUROU;
        }   
    }else if(escolheAtaque == 5){ // Tentativa de fuga.
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
    //turnosNumEstado[ESCONDER] = getTurnosNumEstado(p, ESCONDER);
    turnosNumEstado[FULLHP] = getTurnosNumEstado(p, FULLHP);

    // Decrementando eles pois passou um turno.
    if(turnosNumEstado[DORMIR] > 0) turnosNumEstado[DORMIR]--;
    if(turnosNumEstado[PARALISAR] > 0) turnosNumEstado[PARALISAR]--;
    if(turnosNumEstado[PROTEGIDO] > 0) turnosNumEstado[PROTEGIDO]--;
    //if(turnosNumEstado[ESCONDER] > 0) turnosNumEstado[ESCONDER]--;
    
    if(turnosNumEstado[FULLHP] > 0){
        turnosNumEstado[FULLHP]--;
        if(turnosNumEstado[FULLHP] == 0){
            p = restauraHPAposDormir(p);
        }
    }

    // Pegando todos os estados de um pokemon. 
    estados[DORMIR] = getEstado(p, DORMIR);
    estados[PARALISAR] = getEstado(p, PARALISAR);
    estados[PROTEGIDO] = getEstado(p, PROTEGIDO);
    estados[FULLHP] = getEstado(p, FULLHP);

    // Se o contador de turnos num estado cair pra 0, esse determinado estado acabou.
    if(turnosNumEstado[DORMIR] == 0) estados[DORMIR] = 0;
    if(turnosNumEstado[PARALISAR] == 0) estados[PARALISAR] = 0;
    if(turnosNumEstado[PROTEGIDO] == 0) estados[PROTEGIDO] = 0;
    if(turnosNumEstado[FULLHP] == 0) estados[FULLHP] = 0;

    // Setando novos valores de turnos num estado.
    p = setTurnosNumEstado(p, DORMIR, turnosNumEstado[DORMIR]);
    p = setTurnosNumEstado(p, PARALISAR, turnosNumEstado[PARALISAR]);
    p = setTurnosNumEstado(p, PROTEGIDO, turnosNumEstado[PROTEGIDO]);
    p = setTurnosNumEstado(p, FULLHP, turnosNumEstado[FULLHP]);
    
    // Setando novos valores dos estados do pokemon.
    p = setEstado(p, DORMIR, estados[DORMIR]);
    p = setEstado(p, PARALISAR, estados[PARALISAR]);
    p = setEstado(p, PROTEGIDO, estados[PROTEGIDO]);
    p = setEstado(p, FULLHP, estados[FULLHP]);
}

int computadorAtaca(Pokemon *atacante, Jogador *jogador, FILE* f){
    fptrAtaque atk = sorteiaAtaque(atacante, f);
    Pokemon *defensor = getPrimeiroPokemonDoJogador(jogador);

    atk(atacante, defensor, f);
    
    float hpAtacante = getHPAtual(atacante); 
    float hpDefensor = getHPAtual(defensor);
    
    if(hpAtacante <= 0 && hpDefensor <= 0){ // Os dois morreram.
        int qtdPokemons = getQtdPokemons(jogador);
        qtdPokemons--;
        jogador = setQtdPokemons(jogador, qtdPokemons);
        
        if(qtdPokemons > 0){
            int qtdVitorias = getQtdVitorias(jogador);
            qtdVitorias++;
            jogador = setQtdVitorias(jogador, qtdVitorias);
            return ATKMATOUMORREU; 
        
        } else if(qtdPokemons == 0){
            return GAMEOVER;
        }
         
    } else if(hpDefensor <= 0){ // Pokemon do jogador morreu.
        int qtdPokemons = getQtdPokemons(jogador);
        qtdPokemons--;
        jogador = setQtdPokemons(jogador, qtdPokemons);
    
        if(qtdPokemons <= 0){
            return GAMEOVER;
        }

        return ATKMATOU;
    
    } else if(hpAtacante <= 0){ // Pokemon do computador morreu.
        int qtdVitorias = getQtdVitorias(jogador);
        qtdVitorias++;
        jogador = setQtdVitorias(jogador, qtdVitorias);
        return ATKMORREU;
    
    } else{ // Ninguém morreu.
        return ATKNORMAL;
    }
}

int fogeOuNao(){
    int aleatorio = rand() % 16;
    if(aleatorio == 1){ // Número arbitrário para fazer a comparação. Nesse caso, a probabilidade de sortear 1 é 1/16, que é a probabilidade desejada.
        return 1;
    }
    return 0;
}  

void gameOver(Lista* listaPC, FILE *f, listaJog *listaComJogadores, FILE *placar){
    destroiLista(listaPC);
    menuInicial(listaComJogadores, placar, f);//f será o arquivo de log de batalhas
}

Lista* criaListaPokemonsTela(){
    Lista* lista;
    Pokemon *p = escolhePokemon(PIKACHU);
    Pokemon *c = escolhePokemon(CHARIZARD);
    Pokemon *v = escolhePokemon(VENUSAUR);
    Pokemon *b = escolhePokemon(BLASTOISE);
    Pokemon *s = escolhePokemon(STEELIX);
    Pokemon *m = escolhePokemon(MEW);
    
    lista = criaLista(p);
    lista = adicicionaFinalLista(lista, c);
    lista = adicicionaFinalLista(lista, v);
    lista = adicicionaFinalLista(lista, b);
    lista = adicicionaFinalLista(lista, s);
    lista = adicicionaFinalLista(lista, m);

    return lista;
}
