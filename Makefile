CC = gcc
CFLAGS = -Wall -Iinclude

tinydb: $(wildcard src/*.c)
	$(CC) $(CFLAGS) $(wildcard src/*.c) -o tinydb

clean:
	rm -f tinydb
