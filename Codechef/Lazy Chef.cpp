#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int x, m, d;
        cin>>x>>m>>d;
        cout<<min(m*x , x+d)<<endl;
    }
    
    return 0;
	}
	
//sample input
	3
1 1 0
1 3 1
2 2 3

// sample output
1
2
4

	    

