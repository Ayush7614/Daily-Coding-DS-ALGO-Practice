/*
Program Link:
https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

Ques.
Maria plays college basketball and wants to go pro. Each season she maintains a record of her play. She tabulates the number of times she breaks her season record for most points and least points in a game. Points scored in the first game establish her record for the season, and she begins counting from there.

Example: scores= [10,24,12,24]

Scores are in the same order as the games played. She tabulates her results as follows:

                                 Count
Game  Score  Minimum  Maximum   Min Max
 0      12     12       12       0   0
 1      24     12       24       0   1
 2      10     10       24       1   1
 3      24     10       24       1   1
Given the scores for a season, determine the number of times Maria breaks her records for most and least points scored during the season.

Sample Input 0:
9
10 5 20 20 4 5 2 25 1

Sample Output 0:
2 4

Sample Input 1:
10
3 4 21 36 10 28 35 5 24 42

Sample Output 1:
4 0
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int> breakingRecords(vector<int> scores) {

    int i,low=0,high=0;
    vector<int> result;      

    vector<int> min;
    min.resize(scores.size());       //declaring a vector min of size same as that of vector scores
    min.at(0)=scores.at(0);        //initialising the first element of min vector equal to first element of vector scores

    vector<int> max;
    max.resize(scores.size());    //declaring a vector min of size same as that of vector scores
    max.at(0)=scores.at(0);      //initialising the first element of max vector equal to first element of vector scores
    
    for(i=1;i<scores.size();i++){

        /*if the score at position i less than the min at position i-1,
        change the min at position i to that present in score, else copy the previous min value */
        if(min[i-1]>scores[i]) min[i]=scores[i];
        else min[i]=min[i-1];
        
        
        /*if the score at position i greater than the max at position i-1,
        change the max at position i to that present in score, else copy the previous max value */
        if(max[i-1]<scores[i]) max[i]=scores[i];
        else max[i]=max[i-1];
    }
   
    for(i=1;i<min.size();i++){

        //if there is a change in adjacent values in min or max vector, count them
        if(min[i]!=min[i-1]) low++;
        if(max[i]!=max[i-1]) high++;
    }
    
    //push the result of count into a vector
    result.push_back(high);
    result.push_back(low);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split(rtrim(scores_temp_temp));

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
