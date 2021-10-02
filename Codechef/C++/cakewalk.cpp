#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	long long N;
	cin>>T;


	for(int i=0;i<T;i++){
		cin>>N;
		if(N%10!=0||N%20!=0){
			cout<<"No"<<endl;
		}	
		else{
			long long c=0,c1=0;
			while(N%10==0){
				N=N/10;
				c++;
			}
			while(N%2==0){
				N=N/2;
				c1++;
			}
			if(c1<=c&&N==1){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
			
			
		
	}
	
	return 0;
}
