#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack> 
using namespace std; 
int a[100005],b[100005],flag[100005];
int main()
{
    int n;scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] % 2 == 0)
            b[i] = a[i] / 2;
        else
        {
            b[i] = a[i] / 2;
            flag[i] = 1;
        }
    }
    int tmp = 0;
    for(int i = 1;i <= n;i++)
    {
        tmp += b[i];
    }
    
    if(tmp <= 0)
        for(int i = 1;i <= n && tmp <= -1;i++)
        {
            if(flag[i] && b[i] > 0)
                b[i]++,tmp++;
            else if(a[i] == 1)
                b[i]++,tmp++;
        }
    else if(tmp > 0)
        for(int i = 1;i <= n && tmp >= 1;i++)
        {
            if(flag[i] && b[i] < 0)
                b[i]--,tmp--;
            else if(a[i] == -1)
                b[i]--,tmp--;
        } 
    for(int i = 1;i <= n;i++)printf("%d\n",b[i]);
    return 0;
}