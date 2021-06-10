/* This program prints all the possible solutions of Sudoku problem
   A sudoku solution must satisfy all of the following rules:

1) Each of the digits 1-9 must occur exactly once in each row.
2) Each of the digits 1-9 must occur exactly once in each column.
3) Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid. */

class Sudoku {
    // Driver code
    public static void main(String[] args) {
        int[][] grid = {{ 0, 7, 0, 0, 0, 0, 0, 0, 9 },
                        { 5, 1, 0, 4, 2, 0, 6, 0, 0 },
                        { 0, 8, 0, 3, 0, 0, 7, 0, 0 },
                        { 0, 0, 8, 0, 0, 1, 3, 7, 0 },
                        { 0, 2, 3, 0, 8, 0, 0, 4, 0 },
                        { 4, 0, 0, 9, 0, 0, 1, 0, 0 },
                        { 9, 6, 2, 8, 0, 0, 0, 3, 0 },
                        { 0, 0, 0, 0, 1, 0, 4, 0, 0 },
                        { 7, 0, 0, 2, 0, 3, 0, 9, 6 }};
        sudokuSolver(grid,0,0);
    }

    // This function is used to print the answer grid.
    public static void display(int[][] grid) {
        for(int a=0;a<grid.length;a++) {
            for(int b=0;b<grid[0].length;b++) {
                System.out.print(grid[a][b] + " ");
            }
            System.out.println();
        }
    }

    /* This function checks if a particular value from 1 to 9 can 
        be placed in the particular cell. If the value can be placed
        then it checks for the next column in the specific row */
    public static void sudokuSolver(int[][] grid, int row, int col) {
        // This is base condition, when all the cells of the grid are filled successfully.
        if(row == grid.length-1 && col == grid[0].length) {
            display(grid);
            System.out.println();
            return;
        }
        /* If all the columns of a particular row are filled successfully
            then the row is incremented and column is set to 0. */
        if(col == grid[0].length) {
            row = row + 1;
            col = 0;
        }
        if(grid[row][col] != 0) sudokuSolver(grid,row,col+1);
        else {
            for (int val=1;val<=9;val++) {
                if(isSafeForSudoku(grid,row,col,val)) {
                    grid[row][col] = val;
                    sudokuSolver(grid,row,col+1);
                    grid[row][col] = 0;
                }
            }
        }
    }

    /* This function checks if a particular value from 1 to 9 can be placed 
        in grid[row][col]. It checks for entire row, entire column and 
        the corresponding 3x3 box */
    public static boolean isSafeForSudoku(int[][] grid, int row, int col, int val) {
        // checking entire column
        for (int k=0;k<grid.length;k++) {
            if (grid[k][col] == val) return false;
        }
        // checking entire row
        for (int k=0;k<grid[0].length;k++) {
            if(grid[row][k] == val) return false;
        }
        // checking 3x3 box
        row = row - (row % 3);    // gives the starting index of row of particular 3x3 box
        col = col - (col % 3);    // gives the starting index of col of particular 3x3 box
        for(int k=0;k<3;k++) {
            for(int l=0;l<3;l++) {
                if(grid[row+k][col+l] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
}
