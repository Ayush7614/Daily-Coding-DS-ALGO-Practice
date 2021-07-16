/* Program Link:
https://www.hackerrank.com/challenges/mini-max-sum/problem

Aim:
Given five positive integers, find the minimum and maximum values that can be calculated 
by summing exactly four of the five integers. Then print the respective minimum and maximum 
values as a single line of two space-separated long integers.

Function Description:
Complete the miniMaxSum function in the editor below.
miniMaxSum has the following parameter(s):
- arr: an array of  integers
Print:
-Print two space-separated integers on one line: the minimum sum and the maximum sum of  of  elements.

Sample Input:
1 2 3 4 5

Sample Output:
10 14
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    int i;
    long long max=0,min=0;
    sort(arr.begin(),arr.end());    //sorted the vector array to find maximum or minimum four numbers in vector easily
    for(i=0;i<4;i++){
        min+=arr[i];               //the numbers fron starting to second last element in array will be the minimum 4 elements in a sorted vector
    }
    for(i=1;i<5;i++){         
        max+=arr[i];              //the numbers fron second element to last element in array will be the maximum 4 elements in a sorted vector
    }
    cout<<min<<" "<<max;
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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
