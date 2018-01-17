BIN = bin
SRC = Programming\ language
CFLAGS = gcc -O3 -g -Wall -std=c11 -ll
YACCFLAGS = yacc -dvt
LEXFLAGS = lex -l -d

language: analyser compiler $(SRC)/y.tab.c
	$(CFLAGS) $(SRC)/y.tab.c $(SRC)/lex.yy.c -o $(BIN)/language

analyser: $(SRC)/sintactic.l
	lex $(SRC)/sintactic.l
	mv ./lex.yy.c $(SRC)/

compiler: $(SRC)/sintactic.y 
	$(YACCFLAGS) $(SRC)/sintactic.y -o $(SRC)/y.tab.c

run: language
	$(BIN)/language

frun: $(BIN)/language
	$(BIN)/language

clean:
	echo "Cleaning..."
	rm -r $(BIN)/*

mrproper: 
	rm $(SRC)/y.tab.c
	rm $(SRC)/y.tab.h
	rm $(SRC)/y.output
	rm $(SRC)/lex.yy.c
	rm -r $(BIN)/*