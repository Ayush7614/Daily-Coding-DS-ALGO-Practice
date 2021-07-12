/* Coins And Triangle || Problem Code: TRICOIN */
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int n;
        cin >> n;
        
        int i = 1, sum = 0, count = 0;
        
        if(n == 1)
        {
            cout << 1 << endl;
        }
        
        else
        {
            while(sum <= n)
            {
                sum += i;
                i++;
                count++;
            }
            cout << (count-1) << endl;
        }
        
    }

/*
Input
3
3 5 7

Output
2
2
3
*/
