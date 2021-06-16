#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int arr[6][6],row,column;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1){
            row=i;
            column=j;
            }
        }
    }
    int sum = abs(3-row)+abs(3-column);
    cout<<sum<<endl;
        
        
        
    return 0;
}