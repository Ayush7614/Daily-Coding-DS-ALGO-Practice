// Binomial cofficient problem of Dynamic Programming

int nCrModp(int n, int r, int p)
{
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; 
 
    
    for (int i = 1; i <= n; i++)
    {
        
        for (int j = min(i, r); j > 0; j--)
 
           
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
int main()
 {
 int t;
 cin>>t;
 while(t--)
 {
     int n,r;
     cin>>n>>r;
     /*if(r>n)
     {
         cout<<"0\n";
     }*/
     int p=1000000007;
     cout<<nCrModp(n,r,p)<<" \n";
 }
	//code
	return 0;
}
