#include <bits/stdc++.h>
using namespace std;
int score[2]={0,0};

void comparison()
{
    int a[3];
    int b[3];
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i]>b[i])
        {
            score[0]++;
        }
        else if(b[i]>a[i])
        {
            score[1]++;
        }
        else if(a[i]==b[i])
        {
            continue;
        }
    }
    
}

int main() {
	
    comparison();
    cout<<score[0]<<" "<<score[1];
    
	return 0;
}
