/*
Program Link:
https://www.hackerrank.com/challenges/find-digits/problem

Ques.
An integer d is a divisor of an integer n if the remainder of n%d=0.

Given an integer, for each digit that makes up the integer determine whether it is a 
divisor. Count the number of divisors occurring within the integer.

Sample Input:
2
12
1012

Sample Output:
2
3
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'findDigits' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int findDigits(int n) {

int num=n, digit,count=0;

while(num>0){                    //continue till num is greater than 0

    digit=num%10;               //calculate the remainder- it'll give the digit
    if(digit!=0){               //if the digit is not 0 and it is the dividing the given no n, count it
    if(n%digit==0) count++;

  }
  num/=10;              //divide num by 10 to find all the digits in the given no n
}

return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = findDigits(n);

        fout << result << "\n";
    }

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
