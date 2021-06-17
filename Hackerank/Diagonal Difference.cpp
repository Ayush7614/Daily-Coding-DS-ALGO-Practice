// Problem Link: https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int sum=0;
    int n = arr.size();
    for (int rowindex=0; rowindex<n; rowindex++) {
        sum += arr[rowindex][rowindex] - arr[rowindex][n-1-rowindex];
    }
    return abs(sum);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
