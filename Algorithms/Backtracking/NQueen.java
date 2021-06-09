import java.util.*;

// Java program to print all possible answers of N Queen problem
// The value 1 indicates the position of the queen in the output

class NQueen {
    // Driver code
    public static void main(String[] args) {
        int[][] board = new int[4][4];
        nQueen(board,0);
    }

    /* This function is used to check whether 
       queen can be placed in board[row][col].
       This function is called when the above
       queens are successfully placed. So we
       need to check only in upper direction.  */
    public static boolean isSafeForQueen(int[][] board, int row, int col) {
        // row is decreasing
        for (int i = row; i >= 0; i--) {
            if(board[i][col] == 1) {
                return false;
            }
        }
        // row and col are decreasing
        for (int i = row,j = col; i >= 0 && j >= 0; i--,j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        // row is decreasing and col is increasing
        for (int i = row,j = col; i >= 0 && j <= board[0].length-1; i--,j++) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    /* This function is used to check whether a queen 
       can be placed in a particular row. If the queen 
       can be placed then we check for next row and
       at the base condition when row is out of bound
       then the answer is printed */
    public static void nQueen(int[][] board,int row) {
        if(row == board.length) {
            display(board);
            System.out.println();
            return;
        }
        for (int col = 0; col < board[0].length; col++) {
            if(isSafeForQueen(board,row,col)) {
                board[row][col] = 1;
                nQueen(board,row+1);
                board[row][col] = 0;
            }
        }
    }

    // A utility function to print the solution
    public static void display(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}