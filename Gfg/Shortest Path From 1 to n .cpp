//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
      //Intitialising ans to 0
        int ans=0;
      //iterate the loop
       while(n>1){
         //if the no is dividible by 3 and divides by three.
           if(n%3==0){
                n=n/3;
            }
         //if not than number will be substrcated from n
            else{
            n=n-1;
            }
         //increment the ans
          ans++;
}
      //return the ans.
return ans;
}
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 

  // } Driver Code Ends

//Test Case

// Example 1:

// Input:
// N = 9
// Output:
// 2
// Explanation:
// 9 -> 3 -> 1, so
// number of steps are 2. 
// â€‹Example 2:

// Input:
// N = 4
// Output:
// 2
// Explanation:
// 4 -> 3 -> 1, so
// number of steps are 2.
