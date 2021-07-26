/*
Programming Link:
https://www.hackerrank.com/challenges/camelcase/problem

Ques.
There is a sequence of words in CamelCase as a string of letters, , having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given s, determine the number of words in s.

Example
s= oneTwoThree
There are 3 words in the string: 'one', 'Two', 'Three'.

Sample Input:
saveChangesInTheEditor

Sample Output:
5

Explanation

String  contains five words:
1. save
2. Changes
3. In
4. The
5. Editor
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
 int i, count=1;          //at least 1 word would be present, so set count as 1

 for(i=0;s[i]!='\0';i++){  
     if(s[i]>='A' && s[i]<='Z'){    //if any uppercase is detected, count it
         count++;
     }
 }

 return count;       //return the no of words
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
