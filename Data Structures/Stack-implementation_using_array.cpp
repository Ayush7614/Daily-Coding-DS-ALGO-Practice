#include<iostream>
using namespace std;
int stack[500];

int n, i, top = -1;

void push()
{
    if(top >= n-1)
    {
        cout << "Stack overflow!" << endl;
    }
    else
    {
        int val;
        static int k = 1;
        cout << "Enter element " << k << ": ";
        cin >> val;
        top += 1;
        stack[top] = val;
    }
}
void pop()
{
    if(top <= -1)
    {
        cout << "Stack underflow!" << endl;
    }
    else
    {
        cout<<"Value :"<<stack[top]<<" at position " << top << " got deleted/popped out"<<endl;
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        cout<<"Elements in the stack are :";
        for(i=top;i>=0;i--)
        {
            cout << stack[i] << " " ;
        }
    }
    else
    {
        cout<<"STACK IS EMPTY."<<endl;
    }
}

int main()
{ 
    int ch;
    cout<<"Enter the number of elements: ";
    cin >> n;
    i=1;
    while(i)
    { 
        cout<<"\nEnter your choice: "<<endl;
        cout<<"1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n";
        cin >> ch;
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: i = 0;
                break;
            default:cout<<"Wrong Input... Enter again!"<<endl;
                break;
        }
    } 
    return 0;  
}


/*
INPUT/OUTPUT 1:
Enter the number of elements: 3

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
2
Stack underflow!

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 65

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 6

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
2
Value :6 at position 1 got deleted/popped out

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
3
Elements in the stack are :65 
Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
4

INPUT/OUTPUT 2:
Enter the number of elements: 5

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 34

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 76

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: -7

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 67

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter element 1: 23

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Stack overflow!

Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
3
Elements in the stack are :23 67 -7 76 34 
Enter your choice: 
1.PUSH
2.POP
3.DISPLAY
4.EXIT
4
*/
