//Given two strings s1 and s2 and we have to find the length of shortest supersequence consisting of both s1 and and s2.
//Shortest Common Supersequence finds the shortest supersequence which consist of all the characters of both the string in the order specified. 
//Supersequence have the same relative order but may or may not be continuous.
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

//Test Case:
/*
INPUT:
Enter first String:		geek
Enter second String:	eke
OUTPUT:
5
*/
