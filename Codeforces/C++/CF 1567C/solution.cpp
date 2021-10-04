/*
                                            #Hacktoberfest2021
Alice has just learned addition. However, she hasn't learned the concept of "carrying" fully — instead of carrying to the next column, she carries to the column two columns to the left.

For example, the regular way to evaluate the sum 2039+2976 would be as shown:


However, Alice evaluates it as shown:


In particular, this is what she does:

add 9 and 6 to make 15, and carry the 1 to the column two columns to the left, i. e. to the column "0 9";
add 3 and 7 to make 10 and carry the 1 to the column two columns to the left, i. e. to the column "2 2";
add 1, 0, and 9 to make 10 and carry the 1 to the column two columns to the left, i. e. to the column above the plus sign;
add 1, 2 and 2 to make 5;
add 1 to make 1.
Thus, she ends up with the incorrect result of 15005.
Alice comes up to Bob and says that she has added two numbers to get a result of n. However, Bob knows that Alice adds in her own way. Help Bob find the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of n. Note that pairs (a,b) and (b,a) are considered different if a≠b.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows.

The only line of each test case contains an integer n (2≤n≤109) — the number Alice shows Bob.

Output
For each test case, output one integer — the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of n.

Example
input
5
100
12
8
2021
10000
output
9
4
7
44
99

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define ll long long 
 
//set<string> st;
 
int main() {
    int t;
    cin>>t;
 
    while(t--) {
        string s;
        cin>>s;
 
        string a = "",b="";
        int n = s.length();
 
        for(int i=0;i<n;i++) {
            if(i%2==0)
            a+=s[i];
 
            else
            b+=s[i];
        }
 
        int n1,n2;
        n1 = (a=="")?0:stoi(a);
        n2 = (b=="")?0:stoi(b);
 
        int d1=0,d2=0;
 
        if(n1==0)
        d1 = 1;
 
        else {
            if(n1%2) {
                d1 = (n1/2)*2 + 2;
            }
 
            else
            d1 = (n1/2)*2+1;
        }
 
        //
 
        if(n2==0)
        d2 = 1;
 
        else {
            if(n2%2) {
                d2 = (n2/2)*2 + 2;
            }
 
            else
            d2 = (n2/2)*2+1;
        }
 
        int x = (d1*d2)-2;
 
        cout<<x<<"\n";
    }
 
    return 0;
}