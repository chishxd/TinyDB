CC = gcc
CFLAGS = -Wall -Iinclude -g
SRC = $(wildcard src/*.c)
OUT = bin/tinydb

all: $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
