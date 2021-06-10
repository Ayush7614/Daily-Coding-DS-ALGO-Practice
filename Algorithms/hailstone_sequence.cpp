// CPP program to find Hailstone Sequence of a given number N up to 1

#include <bits/stdc++.h>
using namespace std;

int HailstoneSequence(int N)
{
    static int count;

    if (N == 1 && count == 0)
    {
        cout << N << " ";
        return count;
    }

    else if (N == 1 && count != 0)
    {
        cout << N << " ";
        count++;
        return count;
    }

    else if (N % 2 == 0)
    {
        cout << N << " ";
        count++;
        HailstoneSequence(N / 2);
    }

    else if (N % 2 != 0)
    {
        cout << N << " ";
        count++;
        HailstoneSequence(3 * N + 1);
    }
}

// Driver code
int main()
{
    int N, ans;
    cout << "Enter a number: ";
    cin >> N;
    cout << "\nHailstone Sequence upto 1:" << endl;
    ans = HailstoneSequence(N);
    cout <<"\n\nNumber of Steps involved: "<< ans << endl;
    return 0;
}
/*
Input: 
N = 13  
Hailstone sequence upto 1:                                                                   
13  40  20  10  5  16  8  4  2 1                                                                             
                                                                                                              
Number of steps involved: 10
*/
