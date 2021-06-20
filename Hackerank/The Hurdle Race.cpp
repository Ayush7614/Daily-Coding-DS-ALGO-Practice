// Problem Link: https://www.hackerrank.com/challenges/the-hurdle-race/problem

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

int hurdleRace(int k, vector<int> height) {
    int no_of_doses=0, max_height=0;
    for(int i=0; i<height.size(); i++) {
        if(height[i]>max_height)
            max_height=height[i];
    }
    if(max_height>k)
        no_of_doses = max_height-k;
    return no_of_doses;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string height_temp_temp;
    getline(cin, height_temp_temp);

    vector<string> height_temp = split_string(height_temp_temp);

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
