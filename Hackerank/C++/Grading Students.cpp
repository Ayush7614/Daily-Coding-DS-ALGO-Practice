/* Problem Link:
   https://www.hackerrank.com/challenges/grading/problem

   Ques.
   HackerLand University has the following grading policy:
   Every student receives a grade in the inclusive range from 0 to 100.
   Any grade less than 40 is a failing grade.

   Sam is a professor at the university and likes to round each student's grade according to these rules:
   If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
   If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.
   
Sample Input 0
4
73
67
38
33

Sample Output 0
75
67
40
33

Explaination:
Student 1 received a 73, and the next multiple of 5 from 73 is 75. Since 75-73<3, the student's grade is rounded to 75.
Student 2 received a 67, and the next multiple of 5 from 67 is 70. Since 70-67=3, the grade will not be modified and the student's final grade is 67.
Student 3 received a 38, and the next multiple of 5 from 38 is 40. Since 40-38<3, the student's grade will be rounded to 40.
Student 4 received a grade below 38, so the grade will not be modified and the student's final grade is 33.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int i;

    for(i=0;i<grades.size();i++){

        if(grades[i]>=38){       //checking for grade above 38
           if(grades[i]%5==3) grades[i]+=2;    //add 2 if the grade on dividing with 5 gives a remainder of 3
           else if(grades[i]%5 == 4) grades[i]+=1;   //add 1 if the grade on dividing with 5 gives a remainder of 4
    }  

    }
    return grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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