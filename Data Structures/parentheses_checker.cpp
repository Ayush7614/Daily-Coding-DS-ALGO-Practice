#include<iostream>
using namespace std;
#include<stack>
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int n=s.length();
        if(n==0)
        return 0;
        stack<char> v;
    int c=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if((s[i]=='{') || (s[i]=='[') || (s[i]=='(')){
        v.push(s[i]);
        continue;}
       
        if (v.empty())
            return false;
           
        else if((s[i]==')' && v.top()!='(') || (s[i]==']' && v.top()!='[') || (s[i]=='}' && v.top()!='{'))
        {
            c=1;
            break;
        }
        else if((s[i]==')' && v.top()=='(') || (s[i]==']' && v.top()=='[') || (s[i]=='}' && v.top()=='{'))
            v.pop();
    }
   
    if(c==0 && v.empty()==1)
    return true;
    else
    return false;

    }
   
};
int main()
{
    int t;
    cin>>t;
    string a;
    while(t--)
    {
cin>>a;
Solution obj;
if(obj.ispar(a))
  cout<<"balanced"<<endl;
else
  cout<<"unbalanced"<<endl;
    }
}     




//Test Cases
/*
Input: “[()]{}{()()}”
Output: Balanced

Input: “[(])”
Output: Not Balanced

Input: "a*[ (b*c)+d]"
Output: Balanced
*/
