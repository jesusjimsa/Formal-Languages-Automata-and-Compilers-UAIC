BIN = bin
SRC = Programming\ language
CFLAGS = gcc -O3 -g -Wall -std=c11 -ll
YACCFLAGS = yacc -d

language: compiler analyser $(SRC)/y.tab.c
	$(CFLAGS) $(SRC)/y.tab.c $(SRC)/lex.yy.c -o $(BIN)/language

compiler: $(SRC)/sintactic.y 
	$(YACCFLAGS) $(SRC)/sintactic.y -o $(SRC)/y.tab.c

analyser: $(SRC)/sintactic.l
	lex $(SRC)/sintactic.l
	mv ./lex.yy.c $(SRC)/

clean:
	echo "Cleaning..."
	rm $(BIN)/*

mrproper: 
	rm $(SRC)/y.tab.c
	rm $(SRC)/lex.yy.c
	rm $(BIN)/*