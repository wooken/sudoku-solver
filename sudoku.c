#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
}

void print_board(char **board, int boardRowSize, int boardColSize) {
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

char **create_board() {
    char **board = malloc(9 * sizeof(char *));
    for (int i = 0; i < 9; i++) {
        board[i] = malloc(9 * sizeof(char));
    }
    return board;
}

int main(int argc, char *argv[]) {
    char **puzzle = create_board();
    strncpy(puzzle[0], "..9748...", 9);
    strncpy(puzzle[1], "7........", 9);
    strncpy(puzzle[2], ".2.1.9...", 9);
    strncpy(puzzle[3], "..7...24.", 9);
    strncpy(puzzle[4], ".64.1.59.", 9);
    strncpy(puzzle[5], ".98...3..", 9);
    strncpy(puzzle[6], "...8.3.2.", 9);
    strncpy(puzzle[7], "........6", 9);
    strncpy(puzzle[8], "...2759..", 9);

    char **answer = create_board();
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
