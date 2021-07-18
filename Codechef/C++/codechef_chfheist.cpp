#include <iostream>
#include<bits/stdc++.h>

using namespace std;

long long int sum(int a,int b,int c,int d){
    int r=a/b;
    int q=a%b;
    long long int s=((r*c)+(r*d*(r-1)/2))*b+(c+(r*d))*q;
    return s;
}
int main() {
    
	int t;
	std::cin>>t;
	while(t--){
	    int D,d,p,q;
	    std::cin>>D>>d>>p>>q;
	    std::cout<<sum(D,d,p,q)<<"\n";
	}
	return 0;
}