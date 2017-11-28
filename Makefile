CFLAGS += -Wall -g -std=c99
binaries = a.out sudoku

sudoku: sudoku.o

run: sudoku
	@./sudoku

clean:
	rm -f *.o $(binaries)

.PHONY: clean run
