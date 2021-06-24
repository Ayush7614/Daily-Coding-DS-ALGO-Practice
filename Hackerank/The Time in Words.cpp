#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */
string pasto(int x)
{
    if(x>=1 && x<=30)
        return "past";
    else
        return "to";
}

string timeInWords(int h, int m) {
    vector<string> numbers = {"zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
        };
    string result;
    if(m==0)
    {
        result = numbers[h] + " o' clock";
    }
    else if(m==30)
    {
        result = "half past " + numbers[h];
    }
    else if(m==15)
    {
        result = "quarter past " + numbers[h];
    }
    else if(m==45)
    {
        result = "quarter to " + numbers[h+1];
    }
    else if(m==1)
    {
        result = numbers[m] + " minute past " + numbers[h];
    }
    else if(m>1 && m<=30)
    {
        result = numbers[m] + " minutes past " + numbers[h];
    }
    else
    {
        result = numbers[60-m] + " minutes to " + numbers[h+1];
    }
    return result;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}



/*

Sample Input:
5
47

Sample Output:
thirteen minutes to six

*/


