
#include <iostream>
using namespace std;

int main() {
	// your code goes here
		int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	  
	   long long int len=n-1;
	    string eor;
	    cin>>eor;
	    for(int i=1; i<n; i++)
        len+=eor[i]==eor[i-1]?1:0;
	    
	    while(k--){
	        int l;
            cin>>l;
            l--;
	        if(eor[l]=='0')
            eor[l]='1';
	        else
             eor[l]='0';
	        if(l<n-1){
	            if(eor[l]==eor[l+1])
                len++;
	            else 
                len--;
	        }
	        if(l>0){
	            if(eor[l]==eor[l-1])
                len++;
	            else 
                len--;
	        }
	        cout<<len<<"\n";
	    }
	}
	return 0;
}
