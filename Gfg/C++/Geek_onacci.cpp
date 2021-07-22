/*
Description : 
        Geek created a random series and given a name geek-onacci series. Given four integers x, y, z, N. x, y, z represents the first three numbers of geek-onacci series. 
        
*/

#include <iostream>
using namespace std;

//let us call the function to find geek number in this loop
int geek_num(int p, int q, int r, int n)
{
    int sum;
    for (int i = 4; i <= n; i++)
    {
        sum = p + b + c;
        p = q;
        q = r;
        r = sum;
    }
    return sum;
}

/* Time complexity : O(log n)
Space complexity : O(1)  */


int main()
{
    int p, q, r, n;
    cout << "Enter your a , b , c and Nth digit : " << endl;
    cin >> p >> q >> r >> n;
  
//  The nth number of geek-onacci series is a sum of the 
//  last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers).
  
    cout << "Nth number of the series : " << endl;
    //now, we are  going to call the function 
    cout << geek_num(p, q, r, n) << endl;

    return 0;
}



/*
===========================
testing >>>>
===========================

compiler 

===========================

Input :
 Enter a , b , c and Nth digit : 
 1 3 2 4
 Output :
 Nth number of the series :
 6
 
===========================
*/ 
