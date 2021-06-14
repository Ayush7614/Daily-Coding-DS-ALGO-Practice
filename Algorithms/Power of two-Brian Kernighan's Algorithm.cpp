/*Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit,So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count.
The beauty of this algorithm  is the number of times it loops is equal to the number of set bits in a given integer. */


/*An interesting fact about the powers of two is, all the powers of two have only 1 set bit in the decimal representation*/


#include<iostream>
using namespace std;
bool isPowerofTwo(long long n)
{

        if(n==0)return false;
        else
        return(((n)&(n-1))==0); //if it has one set bit, then it returns true else false.
}
int main()
{
int n;
cin>>n;
if(isPowerofTwo(n))
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
