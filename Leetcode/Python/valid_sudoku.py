"""
https://leetcode.com/problems/valid-sudoku/submissions/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


 Example:
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

"""


class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # validating rows
        for row in board:
            r = [
                element for element in row if element != "."
            ]  # deleting position dots to compare just the numbers
            if len(r) != len(
                set(r)
            ):  # comparting list with set, because the latter has no repeated values
                return False

        # validating columns
        for col in range(9):
            column = [element[col] for element in board]
            c = [element for element in column if element != "."]
            if len(c) != len(set(c)):
                return False

        # validating sub-boxes
        idx = [0, 3, 6]
        for i in idx:
            for p in idx:
                box = []
                for element in board[i : i + 3]:
                    box.extend(element[p : p + 3])
                b = [element for element in box if element != "."]

                if len(b) != len(set(b)):
                    return False
        return True
