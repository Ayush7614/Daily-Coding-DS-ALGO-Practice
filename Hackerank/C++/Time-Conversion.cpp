#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    char str[] = {"00:00:00\0"};
    if (s[8] == 'A')
    {
        if (s[0] == '1' && s[1] == '2')
        {
            for (int i = 2; i < 8; i++)
            {
                str[i] = s[i];
            }
            str[8] = '\0';
            return str;
        }
        else
        {
            for (int i = 0; i < 8; i++)
                str[i] = s[i];
            str[8] = '\0';
            return str;
        }
    }
    else
    {
        if (s[0] == '1' && s[1] == '2')
        {
            for (int i = 0; i < 8; i++)
                str[i] = s[i];
            str[8] = '\0';
            return str;
        }
        else
        {
            string str1;
            for (int i = 0; i < 2; i++)
                str1[i] = s[i];
            int myint1 = stoi(str1);
            myint1 += 12;
            string temp = to_string(myint1);
            for (int i = 0; i < 2; i++)
                str[i] = temp[i];
            for (int i = 2; i < 8; i++)
                str[i] = s[i];
            str[8] = '\0';
            return str;
        }
    }
    return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}