// Problem Link: https://www.hackerrank.com/challenges/append-and-delete/problem

#include <bits/stdc++.h>
using namespace std;

string appendAndDelete(string s, string t, int k) {
    int count=0;
    for (int i=0; i<min(s.size(), t.size()); i++) {
        if(s[i]==t[i])
            count++;
        else
            break;
    }
    if(k+2*count<s.size()+t.size())
        return "No";
    else if(k>=s.size()+t.size())
        return "Yes";
    else if((k-((s.size()-count)+(t.size()-count)))%2==0)
        return "Yes";
    else
        return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
