CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: src/main.c src/fila.c src/pilha.c src/hash.c src/ordenacao.c
	$(CC) $(CFLAGS) src/main.c src/fila.c src/pilha.c src/hash.c src/ordenacao.c -o helpdesk

test: tests/testes.c src/fila.c src/pilha.c src/hash.c src/ordenacao.c
	$(CC) $(CFLAGS) tests/testes.c src/fila.c src/pilha.c src/hash.c src/ordenacao.c -o testes
	./testes

clean:
	rm -f helpdesk testes
