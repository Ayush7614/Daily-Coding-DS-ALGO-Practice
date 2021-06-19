/*TEST CASE 1
INPUT 62+12
OUTPUT 9

TEST CASE 2
INPUT *+483
OUTPUT 36
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> operandstack;
    string s;
    cout << "Enter any prefix Expression: ";
    cin >> s;
    int len = s.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            operandstack.push(s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^')
        {
            int result;
            int a = operandstack.top();
            operandstack.pop();
            int b = operandstack.top();
            operandstack.pop();
            switch (s[i])
            {
            case '/':
                result = a / b;
                break;
            case '*':
                result = a * b;
                break;
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '%':
                result = a % b;
                break;
            case '^':
                result = a ^ b;
                break;
            }
            operandstack.push(result);
        }
    }
    int output = operandstack.top();
    cout << "Value of Prefix Expression: " << output;
}
