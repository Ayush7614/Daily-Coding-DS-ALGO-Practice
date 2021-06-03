#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int r,o,c;
	cin>>r>>o>>c;
	int extraScore = (20-o) * 6 * 6;
	if((extraScore + c) > r)
	    cout<<"YES"<<endl;
	else
	    cout<<"NO"<<endl;
	return 0;
}
