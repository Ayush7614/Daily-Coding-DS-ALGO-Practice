/*
Program Link:
https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem

Ques.
A child is playing a cloud hopping game. In this game, there are sequentially numbered clouds that can be thunderheads or cumulus clouds. The character must jump from cloud to cloud until it reaches the start again.

There is an array of clouds, c and an energy level e=100. The character starts from c[0] and uses q unit of energy to make a jump of size k to next cloud. If it lands on a thundercloud, c[i]=1, its energy (e) decreases by 2 additional units. The game ends when the character lands back on cloud 0.

Given the values of n, k , and the configuration of the clouds as an array c, determine the final value of e after the game ends.

Sample Input:
STDIN             Function
-----             --------
8 2               n = 8, k = 2
0 0 1 0 0 1 1 0   c = [0, 0, 1, 0, 0, 1, 1, 0]

Sample Output:
92
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k) {

    int n=c.size();
    int i=0,e=100;

do{  
    i=((i+k)%n);          //finding index by the formula (i+k)%n to make the route circular
    if(c[i]==1) e=e-2;     //if the cloud is a thunderhead, energy decreases by 2 units
    e=e-1;                //energy of 1 unit is required to jump on the clouds
}
while(i!=0);           //continue the loop till it comes back again on the first index (starting position)

return e;           //return amount of energy left
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
