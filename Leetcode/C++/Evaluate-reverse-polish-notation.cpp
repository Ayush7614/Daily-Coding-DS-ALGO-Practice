//LINK TO PROBLEM:
/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
//AIM:Evaluate the value of an arithmetic expression in Reverse Polish Notation.

//NOTE: Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
//EXAMPLES:
/*
Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/
#include<bits/stdc++.h>
using namespace std;
    int evalRPN(vector<string>& tokens) {
        stack<string>s;//Taking to hold check conditions
        int ans=0;
        for(int i=0;i<tokens.size();i++)
        {
            s.push(tokens[i]);//pushing all chars in the stack
        
        if(s.top()=="+"||s.top()=="-"||s.top()=="*"||s.top()=="/")//if it is an operator
        {
            string t=s.top();//popping the oprator
            s.pop();
            int cnt1=stoi(s.top());//converting operand to a integer
            s.pop();//popping operand 1
            int cnt2=stoi(s.top());//converting operand to a integer
            s.pop();//popping operand 2
             if(t=="+"){
                 //appling operators
                    ans=cnt1+cnt2;
                }else if(t=="-"){
                    ans=cnt2-cnt1;
                }else if(t=="*"){
                    ans=cnt1*cnt2;
                }else if(t=="/"){
                    ans=cnt2/cnt1;
                }
                // cout<<ans<<"\n";
            s.push(to_string(ans));//converting to a strng in order to push to a stack
        }
        }
        return stoi(s.top());//return required result:)
}
int main()
{
    string s;
    vector<string> ss;
    cin >> s;
    ss.push_back(s);
    int ans=evalRPN(ss);
    cout<<ans<<endl;
    return 0;
}