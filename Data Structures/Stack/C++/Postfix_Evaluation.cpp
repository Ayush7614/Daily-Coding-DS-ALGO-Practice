/*
Test Case 1:
    Input: 62/12+*
    Output: 9
Test Case 2:
    Input: 82/22+*
    Output: 16
Test Case 3:
    Input: 21421+*3++*
    Output: 32
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> stack1;
    cout << "Enter any Postfix Expression: ";
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            stack1.push(s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^')
        {
            int result;
            int a = stack1.top();
            stack1.pop();
            int b = stack1.top();
            stack1.pop();
            switch (s[i])
            {
            case '/':
                result = b / a;
                break;
            case '*':
                result = b * a;
                break;
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '%':
                result = b % a;
                break;
            case '^':
                result = b ^ a;
                break;
            }
            stack1.push(result);
        }
    }
    int output = stack1.top();
    cout << "Value: " << output;

    return 0;
}