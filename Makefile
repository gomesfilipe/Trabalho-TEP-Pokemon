# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS=-lm\
             -W\
         -Wall\
         -pedantic\
                  -g\
                 -O2\


DEPS= include/blastoise.h\
		include/charizard.h\
		include/mew.h\
		include/pikachu.h\
		include/steelix.h\
		include/venusaur.h\
        include/jogador.h\
		include/jogo.h\
		include/pokemon.h\
        include/telas.h\
        include/utils.h\
          
        

OBJ= blastoise.o\
		charizard.o\
		mew.o\
		pikachu.o\
		steelix.o\
		venusaur.o\
        jogador.o\
		jogo.o\
		pokemon.o\
        telas.o\
        utils.o\

EXEC:= tp2

#
# Compilation and linking
#


main: client/main.c $(OBJ)
	$(CC) -o ${EXEC} $^ $(CFLAGS) ${CC_FLAGS}  


%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	valgrind ./${EXEC} arquivos_de_saida/placares.txt arquivos_de_saida/logs.txt 40

clean:	
	rm -f *.o
	rm -f $(EXEC)