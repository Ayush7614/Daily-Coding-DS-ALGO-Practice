/*
Program Link:
https://www.hackerrank.com/challenges/mars-exploration/problem

Ques.
A space explorer's ship crashed on Mars! They send a series of SOS messages to Earth for help. Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string, s, determine how many letters of the SOS message have been changed by radiation.

Example. s= 'SOSTOT'
The original message was SOSSOS. Two of the message's characters were changed in transit.

Sample Input:
SOSSPSSQSSOR

Sample Output:
3

Explanation:
Expected signal: SOSSOSSOSSOS
Recieved signal: SOSSPSSQSSOR
Difference:          X  X   X

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {

    int i, count=0;
    
    //checking for a triplet of 'SOS' at a time, if the character doesn't match count it
    for(int i=0;s[i]!='\0';i=i+3){

      if(s[i]!='\0' && s[i]!='S') count++;
      if(s[i+1]!='\0' && s[i+1]!='O') count++;
      if(s[i+2]!='\0' && s[i+2]!='S') count++;

    }

    //return the wrong no of characters in the message
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
