#include <bits/stdc++.h>
using namespace std;
#define m1 1000000007
#define ll long long
#define vi vector<int>
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for(int i = (a); i<= (b); i++)
#define loopneg(i, a, b) for(int i = (a); i>= (b); i--)
#define arint(n) int ar[n]

const int MAX = 1000000;
int prefix[MAX + 1];


void sieve()
{
    bool prime[MAX + 1];
    memset(prime, true, sizeof(prime));

    for(int i = 2; i * i <= MAX; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i * 2; j<= MAX; j+= i)
            {
                prime[j] = false;
            }
        }
    } 

    prefix[0] = prefix[1] = 0;
    for(int i = 2; i<= MAX; i++)
    {
        prefix[i] = prefix[i-1];
        if(prime[i]) prefix[i]++;
    }
}

int count_primes(int x)
{
    return prefix[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    sieve();
	ll t;
	cin>>t;
	while(t--)
	{
	    ll x, y; cin>>x>>y;
        if(count_primes(x) > y) cout<<"Divyam"<<"\n";
        else cout<<"Chef"<<"\n";    
	}
	return 0;
}

