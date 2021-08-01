/*
Program Link:
https://www.hackerrank.com/challenges/strong-password/problem

Ques.
Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

1. Its length is at least 6.
2. It contains at least one digit.
3. It contains at least one lowercase English character.
4. It contains at least one uppercase English character.
5. It contains at least one special character. The special characters are: !@#$%^&*()-+

She typed a random string of length n in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Sample Input:
3
Ab1

Sample Output:
3

Explanation:
She can make the password strong by adding 3 characters, for example, $hk, turning the password into Ab1$hk which is strong.
2 characters aren't enough since the length must be at least 6.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {

    // Return the minimum number of characters to make the password strong
    int i,arr[4]={0},count=0;
    
    //counting the digits, lowercase and uppercase letters
    for(i=0;password[i]!='\0';i++){
        if(isdigit(password[i])) arr[0]++;
        else if(islower(password[i])) arr[1]++;
        else if(isupper(password[i])) arr[2]++;
        else arr[3]++;
    }
    
    //if there is a missing character, count it
    for(i=0;i<4;i++){
        if(arr[i]==0) count++;
    }
    
    //if the length is not sufficient, take it in variable x
    int x= 6-(n+count);
    
    //add the additional characters required
    if(x>0) count+=x;
    
    //return the additional characters required for valid password
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
