#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[3], b[3];

int main() 
{
    REP(i, 3) scanf("%d", a + i);
    REP(i, 3) scanf("%d", b + i);
    int x = 0, y = 0;
    REP(i, 3) if (a[i] > b[i]) 
    {
        ++x;
    } else if (a[i] < b[i]) 
    {
        ++y;
    }
    printf("%d %d\n", x, y);
    return 0;
}
