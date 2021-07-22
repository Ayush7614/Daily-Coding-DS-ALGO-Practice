#include <iostream>  
using namespace std;  
int main()  
{  
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a=n;
    int w=a%10;
    if(w==9)
    
    cout<<(n/10)+1<<'\n';
    else
    cout<<n/10<<'\n';
    }
return 0;  
}  