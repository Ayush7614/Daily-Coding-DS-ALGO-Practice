// Problem Link: https://www.hackerrank.com/challenges/strange-advertising/problem

#include <bits/stdc++.h>
using namespace std;

int viralAdvertising(int n) {
    int C = 2, L=2;
    for (int i=2; i<=n; i++) {
        L = floor(3*L/2);
        C += L;
    }
    return C;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
