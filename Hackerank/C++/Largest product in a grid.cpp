// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem

#include <iostream>
#include <vector>
using namespace std;

int up(vector < vector <int> > grid) {
    int product = 0;
    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 19; j++)
            product = max(product, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
    }
    return product;
}

int left(vector < vector <int> > grid) {
    int product = 0;
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j <= 16; j++)
            product = max(product, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
    }
    return product;
}

int up_left(vector < vector <int> > grid) {
    int product = 0;
    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 16; j++)
            product = max(product, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);
    }
    return product;
}

int up_right(vector < vector <int> > grid) {
    int product = 0;
    for (int i = 19; i >= 3; i--) {
        for (int j = 0; j <= 16; j++)
            product = max(product, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
    }
    return product;
}

int main() {
    vector< vector<int> > grid(20, vector<int>(20));
    for (int grid_i = 0; grid_i < 20; grid_i++) {
        for (int grid_j = 0; grid_j < 20; grid_j++) {
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << max(max(up(grid), left(grid)), max(up_left(grid), up_right(grid)));
    return 0;
}
