/* CODE DESCRIPTION
A number is called lucky if the sum of its digits, as well as the sum of the squares of its digits is a prime number.
Using this C++, we can find how many numbers between a and b inclusive, are lucky.

For example, a = 15 and b = 20 .

VALUE        SUM OF DIGITS                  SUM OF SQUARE OF DIGITS      
 15          6 (non-prime)                     26 (non-prime)
 16          7 (prime)                         37 (prime)
 17          8 (non-prime)                     50 (non-prime)
 18          9 (non-prime)                     65 (non-prime)
 19          10 (non-prime)                    82 (non-prime)
 20          2 (non-prime)                     4 (non-prime)

We see that only 16 is lucky*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function that gives sum of digits of numbers
int digitSum(int num){
    int sum=0;
    while(num>0){
        sum=sum+(num%10);
        num/=10;
    }
    cout<<sum<<"\n";
    return sum;
}

// Function that gives sum of squares of digits of numbers
int squareSum(int num){
    int sum=0,rem;
    while(num>0){
        rem=num%10;
        sum=sum+rem*rem;
        num/=10;
    }
    cout<<sum<<"\n";
    return sum;
}

//Function that checks number is prime or not
bool isPrime(int n)
{
    // return false as 1 is neither prime nor composite
    if (n == 1)
        return false;

    // loop from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

//Function to check a number is lucky or not
bool isLucky(int n){
    int d_s=digitSum(n); //holds sum of all digits of n
    int s_s=squareSum(n); //holds sum of square of all digits of n

    //return true only if both d_s and s_s are prime
    if(isPrime(d_s) && isPrime(s_s))
        return true;
    else    
        return false;
}

int main(){
    int u,l;

    // Taking input from users
    cout<<"Enter the lower bound number: ";
    cin>>l;
    cout<<"Enter the upper bound number: ";
    cin>>u;
    
    //loop run from lower bound to upper bound
    for(int i=l;i<=u;i++){
        //print number if it is lucky
        if(isLucky(i))
            cout<<i<<" ";
    }
    return 0;
}
/*
OUTPUT:
Enter the lower bound number: 5
Enter the upper bound number: 15
11 12 14 
*/