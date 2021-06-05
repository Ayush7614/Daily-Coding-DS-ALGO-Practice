//May long Challenge Question.
//Question link:--->https://www.codechef.com/LTIME96B/problems/CHARGES
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define cin(arr,N)    for(int i=0;i<N;i++)cin>>arr[i]
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int N, K; cin >> N >> K;
        string s;  cin >> s;

        int arr[K]; cin(arr,K);

        if (N == 1){
            for (int i = 0; i < K; i++)
                cout << 0 << endl;
            continue;
        }
        ll d = 0;
        for (int i = 1; i < N; i++){
            if (s[i] == s[i - 1])
                d += 2;
            else
                d += 1;
        }
        for (int i = 0; i < K; i++){
            if (arr[i] == 1){
                if (s[0] == s[1])
                    d--;
                else
                    d++;
            }
            else if (arr[i] == N){
                if (s[N - 1] == s[N - 2])
                    d--;
                else
                    d++;
            }
            else{
                int t = 0;
                if (s[arr[i] - 1] == s[arr[i] - 2])
                    t = t + 2;
                if (s[arr[i] - 1] != s[arr[i] - 2])
                    t += 1;
                if (s[arr[i] - 1] != s[arr[i]])
                    t += 1;
                if (s[arr[i] - 1] == s[arr[i]])
                {
                    t++;
                    t++;
                }

                if (t == 4)
                    d = d - 2;
                if (t == 2)
                    d = d + 2;
            }
            if (s[arr[i] - 1] == '0')
                s[arr[i] - 1] = '1';
            else
                s[arr[i] - 1] = '0';
            cout << d << endl;
        }
    }
    return 0;
}
