#include <iostream>
using namespace std;

void spiral_traversal(int matrix[10][10], int r, int c)
{
    int row = 0, col = 0, i =0;
    while(row < r && col <c)
    {
        for(i = col; i < c; i++)
            cout << matrix[row][i] << " ";
        row++;

        for(i = row; i < r; i++)
            cout << matrix[i][c-1] << " ";
        c--;

        if (row < r) {
            for (i = c - 1; i >= col; --i) {
                cout << matrix[r - 1][i] << " ";
            }
            r--;
        }

        if (col < c) {
            for (i = r - 1; i >= row; --i) {
                cout << matrix[i][col] << " ";
            }
            col++;
        }
    }
}

int main()
{
    int n,m;
    cin >> m >> n;
    int matrix[10][10];
    for(int i=0; i<m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    spiral_traversal(matrix, m, n);
    return 0;
}
