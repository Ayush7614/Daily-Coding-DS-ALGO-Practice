//------Lucky Sum of Digits Explanation------//
// Problem link is:
// https://codeforces.com/contest/110/problem/C

/* 
Problem Statement:
Petya loves lucky numbers. We all know that lucky numbers are the positive
integers whose decimal representations contain only the lucky digits 4 and 7.
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya wonders eagerly what minimum lucky number has the sum of digits equal 
to n. Help him cope with the task.
*/

/* 
Solution: In this problem you just need to find a number of lucky digits in n 
and output YES if it number is equal to 4 or 7, NO otherwise.
Here in solution, we will first find the number of 4's that can 
come in lucky number such that remaining part of number can be filled
by 7 and also sum of digits of number become equal to n. 
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n; //inputs the sum of digits n

    int i,flag=0;
    /* 
     i represents the number of 4 to be added in required number
     flag checks whether such a lucky number exists for given n
    */

    for( i=0;4*i<=n;i++)
    {
      int z=n-i*4;
      if(z%7==0){
            flag=1;// flag=1 says that a lucky number exist for
            break ;// a given n and break the loop
       }
    }

    if(flag==0) // if no such number is there for given n
      cout<<-1<<"\n";
    else
    {
      string s; //required number will be in string s 
      for(int j=1;j<=i;j++) 
        s+='4'; 

      for(int j=1;j<=n-i*4;j+=7)
        s+='7';

      cout<<s<<"\n";
    }

}