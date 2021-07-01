// Orderly Queue
// A string s of lowercase letters is given.  Then, we may make any number of moves.

// In each move, we choose one of the first k letters (starting from the left), remove it, and place it at the end of the string.

// Return the lexicographically smallest string we could have after any number of moves.

// Example 1:

// Input: s = "cba", k = 1
// Output: "acb"
// Explanation: 
// In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
// In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".

// Example 2:

// Input: s = "baaca", k = 3
// Output: "aaabc"
// Explanation: 
// In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
// In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".

// Note:

// 1 <= k <= s.length <= 1000
// s consists of lowercase letters only.


// Orderly Queue Solution -
// First, Let us consider k = 1.
// Given k=1, We now remove 1st k charecters and put them at the end of the string.

// By doing this we are rotating the string.
// When we repeat this process we will be generating rotated strings.

// As we have taken k=1, We rotate the string over and over again untill we get our original charecter back.
// After each move we put the rotated string into a vector of string.

// After getting all rotated strings, we then sort the vector.

// String at index 0 will be our required string.

// But if k>1
// We will be able to generate all the permutations of the string.
// Then we will return the smallest string. We can sort the string and also return it.


#include <bits/stdc++.h>
using namespace std;

// Function to find rotated strings
// by removing charecters

    string orderlyQueue(string S, int K) {
        int n = S.length();
        
        if(n == 0){
            return "";
        }
        
        if(K > 1){
            sort(S.begin(),S.end());
            return S;
        }
        
        vector<string> res;
        
        for(int i=0;i<n;i++){
            
            char temp = S[0];
            S.erase(S.begin());
            S += temp;
            res.push_back(S);
            
        }
        
        sort(res.begin(),res.end());
        
        return res[0];
    }

    // Driver Code

    int main()
    {
        int k;
        string s;
        cin>>s;
        cin>>k;
    
        cout << newString(s, k);
    }




















