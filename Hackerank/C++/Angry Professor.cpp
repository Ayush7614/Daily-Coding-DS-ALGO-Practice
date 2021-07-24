/*
Program Link:
https://www.hackerrank.com/challenges/angry-professor/problem

Ques.
A Discrete Mathematics professor has a class of students. Frustrated with their lack of 
discipline, the professor decides to cancel class if fewer than some number of students 
are present when class starts. Arrival times go from on time ( arrivalTime <= 0 ) to 
arrived late ( arrivalTime > 0 ).

Sample Input:
2
4 3
-1 -3 4 2
4 2
0 -1 2 1

Sample Output:
YES
NO

Explanation:
For the first test case,k=3. The professor wants at least 3 students in attendance, but 
only 2 have arrived on time (-3 and -1) so the class is cancelled.
For the second test case, k=2. The professor wants at least 2 students in attendance, and 
there are 2 who arrived on time (0 and -1). The class is not cancelled.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'angryProfessor' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY a
 */

string angryProfessor(int k, vector<int> a) {

int ontime=0;           //for counting the students who are on time

for(int i=0;i<a.size();i++){
    if(a[i]<=0) ontime++;      //Negative elements and element 0 is considered to be on time
}

 if(ontime>=k) return "NO";   //if the students on time are greater than or equal to k, the class is not cancelled
 else return "YES";     //if the students on time are less than k, the class is cancelled
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string result = angryProfessor(k, a);

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
