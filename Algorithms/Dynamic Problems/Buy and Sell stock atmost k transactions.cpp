#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n,int prices[],int k)
{
    if(k >= n/2) // unlimited transactions
    {
        int s = 0;
        for(int i=1;i<n;i++)
            if(prices[i] > prices[i-1])
                s += prices[i]-prices[i-1]; 
        return s;
    }

    vector<int>b(k+1,0),s(k+1,0);  // buy and sell 
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            b[i] = max(b[j],s[j-1] - prices[i]);
            s[i] = max(s[j],b[j] + prices[i]);
        }

    }
    return s[k];
}

int main()
{
    int n,k;
    cout<<"Enter n and k ";
    cin>>n>>k;

    int prices[n];
    for(int i=0;i<n;i++)
       cin>>prices[i];

    cout<<"Maximum profit with atmost k transactions is "<<maxProfit(n,prices,k);
    return 0;
}
