/*
 
 Problem Link:
 https://www.hackerrank.com/challenges/the-hurdle-race/problem

 Ques.
 A video player plays a game in which the character competes in a hurdle race. 
 Hurdles are of varying heights, and the characters have a maximum height they can jump. 
 There is a magic potion they can take that will increase their maximum jump height by 1 
 unit for each dose. How many doses of the potion must the character take to be able to 
 jump all of the hurdles. If the character can already clear all of the hurdles, return 0.

Sample Input 0:
5 4
1 6 3 5 2

Sample Output 0:
2

Explaination:
Dan's character can jump a maximum of k=4 units, but the tallest hurdle has a height of h1=6:
To be able to jump all the hurdles, Dan must drink 6-4=2 doses.

Sample Input 1:
5 7
2 5 4 5 2

Sample Output 1:
0

Explaination:
Dan's character can jump a maximum of k=7 units, which is enough to cross all the hurdles:
Because he can already jump all the hurdles, Dan needs to drink 0 doses.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hurdleRace' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY height
 */

int hurdleRace(int k, vector<int> height) {

 int max;
 max = *max_element(height.begin(),height.end());  //storing the maximum element in max variable

 if(k>=max) return 0;   //if k is greater than or equal to max height, no doses so return 0
 else return max-k;    //else return (max-k) doses which he require to drink
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string height_temp_temp;
    getline(cin, height_temp_temp);

    vector<string> height_temp = split(rtrim(height_temp_temp));

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        int height_item = stoi(height_temp[i]);

        height[i] = height_item;
    }

    int result = hurdleRace(k, height);

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
