all:
	gcc src/pokemons/*.c src/*.c client/main.c -o main

run:
	./main