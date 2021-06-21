// Problem Link: https://www.hackerrank.com/challenges/find-digits/problem

#include <bits/stdc++.h>
using namespace std;

int findDigits(int n) {
    string s = to_string(n);
    int div=0;
    for (int i=0; i<s.size(); i++) {
        if (s[i]!='0' && n%(s[i]-'0')==0)
            div++;
    }
    return div;
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

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
