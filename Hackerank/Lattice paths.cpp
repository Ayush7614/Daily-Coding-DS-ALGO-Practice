// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler015/problem

#include <iostream>
using namespace std;

int main() {
    unsigned long long arr[501][501];
    for (int i = 0; i < 501; i++) {
        arr[i][0] = 1;
        arr[0][i] = 1;
    }
    for (int i = 1; i < 501; i++) {
        for (int j = 1; j < 501; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> N >> M;
        cout << arr[N][M]<< endl;
    }
    return 0;
}
