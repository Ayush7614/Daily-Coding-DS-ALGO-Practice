// Problem Link: https://www.hackerrank.com/challenges/extra-long-factorials/problem

#include <bits/stdc++.h>
using namespace std;

void extraLongFactorials(int n) {
    stack<int> digit;
    stack<int> ans;
    digit.push(1);
    int carry, i;
    for (int j=2; j<=n; j++) {
        carry=0;
        while(!digit.empty()) {
            ans.push((carry+j*digit.top())%10);
            carry = (carry+j*digit.top())/10;
            digit.pop();
        }
        while(carry>0) {
            ans.push(carry%10);
            carry = carry/10;
        }
        while(!ans.empty()) {
            digit.push(ans.top());
            ans.pop();
        }
    }
    
    while(!digit.empty()) {
        ans.push(digit.top());
        digit.pop();
    }
    while(!ans.empty()) {
        cout<<ans.top();
        ans.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
