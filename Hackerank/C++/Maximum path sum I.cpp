// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler018/problem

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector < vector <int> > arr(N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                int x;
                cin >> x;
                arr[i - 1].push_back(x);
            }
        }
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (j - 1 >= 0) {
                    if (j < arr[i - 1].size()) {
                        arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
                    }
                    else {
                        arr[i][j] += arr[i - 1][j - 1];
                    }
                }
                else
                    arr[i][j] += arr[i - 1][j];
            }
        }
        int maxx = 0;
            for (int i = 0; i < arr[N - 1].size(); i++) {
                maxx = max(maxx, arr[N - 1][i]);
            }
        cout << maxx << endl;
    }
    return 0;
}
