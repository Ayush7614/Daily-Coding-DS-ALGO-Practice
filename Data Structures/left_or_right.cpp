//     Left Or Right

// Link of the problem:- https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/left-or-right-92c0b54c/

// A country X consists of N cities numbered 0 through N−1. The map of this country can be represented as a cycle — for each valid i, city i has exactly two neighboring cities (i+1)%N and (i−1+N)%N.
// The cities in the country are broadly categorized into different types. For each valid i, the type of city i is denoted by Ai.
// A person called Suarez wants to travel between some pairs of the cities. You are given Q queries. In each query, Suarez wants to travel from city number Y to a city of type Z. Also, he wants to travel only in a given direction along the cycle.
// The direction is represented by a letter — L or R. If it's L, Suarez may only move from city i to city (i−1+N)%N for each valid i. If it's R, he may only move from city i to city (i+1)%N.
// You need to find the minimum number of steps Suarez needs to take to reach a city of type Z if he starts moving from city Y in the given direction (he can take zero steps). In one step, Suarez can move from his current city to a neighboring city.
// If Suarez can never reach a city of type Z for a given query, print 1 instead.

// Sample Input
// 3 4
// 1 2 3
// 0 1 L
// 1 3 L
// 2 1 R
// 1 5 L

// Sample Output
// 0
// 2
// 1
// -1

// Explanation:
// For the first query, Suarez is already standing in a city of the required type, hence 0 steps taken.

// For the second query, Suarez will take the path 1 -> 0 -> 2, hence 2 steps taken.

// For the third query, Suarez will take the path 2 -> 0, hence 1 step taken.

// For the fourth query, there is no city of type 5, so the answer is 1.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	while(q--)
	{
		int start,destno;
		char dir;
		int ans=0;
        cin>>start>>destno>>dir;
        bool found=false;

        if(arr[start]==destno)      //in case of 0 1 L
        {
            ans=0;
            found=true;
        }
        else if(dir=='L')          //in case of 1 3 L 
        {
            int i;
            for(i=start-1;i>=0;i--)     //i becomes 0
            {
                ans++;                  //ans becomes 1
                if(arr[i]==destno)      //arr[0]=1 which is not equal to destno(3)
                {
                    found=true;
                    break;
                }
            }
            i++;                    //i=0
            if((i==0) && found==false)      //which is true
            {
                for(int i=n-1;i>=start+1;i--)       //n=3, i=2, start=1, i>=2
                {
                    ans++;                  //ans becomes 2
                    if(arr[i]==destno)      //arr[2]=3 which is equal to destno(3)
                    {
                        found=true;
                        break;
                    }
                }
            }
        }

        else if(dir=='R')           //in case of 2 1 R
        {
           int i;
            for(i=start+1;i<=n-1;i++)       //i=3, i<=2
            {
                ans++;
                if(arr[i]==destno)
                {
                    found=true;
                    break;
                }
            }
            i--; 
            if((i==n-1) && (found==false))
            {
                for(i=0;i<=start-1;i++)
                {
                    ans++;
                    if(arr[i]==destno)
                    {
                        found=true;
                        break;
                    }
                }
            }
        }
        if(found==true)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
	}
    
    return 0;
}

