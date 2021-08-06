/* 
Program Link:
https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

Ques.
Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse. For instance, given the number 12, its reverse is 21. Their difference is 9. The number 120 reversed is 21, and their difference is 99.

She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.

Given a range of numbered days, [i...j] and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where |i-reverse(i)| is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Return the number of beautiful days in the range.

Sample Input:
20 23 6

Sample Output:
2

Explanation:
Lily may go to the movies on days 20, 21, 22, and 23. We perform the following calculations to determine which days are beautiful:
Only two days 20 and 22 are beautiful as |20-02|/6=3 and |22-22|/6=0. Thus we print two as our answer
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER i
 *  2. INTEGER j
 *  3. INTEGER k
 */
 
int reverse(int n){       //function to reverse a number
    int rem,rev=0;

    while(n!=0)    
  {    
     rem=n%10;      
     rev=rev*10+rem;    
     n/=10;    
  }

  return rev;    
}

int beautifulDays(int i, int j, int k) {
    int p,day,days=0;
    double diff,r;

    for(p=i;p<=j;p++){
      day=p;
      day=reverse(day);       //storing reverse in day
      diff =(double)(abs((double)p-(double)day))/(double)k;   //finding difference and dividing difference by k

      if(floor(diff)==diff) days++;             //checking if the day is a whole no, if yes then count it
    }

  return days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i = stoi(first_multiple_input[0]);

    int j = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    int result = beautifulDays(i, j, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
