// 			HackerEarth Problem
// 			Grid And Phrase
// Link of the problem: https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/jadvaliioo-62280ff6/

// You are given an n*m grid which contains lower case English letters. How many times does the phrase "saba" appear horizontally, vertically, and diagonally in the grid?

// Sample Input
// 5 5
// safer
// amjad
// babol
// aaron
// songs

// Sample Output
// 2

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	char a[n+1][m+1];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	int count=0;
	
	//horizontally
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(j<m)
		{
			if(a[i][j]=='s' && j+3<m)
			{
				int ch1=a[i][j+1];
				int ch2=a[i][j+2];
				int ch3=a[i][j+3];
				
				if(ch1=='a' && ch2=='b' && ch3=='a')
				{
					count++;
					j+=4;
					continue;
				}
			}
			j++;
		}
	}

	//vertically
	for(int j=0;j<m;j++)
	{
		int i=0;
		while(i<n)
		{
			if(a[i][j]=='s' && i+3<n)
			{
				int ch1=a[i+1][j];
				int ch2=a[i+2][j];
				int ch3=a[i+3][j];
				if(ch1=='a' && ch2=='b' && ch3=='a')
				{
					count++;
					i+=4;
					continue;
				}
			}
			i++;
		}	
	}

	//diagonally
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='s')
			{
				//for top to bottom
				if(i+3<n && j+3<m)
				{
					int ch1=a[i+1][j+1];
					int ch2=a[i+2][j+2];
					int ch3=a[i+3][j+3];
					if(ch1=='a' && ch2=='b' && ch3=='a')
					{
						count++;
					}
				}
				//for bottom to top
				if(i-3>=0 && j-3<m)
				{
					int ch1=a[i-1][j+1];
					int ch2=a[i-2][j+2];
					int ch3=a[i-3][j+3];
					if(ch1=='a' && ch2=='b' && ch3=='a')
					{
						count++;
					}
				}
			}
		}
	}

	cout<<count;
	return 0;
}

// Explaination:- First we input a 2D Matrix using characters. Now we had check if "saba" is present horizontally, vertically or diagonally. We stored each variable using 
// ch1,ch2 and ch3. Using if condition we checked, if it is true the we inc count by 1.