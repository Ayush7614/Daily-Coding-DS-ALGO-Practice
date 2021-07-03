/*
Indian Coin Change Problem
In this we enter the number and it will find the minimum number of coins change for that number
*/

#include <bits/stdc++.h>
using namespace std;

int currency[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
int n = sizeof(currency) / sizeof(currency[0]);

void find(int V)
{
    sort(currency, currency + n);
    vector<int> min;
    for (int i = n - 1; i >= 0; i--) 
    {
        while (V >= currency[i]) 
        {
            V -= currency[i];
            min.push_back(currency[i]);
        }
    }
   int count =0;
   for (int i = 0; i < min.size(); i++)
    {   cout << min[i] << " ";
        count++;
    }
    cout<<"\nCoins it took to make the desired number: "<<count;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout << "Minimal number of change for " << n <<": ";
    find(n);
    return 0;
}

/*
n = 73
Minimal number of change for 73: 50, 20, 2, 1
Coins it took = 4
*/ 