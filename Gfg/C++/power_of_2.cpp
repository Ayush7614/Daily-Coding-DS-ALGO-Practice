/* There is a Problem on GFG and different platforms in which we have to tell wether a number is power 
of 2 or not without using loop.
This is not only a seperate problem but this concept can be used in many different big problem 
and help to reduce the time complexity of the program.
So we will try to solve the problem using bits manipulation concepts.

Concept
Let take some numbers which is a power of 2.Now let see how we can proof that the number is power of 2
1 in binary form->1
2 in binary form->10
4 in binary form->100
8 in binary form->1000

There is one thing common in all number that its leftmost digit is 1 while all other digits are 0.
One thing more to notice that number that less than power of 2 have one digit less than that number and has
all the digits as 1.

3 in binary form->11
7 in binary form->111
15 in binary form->1111

so if n is a number which is a power of 2 and when we take bitwise and of that number with n-1 we alwals get 0.

4-> 100
3-> 011
&-> 000

8-> 1000
7-> 0111
&-> 0000
so this is the concept
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    /* n must be greater than 0*/
    if(n<=0)
    {
        cout<<"Number is not a power of 2";
    }
    else
    {
        if(n&(n-1)==0)
        {
            cout<<"Number is a power of 2";
        }
        else
        {
            cout<<"Number is not a power of 2";
        }
    }
}