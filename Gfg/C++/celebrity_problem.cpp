/*
Algorithm :
We will implement elimination method using stack.
First push all the people in stack, then pop two person(Consider A and B) every time untill stack become empty or only one person is left.
We will check that if A knows B means A cannot be celebrity so we will push B back in the stack.
Similarly if B knows A then push A in stack.
At last either stack will be empty means there is no celebrity or only one person will left which may or may not be celebrity(potential celebrity)
If the whole row of potential celebrity is 0(means he doesn't know anyone) and the whole column except itself is 1( means everyone knows him).
Then he is the celebrity otherwise there is no celebrity in the party.
*/
#include<iostream>
#include <stack>

using namespace std;

// Function to find celebrity
int celeb(int m[3001][3001],int n)
{
    stack<int>s;
    int temp;

    // Pushing all person in the stack
    for(int i=0;i<n;i++)
        s.push(i);


    while(s.size()>=2)
    {
        // Poping to two person
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        // A doesn't know B means B cannot be celebrity 
        if(m[a][b]==0)
            s.push(a);
        // A knows B means B can be celebrity
        else
            s.push(b);
    }

    // If stack is empty means there is no celebrity
    if(s.size()==0)
        return -1;

    else
    {
        // temp may or may not be a celebrity
        temp=s.top();

         for(int i=0;i<n;i++)
         {
             // temp is not a celebrity
             if(m[temp][i]!=0 || ((i!=temp) && m[i][temp]!=1))
                return -1;

        }
    }

    // temp is the celebrity
    return temp;



}

int main()
{

    int n,i,m[3001][3001],c;

    cout<<"Enter total number of person in the party= ";
    cin>>n;

    // Taking input in the form of matrix
    cout<<"\nEnter the input matrix=\n";
    for(i=0;i<n;i++)
        for(i=0;i<n;i++)
            cin>>m[i][i];

    // Calling celeb() function
    c=celeb(m,n);

    // Displaying if there is celebrity or not in the party
    if(c==-1)
        cout<<"\nNo one is celebrity";
    else
        cout<<"\n"<<c<<" is the celebrity";

    return 0;
}


/*
Input: 
n= 4
m[][]== {{0 0 0 1},
         {1 0 0 1}, 
         {0 0 1 1}, 
         {0 0 0 0}}
Output: 3 
Explanation: 0th, 1st and 2nd person all know 3. Therefore, 3 is the celebrity .
Input: 
n= 3
m[][]== {{0 0 1},
         {0 0 0}, 
         {1 1 0}}
Output: -1
Explanation: 1st person doesn't know anyone but everyone doesn't know him(2nd person knows him but 0th doesn't).
Therefore, there is no celebrity .
Time Complexity: O(N)
Space Complexity: O(N)
*/ 