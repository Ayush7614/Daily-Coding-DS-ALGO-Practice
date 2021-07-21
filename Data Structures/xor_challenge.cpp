//         A XOR Challenge
//         Link of the problem: https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

// You are given an integer C such that the XOR of two integers (A,B) is C. In short A⊕B=C (⊕ denotes the bitwise the XOR operation).
// Out of all possible pairs of A and B, you must find two integers such that their product is maximum. 
// Let us define L(A) as the length of A in its binary representation. Then, L(A)≤L(C) and L(B)≤L(C).

// Sample Input
// 13
// Sample Output
// 70

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m = 0 ;
    cin >> n;

    for (int i = 0;i<n;i++)
    {
        long long temp = i^n;
        temp = temp *i;
        if(temp > m)
        {
            m = temp;
        }
    }
    
    cout<<m;
    return 0;
}

// In  this solution both no. should be less than n. So when i becomes 7, so temp becomes 10 when we xor i with the number 
//               7^13=10 and 10*7=70 so it is the heighest product