/*Link to probelm:
https://practice.geeksforgeeks.org/problems/word-wrap1646/1

*/

/*Algorithm:
We will implement it with DP.The idea is to use two 1-D arrays dp[] and ans[], where dp[i] represents minimum cost of the line 
in which a[i] is the first word and ans[i] represents index of last word present in line in which word arr[i] is
 the first word.Suppose for any line l the first word in that line is at index i in a[]. The minimum cost of that line is 
 stored in dp[i]. The last word in that line is at index j in a[].We will iterate over all values of j and keep track of number 
 of characters added so far in line l. If number of characters are less than k then find cost of current line with these 
 number of characters then compare this cost with minimum cost find so far for this line in dp[i] and update dp[i] 
 and ans[i] accordingly. We will repeat it for i(1 <= i <= n). The starting and ending words of each line will be at
index i and index ans[i], where next value of i for line l+1 is ans[i] + 1.
*/


#include<bits/stdc++.h>

using namespace std;



  int solveWordWrap(vector<int>a, int k) 
    { 
        int n = a.size();
        int i, j;
        int currlen; //store number of characters in given line
        int cost; //store possible minimum cost of line.
        
        vector<int>dp(n, 0);
        vector<int>ans(n, 0);
        
        dp[n-1]=0;
        ans[n-1]=n-1;
        for (i=n-2;i>=0;i--) 
        {
            currlen=-1;
            dp[i]=INT_MAX;
            for (j=i;j<n;j++) //adding words in current line by iterating
            {
                currlen+=(a[j] + 1); //updating number of characters
                if (currlen > k) //if no more characters are added
                    break;
                if (j==n-1) //word ended at last line
                    cost=0;
                else
                    cost=(k-currlen)*(k-currlen)+dp[j+1]; //calculating ans
                if (cost < dp[i])  //if arrangement gives minimum 
                {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        int r=0;
        i=0;
        while (i<n) 
        {
            int p=0;
            for (int j=i;j<ans[i]+1;j++) 
            {
                p+=a[j];
            }
            int x=ans[i]-i;
            if(ans[i]+1 !=a.size())
                r+= (k-x-p)*(k-x-p); //calculating output
            i = ans[i]+1;
        }
        return r;
    }



int main()
{
    int n,i,k;
    cin>>n;
    vector<int>a(n);

    for(i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    int ans=solveWordWrap(a,k);

    cout<<ans;

    return 0;
   
}