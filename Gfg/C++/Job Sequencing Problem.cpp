// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a , Job b)
    {
        return (a.profit>b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      //sorting in descending 
        sort(arr,arr+n,comp);
      //taking array of done so that we can track how much job is completed
        bool done[n]={0};
        int day=0;
        int profit=0;
      //traversing through the elements
        for(int i=0;i<n;i++)
        {
          //traversing through the deadline so that we can allow the job which has the nearest deadline
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j]==false)
                {
                    day=day+1;
                    profit+=arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
      //last returning day and profit 
        return {day,profit};
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends


// Test cases 
// Example 1:

// Input:
// N = 4
// Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
// Output:
// 2 60
// Explanation:
// 2 jobs can be done with
// maximum profit of 60 (20+40).
// Example 2:

// Input:
// N = 5
// Jobs = (1,2,100)(2,1,19)(3,2,27)
// (4,1,25)(5,1,15)
// Output:
// 2 127
// Explanation:
// 2 jobs can be done with
// maximum profit of 127 (100+27).
