/* In this problem a truck has to got one place to another.
So in this problem we need to find the minimun number of stops a truck takes to reach the destination.
On very stop he needs to get gas can filled and has to travel the distance.
1km=1L
*/


#include <bits/stdc++.h>

using namespace std;

int main () 
{
    int t; //Number of trucks
    cout<<"Enter the truck: ";
    cin>>t;
    while(t--)
    {
        int n; //Number of stops
        cout<<"Enter the stops: ";
        cin>>n;
        vector<pair<int,int>> a(n);  //Vector to make it easy
        cout<<"Enter the Kilometer and Petrol: "; //These are the location after which stops are there and the petrol he can get at that stop
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second; //Input of vector (First -> Kilometer, Second -> Petrol)
        }
        int l,p;
        cout<<"Final Kilometer and Petrol: "; //Total distance is to cover is 25km and the initial petrol count is 10L
        cin>>l>>p;
        for(int i=0;i<n;i++)
        {
            a[i].first = l-a[i].first;
        }
        sort(a.begin(),a.end()); //Sort the vector to make it easy ot find the ans
        int ans=0;
        int curr=p;
        priority_queue<int, vector<int> > pq;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(curr>=l)
                break;
            while(curr<a[i].first)
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                ans++;
                curr+=pq.top();
                pq.pop();
            }
            if(flag)
                break;
            pq.push(a[i].second);
        }
        if(flag)
        {
            cout<<"-1"<<"\n";
            continue;
        }
        while(!pq.empty() && curr<l)
        {
            curr+=pq.top();
            pq.pop();
            ans++;
        }
        if(curr<l)
        {
            cout<<"-1"<<"\n";
            continue;
        }
        cout<<ans;
    }
    return 0;
}
//One Solution
/*
T = 1
N = 4
A(n)
First -> 4    Second -> 4
First -> 5    Second -> 2
First -> 11   Second -> 5
First -> 15   Second -> 10
L = 25km
P = 10L
Output = 2

First we need to find the initial position which would be
Stop 1 = 25-4 = 21km
Stop 2 = 25-5 = 20km
Stop 3 = 25-11 = 14km
Stop 4 = 25-15 = 10km

So optimal Solution would be- 
1. He goes to stop 4 and fuel tank=0 distance covered=10km and gas filled=10l
2. Next he goes to stop 3 fuel tank=6 distance covered=14km and gas filled=5l as total gasfilled=11l
3. Next he reaches final destination fuel tank=0 distance covered=25km and gas filled=0l
*/
