#include<bits/stdc++.h>
using namespace std;
// Function to find majority element in the array
// a: input array
// size: size of input array
 int majorityElement(int a[], int size)
{
    // using unordered map
    unordered_map<int,int> mp;
    int res=-1;
    for(int i=0;i<size;i++){
        mp[a[i]]++;
        if(mp[a[i]] > size/2){
            res=a[i];
            break;
        }
    }
    return res;   
}
int main(){
    int t;
    cin >> t;
    while(t--){
        //taking input from the user 
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  //second method 
  
     
//    int majorityelement(int a[], int size) 
//     { 
//         int maj_index = 0, count = 1; 
        
//         // use linear search to compute candidate for majority element
//         for (int i = 1; i < size; i++) 
//         { 
            // if (a[maj_index] == a[i]) 
//                 count++; 
//             else
//                 count--; 
//             if (count == 0) 
//             { 
//                 maj_index = i; 
//                 count = 1; 
//             } 
//         } 
//         return a[maj_index]; 
//     }  
//     /* Function to check if the candidate 
//        occurs more than n/2 times */
//     bool isMajority(int a[], int size, int cand) 
//     { 
//         int count = 0; 
//         for (int i = 0; i < size; i++) 
//             if (a[i] == cand) 
//                 count++; 
              
//         if (count > size/2) 
//             return 1;          
//         else
//             return 0; 
//     }   
//     /* Function to print Majority Element */
//     int majorityElement(int a[], int size)
//     {
//         /* Find the candidate for Majority*/
//        int cand = findCandidate(a, size); 
      
//        /* Print the candidate if it is Majority*/
//         if (isMajority(a, size, cand)) 
//             return cand;
//         else
//             return -1;
//     }
// };

//Test Cases :-
// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.


// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.
