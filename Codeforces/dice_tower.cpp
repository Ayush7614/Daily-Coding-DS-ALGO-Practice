// Question link:https://codeforces.com/contest/225/problem/A
#include <iostream>
using namespace std;
int main(){
    int n,x,a,b;
    bool p(true);
    cin>>n>>x;
    while(n--){
        cin>>a>>b;
        if(x==a||x==b||x==7-a||x==7-b) p = false;
        x = 7-x;
    }cout<<(p?"YES":"NO");
    return 0;
}

// Test Case 1
// i/p
// 3
// 6
// 3 2
// 5 4
// 2 4
// o/p
// YES

// Test Case 2
// i/p
// 3
// 3
// 2 6
// 4 1
// 5 3
// o/p
// NO