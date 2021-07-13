import java.io.*;
import java.util.Scanner;

class Solution {
    static void rotateMatrix(int N, int mat[][])
    {
        for (int x = 0; x < N / 2; x++) {

            for (int y = x; y < N - x - 1; y++) {
                int temp = mat[x][y];

                mat[x][y] = mat[y][N - 1 - x];

                mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

                mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

                mat[N - 1 - y][x] = temp;
            }
        }
    }

    static void displayMatrix(int N, int mat[][])
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(" " + mat[i][j]);

            System.out.print("\n");
        }
        System.out.print("\n");
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        int[][] mat = new int[N][N];
        
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++)
                mat[i][j] = sc.nextInt();
        
        rotateMatrix(N, mat);

        displayMatrix(N, mat);
    }
}
