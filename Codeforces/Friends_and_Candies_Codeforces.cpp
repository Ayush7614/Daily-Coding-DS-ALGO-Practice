# include<bits/stdc++.h>
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcase ll t;cin>>t;while(t--)

using namespace std;

int main()
{
    fast
    testcase
    {
        ll n, sum=0, cnt = 0;
        cin>>n;
        vector<ll> v;
        for(ll i = 0; i < n; i ++)
        {
            ll tmp;
            cin>>tmp;
            v.push_back(tmp);
            sum+=tmp;
        }
        if(sum%n != 0)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            ll avg = sum/n;
            for(ll i = 0; i < n; i ++)
            {
                if(v[i] > avg)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}

