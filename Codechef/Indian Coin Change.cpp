/*
Indian Coin Change Problem
In this we enter the number and it will find the minimum number of coins change for that number
*/

#include <bits/stdc++.h>
using namespace std;
 
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
int n = sizeof(deno) / sizeof(deno[0]);
 
void findMin(int V)
{
    sort(deno, deno + n);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) 
    {
        while (V >= deno[i]) 
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
   int count =0;
   for (int i = 0; i < ans.size(); i++)
    {   cout << ans[i] << " ";
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
    findMin(n);
    return 0;
}

/*
n = 73
Minimal number of change for 73: 50, 20, 2, 1
Coins it took = 4
*/