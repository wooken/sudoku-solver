#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sudoku.h"

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
}

bool is_valid_cell(char **board, int x, int y, int boardRowSize, int boardColSize, char val) {
    // check row
    for (int col = 0; col < boardRowSize; col++) {
        if (col == y) {
            continue;
        }
        if (board[x][col] == val) {
            return false;
        }
    }
    // check column
    for (int row = 0; row < boardColSize; row++) {
        if (row == x) {
            continue;
        }
        if (board[row][y] == val) {
            return false;
        }
    }
    // check box
    int x_min = (x > 0) ? x - 1 : x;
    int x_max = (x < boardRowSize - 1) ? x + 1 : x;
    int y_min = (y > 0) ? y - 1 : y;
    int y_max = (y < boardColSize - 1) ? y + 1 : y;
    for (int x_prime = x_min; x_prime <= x_max; x_prime++) {
        for (int y_prime = y_min; y_prime <= y_max; y_prime++) {
            if ((x_prime == x) && (y_prime == y)) {
                continue;
            }
            if (board[x_prime][y_prime] == val) {
                return false;
            }
        }
    }
    return true;
}

void print_board(char **board, int boardRowSize, int boardColSize) {
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

char **create_board(int boardRowSize, int boardColSize) {
    char **board = malloc(boardRowSize * sizeof(char *));
    for (int i = 0; i < boardRowSize; i++) {
        board[i] = malloc(boardColSize * sizeof(char));
    }
    return board;
}

int main(int argc, char *argv[]) {
    char **puzzle = create_board(9, 9);
    strncpy(puzzle[0], "..9748...", 9);
    strncpy(puzzle[1], "7........", 9);
    strncpy(puzzle[2], ".2.1.9...", 9);
    strncpy(puzzle[3], "..7...24.", 9);
    strncpy(puzzle[4], ".64.1.59.", 9);
    strncpy(puzzle[5], ".98...3..", 9);
    strncpy(puzzle[6], "...8.3.2.", 9);
    strncpy(puzzle[7], "........6", 9);
    strncpy(puzzle[8], "...2759..", 9);

    char **answer = create_board(9, 9);
    strncpy(answer[0], "519748632", 9);
    strncpy(answer[1], "783652419", 9);
    strncpy(answer[2], "426139875", 9);
    strncpy(answer[3], "357986241", 9);
    strncpy(answer[4], "264317598", 9);
    strncpy(answer[5], "198524367", 9);
    strncpy(answer[6], "975863124", 9);
    strncpy(answer[7], "832491756", 9);
    strncpy(answer[8], "641275983", 9);

    solveSudoku(puzzle, 9, 9);
}
