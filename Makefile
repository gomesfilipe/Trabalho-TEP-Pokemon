all:
	gcc client/main.c src/*.c src/pokemons/*.c -o main

run:
	./main