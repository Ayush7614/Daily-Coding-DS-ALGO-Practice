#include <bits/stdc++.h>

using namespace std;




int max(int a, int b) { return (a > b) ? a : b; }




int knapSack(int maxweight,int[] weight,int[] value,int n)
{
	int storage[n+1][maxweight+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=maxweight;j++)
		{
			//base case
			if (i==0 || j==0) 
                             storage[i][w] = 0;
			else if(weight[i-1]>maxweight)
		               storage[i][j]=storage[i-1][j];
			else
				storage[i][j]=max(storage[i-1][j],storage[i-1][j-weight[i-1]]+value[i-1];
		}
	}
	
	return storage[n][maxweight];					  
						  

}




int main()

{
	
   int val[] = { 60, 100, 120 };

   int wt[] = { 10, 20, 30 };
   int W = 50;
	
   
   int n = sizeof(val) / sizeof(val[0]);
	
  
   cout << knapSack(W, wt, val, n);
	
   return 0;

}



