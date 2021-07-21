/* 
-------------------------------------
Test Case 1:
Input: 24
Output: 5

Test Case 2:
Input: 3
Output: 1
-------------------------------------
 */

#include<bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int minOperation(int N){
        int days = 0,t,num = N;
        int m = 0;
        while(num > 0){
            N = num;
            m = 0;
        
        while(N > 0){
            t = N % 10;
            N = N / 10;
            m = max(t,m);
        }
        days++;
        num = num - m;
        }
    return days;
}
};

//Driver code starts
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        cout << ob.minOperation(N) << endl;
    }
    return 0;
}