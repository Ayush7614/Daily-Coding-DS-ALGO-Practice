#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int a[], int n , int x )
{
    // code here
    int mid, low=0,high=n-1;
    bool flag=false;
    vector<int> ans;
    while(low<=high)
    {
        mid= low+ (high-low)/2;
        if(a[mid]==x)
        {
            flag=true;
            break;
        }
        if(a[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==false)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    low=mid,high=mid;
    while(a[low]==x)
    {
        low--;
    }
    while(a[high]==x)
    {
        high++;
    }
    ans.push_back(low+1);
    ans.push_back(high-1);
    return ans;
}
