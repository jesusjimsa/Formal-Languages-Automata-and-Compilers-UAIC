BIN = bin
SRC = Programming\ language
CFLAGS = gcc -O3 -g -Wall -std=c11

language: source $(SRC)/y.tab.c
	$(CFLAGS) $(SRC)/y.tab.c -o $(BIN)/language

source: $(SRC)/sintactic.y
	yacc $(SRC)/sintactic.y -o $(SRC)/y.tab.c

clean:
	echo "Cleaning..."
	rm $(BIN)/*

mrproper: clean
	rm $(SRC)/y.tab.c