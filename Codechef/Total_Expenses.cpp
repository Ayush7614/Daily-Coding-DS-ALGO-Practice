/*
TEST CASE:
    Input:
        3   
        100 120
        10  20
        1200    20  
    Output:
        12000.000000
        200.000000
        21600.000000
*/
#include <bits/stdc++.h>
#define ll unsigned long int
using namespace std;

int main()
{
    ll test;
    cin >> test;
    for (ll k = 0; k < test; k++)
    {
        double quantity, price;
        cin >> quantity >> price;
        if (quantity > 1000)
        {
            double discount = price * 0.1;
            price = price - discount;
        }
        double result = quantity * price;
        cout << fixed << setprecision(6) << result << endl;
    }

    return 0;
}
