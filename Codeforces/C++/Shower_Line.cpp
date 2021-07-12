//65 Shower Line
// Probel Code - 431 - B

/*

Test Cases :
First Test Case :
# input
0 0 0 0 9
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
7 0 0 0 0
# output
32

Second Test Case :
# input
0 43 21 18 2
3 0 21 11 65
5 2 0 1 4
54 62 12 0 99
87 64 81 33 0
# output
620
*/



#include<bits/stdc++.h>
using namespace std;
long long int max1 = INT_MIN; //variable defined to store the maximum value of happiness
// function defined to get all the permutation of starting string
void permute(string a, int l, int r, long long int g[][5]) 
{ 
	if (l == r) 
    {
    	vector<int > v;
    	for(int i=0;i<5;i++)
    	{
    		//cout<<a[i]-48<<" ";
    		v.push_back(a[i]-49);
		}
		//cout<<endl;
		// calculating the happiness for each string permutatin
		long long int x1 = (g[v[0]][v[1]] + g[v[1]][v[0]] + g[v[2]][v[3]] + g[v[3]][v[2]]) + (g[v[1]][v[2]] + g[v[2]][v[1]] + g[v[3]][v[4]] + g[v[4]][v[3]]) + (g[v[2]][v[3]] + g[v[3]][v[2]]) + (g[v[3]][v[4]] + g[v[4]][v[3]]);                         
    	max1 = max(max1,x1); // ans updating the max happiness value
	}
  		
	else
	{ 
		for (int i = l; i <= r; i++) 
		{ 
			swap(a[l], a[i]); 
			permute(a, l+1, r,g); 
			swap(a[l], a[i]); 
		} 
	} 
} 
int main()
{
	ios::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// first we consider starting string as "12345"
	string str = "12345";
	// taken input for 5x5 matrix
    long long int g[5][5];
    for(int i=0;i<5;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		cin>>g[i][j];
		}
	}
	// now we consider all the permutation of that string, and check for the maximumn value of happiness for all string, and will return the maximum value
	permute(str, 0, 4,g);
	cout<<max1;
    return 0;
}
