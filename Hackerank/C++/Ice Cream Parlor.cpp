/*
Programming Link:
https://www.hackerrank.com/challenges/icecream-parlor/problem

Ques.
Two friends like to pool their money and go to the ice cream parlor. They always choose 
two distinct flavors and they spend all of their money.
Given a list of prices for the flavors of ice cream, select the two that will cost all 
of the money they have.

Example. m=6 cost=[1,3,4,5,6]
The two flavors that cost 1 and 5 meet the criteria. Using 1-based indexing, they are at 
indices 1 and 4.

Sample Input:

STDIN       Function
-----       --------
2           t = 2
4           k = 4
5           cost[] size n = 5
1 4 5 3 2   cost = [1, 4, 5, 3, 2]
4           k = 4
4           cost[] size n = 4
2 2 4 3     cost=[2, 2,4, 3]

Sample Output:
1 4
1 2

Explanation:
Sunny and Johnny make the following two trips to the parlor:

The first time, they pool together m=4 dollars. Of the five flavors available that day, 
flavors 1 and 4 have a total cost of 1+3=4.
The second time, they pool together m=4 dollars. Of the four flavors available that day, 
flavors 1 and 2 have a total cost of 2+2=4.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr) {
    int i,j;
    vector<int> result;

  for(i=0;i<arr.size();i++){
      for(j=i+1;j<arr.size();j++){      //taking loop j starting from i+1 as we have to find a pair

          int sum= arr[i]+arr[j];  
             
          //if the sum of pairs is equal to the given amount of pool, push them in vector result 
          if(sum==m) {
              result.push_back(i+1);
              result.push_back(j+1);
          }
      }
  }
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = icecreamParlor(m, arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
