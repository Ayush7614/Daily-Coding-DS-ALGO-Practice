//Link to problem :
// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1

/*Algorithm:
We will sort array and will make two numbers nearly of equal length by making num1 from all digits at even position 
and num2 from  all digits at odd position (num1 and num2 are the minimum possible number that can be formed) in string form
then add both string and return it as ans.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:

    //Funtion for addition of two strings
    string findSum(string str1, string str2)
    {
        if(str1.length()>str2.length())
            swap(str1, str2);
 
        string str = ""; //storing ans
 
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
 
        
        int carry = 0;//taking carry as 0
 
        for (int i=n1-1; i>=0; i--) // Traverse from end of both strings
        {
        
            int sum = ((str1[i]-'0') +(str2[i+diff]-'0') + carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
 
        // Adding remaining digits of str2[]
        for (int i=n2-n1-1; i>=0; i--)
        {
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
 
        // Add remaining carry
        if (carry)
            str.push_back(carry+'0');
 
        // reverse resultant string
        reverse(str.begin(), str.end());
 
        return str;
    }

    //Function to solve Minimum sum
    string solve(int arr[], int n) 
    {
        
        sort(arr,arr+n); //sorting
        string num1,num2;
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                if(arr[i]==0 && num1.length()==0) //if any leading 0 ,we will discard it
                        continue;
                num1+=to_string(arr[i]);
                
            }
            else
            {
                 if(arr[i]==0 && num1.length()==0) //if any leading 0 ,we will discard it
                        continue;
                num2+=to_string(arr[i]);
                
                
            }
        }
        
        return findSum(num1,num2);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

/*
Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.
*/