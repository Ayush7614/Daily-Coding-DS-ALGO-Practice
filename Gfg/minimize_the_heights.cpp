/*Algorithm:
We will use sliding window method. At first we will traverse the array and add its value by decreasing(if possible)and increasing
by k in vactor of pair along with its index. Then sort the vector . Now we will consider window of size n and use visited vector 
to ensure the element of particular index is considered or not. When the size of window will become equal to n then we will
calculate the answer. Our final answer will be minimum of all answers after sliding window till right pointer will reach n-1 index.

*/

#include <bits/stdc++.h>
using namespace std;


int getMinDiff(int arr[], int n, int k)
{
    int i;
    vector<pair<int,int>>v;
    vector<int>visited(n);
        
    for(i=0;i<n;i++)
    {
        if(arr[i]-k>=0)
            v.push_back({arr[i]-k,i}); //pushing value by decreasing by k
        v.push_back({arr[i]+k,i}); //pushing value by increasing by k
    }
        
    sort(v.begin(),v.end()); // sorting 
        
    int ele=0,right=0,left=0;
        
    while(ele<n && (right<v.size())) // First window created
    {
        if(visited[v[right].second]==0)
            ele++; // if index is not visited then we will include it
        visited[v[right].second]++;
        right++;
    }
        
    int ans=v[right-1].first-v[left].first; // first possible answer
        
    while(right<v.size())
    {
        if(visited[v[left].second]==1)
            ele--; // excluding element as we are sliding window forward
        visited[v[left].second]--;
        left++;
                
        while(ele<n && right<v.size())
        {
            if(visited[v[right].second]==0)
                ele++; // if index is not visited then we will include it
            visited[v[right].second]++;
            right++;
        }
            
        if(ele==n)
            ans=min(ans,v[right-1].first-v[left].first); // Minimum of all answers
        else
            break; // window didn't contain all index element hence answer not possible
            
            
    }

    return ans;
}
      



int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
     
        int ans= getMinDiff(arr, n, k);
        cout << ans << "\n";

    }
      
   
    return 0;
} 

/*
Input :
t= 1
k= 3
n= 7
arr[]= 4 2 56 8 23 76 45

Output:
68

*/