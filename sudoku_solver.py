class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.cells = []
        # generate list of empty cells
        for y in range(9):
            for x in range(9):
                if board[y][x] == '.':
                    self.cells.append((x, y))
        self.dfs(board, 0)

    def dfs(self, board, pos):
        def is_valid_cell(x, y, char):
            for val in board[y]:
                if val == char:
                    return False
            for i in range(9):
                if board[i][x] == char:
                    return False
            square_coords = [
                [(1, 1), (0, 0), (2, 2), (0, 2), (2, 0), (0, 1), (2, 1), (1, 0), (1, 2)],
                [(4, 1), (3, 0), (5, 2), (3, 2), (5, 0), (3, 1), (5, 1), (4, 0), (4, 2)],
                [(7, 1), (6, 0), (8, 2), (6, 2), (8, 0), (6, 1), (8, 1), (7, 0), (7, 2)],
                [(1, 4), (0, 3), (2, 5), (0, 5), (2, 3), (0, 4), (2, 4), (1, 3), (1, 5)],
                [(4, 4), (3, 3), (5, 5), (3, 5), (5, 3), (3, 4), (5, 4), (4, 3), (4, 5)],
                [(7, 4), (6, 3), (8, 5), (6, 5), (8, 3), (6, 4), (8, 4), (7, 3), (7, 5)],
                [(1, 7), (0, 6), (2, 8), (0, 8), (2, 6), (0, 7), (2, 7), (1, 6), (1, 8)],
                [(4, 7), (3, 6), (5, 8), (3, 8), (5, 6), (3, 7), (5, 7), (4, 6), (4, 8)],
                [(7, 7), (6, 6), (8, 8), (6, 8), (8, 6), (6, 7), (8, 7), (7, 6), (7, 8)]
            ]
            for coords in square_coords:
                if (x, y) in coords:
                    square = [board[y][x] for (x, y) in coords]
                    if char in square:
                        return False
            return True
        # solve
        if pos == len(self.cells):
            return True
        (x, y) = self.cells[pos]
        for i in range(1, 10):
            if is_valid_cell(x, y, str(i)):
                board[y][x] = str(i)
                if self.dfs(board, pos + 1):
                    return True
            board[y][x] = '.'
        return False


test_board = [
    ['.', '.', '9', '7', '4', '8', '.', '.', '.'],
    ['7', '.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '2', '.', '1', '.', '9', '.', '.', '.'],
    ['.', '.', '7', '.', '.', '.', '2', '4', '.'],
    ['.', '6', '4', '.', '1', '.', '5', '9', '.'],
    ['.', '9', '8', '.', '.', '.', '3', '.', '.'],
    ['.', '.', '.', '8', '.', '3', '.', '2', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.', '6'],
    ['.', '.', '.', '2', '7', '5', '9', '.', '.'],
]
answer = [
    ['5', '1', '9', '7', '4', '8', '6', '3', '2'],
    ['7', '8', '3', '6', '5', '2', '4', '1', '9'],
    ['4', '2', '6', '1', '3', '9', '8', '7', '5'],
    ['3', '5', '7', '9', '8', '6', '2', '4', '1'],
    ['2', '6', '4', '3', '1', '7', '5', '9', '8'],
    ['1', '9', '8', '5', '2', '4', '3', '6', '7'],
    ['9', '7', '5', '8', '6', '3', '1', '2', '4'],
    ['8', '3', '2', '4', '9', '1', '7', '5', '6'],
    ['6', '4', '1', '2', '7', '5', '9', '8', '3'],
]
Solution().solveSudoku(test_board)
for y in range(9):
    for x in range(9):
        coords = (x, y)
        expected = answer[y][x]
        got = test_board[y][x]
        assert got == expected, 'Coords: {}, Expected: {}, Got: {}'.format(coords, expected, got)
