#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define endl "\n"
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define countsetb(n) __builtin_popcount(n)

int cnt = 0;
bitset<20> board[20];

bool canPlace(int i,int j,int n){
	if(i-2>=0 && j-1 >=0 && board[i-2][j-1]) return 0;
	if(i-2>=0 && j+1 <n && board[i-2][j+1]) return 0;
	if(i-1>=0 && j-2 >=0 && board[i-1][j-2]) return 0;
	if(i-1>=0 && j+2<n && board[i-1][j+2]) return 0;
	return 1;
}

void display(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void func(int n,int cr,int cc,int num){
	if(num==n){
		cnt++;
//		display(n);
		return ;
	}
	
	for(int i=cr;i<n;i++){
		for(int j = (i==cr)?cc:0;j<n;j++){
			if(canPlace(i,j,n)){
				board[i][j] = 1;
				
				func(n,i,j+1,num+1);
				
				board[i][j] = 0;
			}
		}
	}		
	return ;	
}

int main(){
	fast_io;

	int n;
	cin>>n;
	
	func(n,0,0,0);
//	cout<<cnt<<endl;

	return 0;
}


