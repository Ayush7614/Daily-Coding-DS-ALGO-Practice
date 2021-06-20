// Problem Link: https://www.hackerrank.com/challenges/utopian-tree/problem

#include <bits/stdc++.h>
using namespace std;

int utopianTree(int n) {
    int height=1;
    for (int i=1; i<=n; i++) {
        if(i%2 == 0)
            height++;
        else
            height *= 2;
    }
    return height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
