#include <stdbool.h>

#ifndef SUDOKU_H
#define SUDOKU_H

void solveSudoku(char** board, int boardRowSize, int boardColSize);

bool is_valid_cell(char **board, int x, int y, int boardRowSize, int boardColSize, char val);

void print_board(char **board, int boardRowSize, int boardColSize);

char **create_board(int boardRowSize, int boardColSize);

#endif /* SUDOKU_H */
