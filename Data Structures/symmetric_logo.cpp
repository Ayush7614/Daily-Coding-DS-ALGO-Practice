//     Roy and Symmetric Logos

// Link of the problem: https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/roy-and-symmetric-logos-1/

// Roy likes Symmetric Logos.
// How to check whether a logo is symmetric?
// Align the center of logo with the origin of Cartesian plane. Now if the colored pixels of the logo are symmetric about both X-axis and Y-axis, then the logo is symmetric.
// You are given a binary matrix of size N x N which represents the pixels of a logo.
// 1 indicates that the pixel is colored and 0 indicates no color.

// For instance: Take a 5x5 matrix as follows:
// 01110
// 01010
// 10001
// 01010
// 01110
// This is Symmetric

// Let's take another example of 5x5 matrix:
// 00100                       
// 01010                        
// 10001                        
// 01010                        
// 01110                        
// This is non-symmetric

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}

		int centre=0;       //center is the x and y axis
		if(n%2==0)		//even
		{
			centre=(n-1)/2;
		}
		else            //odd
		{
			centre=n/2;
		}

        int i=0;
        int j=0;
        for(i=0;i<=centre;i++)
        {
            for(j=0;j<=centre;j++)
            {
                if((a[i][j]==a[n-1-i][j]) && (a[i][j]==a[i][n-1-j]) && (a[i][j]==a[n-1-i][n-1-j]))
                {
                    continue;
                }
                else
                {
                    i=centre+5;     //so that it breaks i loop also
                    break;         //only breaks j loop not i
                }
            }
        }

        if(i==centre+6)         //center+6 because after exiting i loop will be inc by 1
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
        }
		cout<<endl;
	}
    
}

// Explaination:- In this solution we had compared 1st and last elements
