// link to the question=https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/n-queens-official/ojquestion
// Question-given the no of queens i.e N, print all the configurations in which queens can be placed safely on a N*N chessboard
// Test Cases
// Input   
// 4   
// Output
//  0-1, 1-3, 2-0, 3-2, .
//  0-2, 1-0, 2-3, 3-1, .
// Input
// 6
// 0-2, 1-5, 2-1, 3-4, 4-0, 5-3, .
// 0-3, 1-0, 2-4, 3-1, 4-5, 5-2, .
// 0-4, 1-2, 2-0, 3-5, 4-3, 5-1, .
// Input
// 2

// No configuration is possible hence blank line 


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] chess = new int[n][n];
        printNQueens(chess, "", 0);
    }

    public static void printNQueens(int[][] chess, String qsf, int row){
        if(row == chess.length){
            System.out.println(qsf + ".");
            return;
        }
        for(int col = 0; col < chess.length; col++){
            // 0 means current position is unoccupied and 1 means it is occupied
            if(chess[row][col] == 0 && isQueenSafe(chess, row, col) == true){
                chess[row][col] = 1;
                printNQueens(chess, qsf + row + "-" + col + ", ", row + 1);
                chess[row][col] = 0;
            }
        }
    }
    // function to check if queen will not attacked from another queen horizontally,vertically or diagonally
    public static boolean isQueenSafe(int[][] chess, int row, int col){
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col; i >= 0; i--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < chess.length; i--, j++){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row, j = col - 1; j >= 0; j--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        return true;
    }
}