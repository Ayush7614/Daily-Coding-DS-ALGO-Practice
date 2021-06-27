#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;

    while(T)
    {
        int N;
        cin>>N;
        
        int even[N],odd[N];
        int e=0,o=0;
        
        for(int i=0;i<N;i++)
        {
            int A;
            cin>>A;
            
            if(A%2==0)
            {
                even[e]=A;
                e++;
            }
            else
            {
                odd[o]=A;
                o++;
            }
        }
        
        for(int i=0;i<e;i++)
            cout<<even[i]<<" ";
        for(int i=0;i<o;i++)
            cout<<odd[i]<<" ";
        cout<<endl;

        T--;
    }

    return 0;
}
