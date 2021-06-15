#include<iostream>

using namespace std;

maxProfit(int length[],int price[],int n,int L){
	int t[n + 1][L + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= L; j++)
			if (j == 0 || i == 0)
				t[i][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L; j++) {
			if (length[i - 1] <= j) {
				t[i][j] = max(t[i - 1][j],
				               price[i - 1] + t[i][j - length[i - 1]]);
			}
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][L];
}

int main(){
	int n;
	cout<<"Enter the number of pieces:\t"<<endl;
	cin>>n;
	int length[n], price[n];
	cout<<"Enter length and price:\t"<<endl;
	for(int i=0;i<n;i++){
		cin>>length[i]>>price[i];
	}
	int L=n;//total length=number of pieces
	cout<<maxProfit(length,price,n,L);
}
