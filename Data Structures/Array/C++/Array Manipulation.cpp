#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long int> A(n,0); // sum or difference of K's value in the vector
    long len = queries.size();
    for(long i=0; i<len; i++)
    {
        //  step 1 as described above
        A[(queries[i][0])-1] = A[(queries[i][0])-1]+queries[i][2];
        if(queries[i][1]<n) // checking for segmentation fault
        {
            // step 2 as described above
            A[(queries[i][1])] = A[(queries[i][1])]-queries[i][2];
        }
    }
    long sum =0,x=0;
    // Step 3: Calculating maximum prefix array sum
    for(long i=0; i<n; i++)
        {
            x = x + A[i];
            if(x>sum)
            {
                sum = x;
            }
        }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string nm_temp;
    getline(cin, nm_temp);
    vector<string> nm = split_string(nm_temp);
    int n = stoi(nm[0]);
    int m = stoi(nm[1]);
    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    long result = arrayManipulation(n, queries);
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
