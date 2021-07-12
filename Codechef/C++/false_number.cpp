#include <bits/stdc++.h>
using namespace std;

int main() {
 int t;
 /* take input of test cases */
 cin>>t;

 /* loop while testcase !=0 */
 while(t--){
   string s;
   /* take string input */
   cin>>s;

   /* if first digit is 1 */
   if(s[0]=='1'){
       s[0]='0';
       cout<<1<<s<<endl;
   }

   /* if first digit is not 1 */
   else{
       cout<<1<<s<<endl;
   }
 }
 return 0;
}

/*
Sample Input:
2
9876543211
12345678999

Sample Output:
19876543211
102345678999
*/
