// Problem link ---https://codeforces.com/contest/1328/problem/A
// -------input-------- 
// 5
// 10 4
// 13 9
// 100 13
// 123 456
// 92 46
// --------output------- 
// 2
// 5
// 4
// 333
// 0





#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<string>
#include<string.h>
using namespace std;
const int MAX = 1000001;
int main(){
  // fast input and output
ios_base::sync_with_stdio(false);
 cin.tie(0);
cout.tie(0);
// For running the program t times
int t;
cin>>t;
while(t--){
    // Talking input of a and b
  int a,b;
  cin>>a>>b;
//   x is the remainder when a is divided by b
  int x=a%b;
  int y=b-x;
//   if a is completely divisible by b then answer will be zero
  if(y==b){
    cout<<"0"<<endl;
  }
  else{
 cout<<y<<endl;
  }
 
}
    return 0;
}
 
 
 
