#include <iostream>
#define MAX 1000
using namespace std;

class stack {
public:
    int Top;
    char a[MAX]; // Maximum size of Stack

    stack() { Top = -1; }       //defult constructure

    char push(char x){          //data add in stack
        if (Top >= (MAX - 1)) {
            cout << "Stack Overflow";
        }
        else {
            a[++Top] = x;
        }
        return *a;
    }

    char pop(){                 //data remove from stack
        if (Top < 0) {
            cout << "Stack Underflow";
            return 0;
        }
        else {
            char x = a[Top--];
            return x;
        }
    }

    char top(){                 //return top element
        if (Top < 0) {
            cout << "Stack is Empty";
            return 0;
        }
        else {
            char x = a[Top];
            return x;
        }
    }

    bool empty(){               //function for checking stack in empty or not
        return (Top < 0);
    }
};

string isBalanced(string s) {
    
    stack st;
        
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '{':
            case '(':
            case '[':
                st.push(s[i]);
                break;
            case '}':
                if (st.empty() || (st.top() != '{')) {
                    return "Unbalanced parenthesis";
                }
                st.pop();
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return "Unbalanced parenthesis";
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || (st.top() != '[')) {
                    return "Unbalanced parenthesis";
                }
                st.pop();
                break;
            default:
                continue;
        }
    }
    
    return st.empty() ? "Balanced parenthesis" : "Unbalanced parenthesis";
}

int main() {
   
   string eq;
   cout<<"Enter mathematical equation\t: \t";       //input
   cin>>eq;
   string result = isBalanced(eq);
   cout<<endl<<"Output\t\t\t\t: \t"<<result;        //ouptup
   return 0;
}
/*
Input: {([{}])}
Output: Balanced parenthesis

Input: {([{]})}
Output: Unbalanced parenthesis
*/