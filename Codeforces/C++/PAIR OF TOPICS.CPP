#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int>,null_type,less<int>,rb_tree_tag;
tree_order_statistics_node_update>
    PBDS;
    int main()
    {
        
        int n;
        cin>>n;
        int a[n],b[n],c[n];
        for(int i=0;i<n;i++)
        cin>>a[n];
         for(int i=0;i<n;i++)
        cin>>b[n];
         for(int i=0;i<n;i++)
            c[i]=a[i]-b[i];
            long long int ans=0;
            PBDS st;
         for(int i=0;i<n;i++)
        {
            ans+=st.size()-st.order_of_key({-c[i],10000000});
            st.insert({c[i],i});
        }
cout<<ans;

    }