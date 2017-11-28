CFLAGS += -Wall -g -std=c99
binaries = a.out sudoku

sudoku: sudoku.o

clean:
	rm -f *.o $(binaries)

.PHONY: clean
