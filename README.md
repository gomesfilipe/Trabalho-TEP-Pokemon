# 1. Dupla
Aluna: Elaine Dias Pires
Matrícula: 2020101903

Aluno: Filipe Gomes Arante de Souza
Matrícula: 2020100625

# 2. Organização do trabalho

## 2.1 TADs criadas

Para facilitar o desenvolvimento do trabalho, e ter uma boa estrutura para programar, criamos as seguintes TADs:

### 2.1.1 TAD Pokemon
Nessa TAD foram implementadas as operações que podem ser feitas num pokemon e numa lista encadeada simples de pokemons. Por exemplo, fizemos a criação de pokemons, funções dos tipos get e set para poder manipular os pokemons em outros arquivos, função de ataque genérica de um pokemon, liberar um pokemon ou uma lista simples de pokemons da memória, dentre outras.

### 2.1.2 TAD Jogador
Nessa TAD foram implementadas as operações que podem ser feitas num jogador, bem como numa lista encadeada com sentinela de jogadores. Por exemplo, fizemos a criação de um jogador, a criação de uma lista vazia de jogadores, adicionar jogador ao final da lista, funções do tipo get e set para manipular os jogadores em arquivos, dentre outros.

## 2.2 Bibliotecas criadas
Também criamos as seguintes bibliotecas a fim de organizar melhor o trabalho:

### 2.2.1 Biblioteca Jogo
Nessa biblioteca, foram implementadas, as funções referentes ao jogo, por exemplo, as funções responsáveis pelo ataque do computador e pelo ataque do usuário.

### 2.2.2 Biblioteca Telas
Nessa biblioteca, fizemos todas as funções referentes a mensagens que deveriam ser impressas na tela e nos arquivos log de batalhas e de pontuações dos jogadores, bem como a interação do usuário com o programa. 

### 2.2.3 Bibliotecas Utils
Nessa biblioteca fizemos funções auxiliares que seriam úteis ao decorrer do trabalho, mas não se encaixavam em nenhuma TAD ou biblioteca.

### 2.2.4   Bibliotecas Blastoise, Charizard, Mew, Pikachu, Steelix e Venusaur
Nessa biblioteca implementamos os personagens do jogo. Foram feitas funções que efetuavam seus ataques e também que criavam cada um desses pokemons, seja para adicionar na lista de pokemons do jogador ou na lista de pokemons do computador.

# 3. Considerações importantes

## 3.1 Listas encadeadas
Nesse trabalho, haviam algumas situações que suas quantidades não eram bem definidas. Para isso, criamos as seguintes listas encadeadas:

### 3.1.1 Lista de pokemons do computador 
Como o número de batalhas numa partida não é conhecido, a criação de uma lista encadeada simples para os pokemons do computador trouxe muita praticidade para a implementação de uma batalha. A medida que o jogador vai vencendo batalhas, são adicionados novos pokemons na lista em questão. Seu objetivo era facilitar a liberação da memória dos pokemons do jogador após o final de uma partida.

### 3.1.2 Lista de pokemons do jogador
A quantidade de pokemons do jogador no início de uma partida, apesar de inicialmente ser conhecida (3 pokemons), pode aumentar ao decorrer do jogo.  Assim, não é possível saber quantos pokemons o jogador pode ter, pois ele pode capturar pokemons indefinidamente ao longo da execução do jogo. Dessa forma, criamos uma lista de pokemons para o jogador. Nessa lista, os pokemons capturados 
são adicionados no final da lista e cada vez que um pokemon perde uma batalha, ele é liberado da memória.

### 3.1.3 Lista de pokemons do jogo 
No menu inicial, quando o usuário digita a opção de jogar, uma lista de pokemons é mostrada na tela. A cada vez que o usuário escolhe um pokemon, aparece outra lista já ordenada e sem o pokemon que o usuário escolheu anteoriormente. Inicialmente, pensamos em utilizar um vetor e quando o usuário escolhesse o pokemon, o mesmo seria retirado do vetor e faríamos um shift left. Contudo, a medida que assitíamos as aulas síncronas da disciplina, percebemos que utilizar uma lista encadeada era a melhor solução, pois, quando se remove uma célula, a lista já se ordena automaticamente.

### 3.1.4 Lista encadeada com sentinela de jogadores
Assim como nas listas descritas anteriormente, o número de partidas jogadas durante uma execução é desconhecido. Portanto, para trabalhar com a questão do placar do jogo, surgiu a necessidade dessa lista. Implementamos ela com um ponteiro para a primeira e para a última célula dessa estrutura, além de um campo que possuia seu tamanho. A partir dela, conseguimos fazer a ordenação do placar e também fazer a liberação da memória dos jogadores de modo mais prático.

## 3.2 Callbacks
Nesse trabalho utilizamos callbacks para resolver os seguintes problemas:

### 3.2.1 Criação de um pokemon
Como existiam vários pokemons implementados, era necessário a criação de uma função que criasse um pokemon genérico. Portanto, criamos ponteiros para cada função de criação de um pokemon específico e as juntamos para desenvolver a função citada, cujo parâmetro era unicamente o código de cada personagem. 

### 3.2.2 Ataque de um pokemon
Cada pokemon possui três ataques, dessa forma, fizemos uma função para cada um e quando o jogador escolhia ou o computador sorteava um ataque, utilizamos tabela de dispersão para capturar a função de ataque correta a ser chamada. Esse callback tambem foi muito útil na implementação do movimento **"metronomo"** do Mew, pois ele simplesmente sorteava um desses ponteiros para executar esse ataque e os pegava numa outra tabela de dispersão.

## 3.3 Arquivos de saída
Direcionamos os arquivos gerados do log de batalhas e do placar de jogadores para uma pasta já existente chamada **"arquivos_de_saida". Como utilizamos o modo "w" para escrever no arquivo, a cada execução do programa os dados são sobrescritos sobre os da execução anterior.


# 4 Makefile
Para utilizar esse makefile, basta digitar o comando **make** no terminal, que o programa será compliado e comando **make run** que irá executar o programa.
Inserimos como semente dos números aleatórios o número 40. Para mudar essa semente, é preciso alterar o makefile na linha 54.

