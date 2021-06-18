#include<bits/stdc++.h>

using namespace std;

int LCS(string X, string Y,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++){
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
		
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if (X[i - 1] == Y[j - 1])
				t[i][j] = 1+t[i - 1][j - 1];
			else
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
		}
	return t[m][n];
}

int CalcSCSLength(string X,string Y){
	int m=X.size(),n=Y.size();
	int l = m + n - LCS(X,Y,m,n);
	return l;
}

int main(){
	string X,Y;
	cout<<"Enter first String:\t";
	cin>>X;
	cout<<"\nEnter second String:\t";
	cin>>Y;
	cout<<CalcSCSLength(X,Y);
	return 0;
}
