/*
Problem Statement:
Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police.
Keep in mind the following conditions :

  1. Each policeman can catch only one thief.
  2. A policeman cannot catch a thief who is more than K units away from him.

Problem Link:
https://practice.geeksforgeeks.org/problems/e47329920b4e75869ea7b0e9b7c59ea145ccc22c/1

Logic:
1. Create two array p[n] and t[n] and four int variable pindex=0,tindex=0,count=0 and i=0
2. While i is less than n(size) run the loop
3. Check whether arr[i] == 'P'(Police) if yes then p[pindex]=i; and pindex++
4. If the 3th step didn't run then t[tindex]=i; and tindex++
5. Run the step 3 and 4 till i<n
6. Now create a variable j=0 and assign i=0
7: Run the loop till i<pindex and j<tindex
8: If p[i]>t[j] && p[i]-t[j]<=k then i++ and j++ and count++
9: If t[j]>p[i] && t[j]-p[i]<=k then i++ and j++ and count++
10: else p[i]>t[j] j++ else i++
11: return the count
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /*
    This function find the number of thieve can be catch by police
    Takes 3 argument arr[],n(size),k(range)
    returns int(count)
    The Logic had been discussed above
    */
    int catchThieves(char arr[], int n, int k) {
      int p[n], t[n];
      int i, count = 0, pindex = 0, tindex = 0;
      for (i = 0; i < n; i++) {
        if (arr[i] == 'P') {
          p[pindex] = i;
          pindex++;
        } else {
          t[tindex] = i;
          tindex++;
        }
      }
      int j = 0;
      i = 0;
      while (i < pindex && j < tindex) {
        if (p[i] > t[j] && p[i] - t[j] <= k) {
          i++;
          j++;
          count++;
        } else if (t[j] > p[i] && t[j] - p[i] <= k) {
          count++;
          i++;
          j++;
        } else {
          if (p[i] > t[j])
            j++;
          else
            i++;
        }
      }
      return count;
    }
};
// Driver code
int main() {
  int t;
  //taking the number of test case in t
  cin >> t;
  while (t--) {
    int n, k;
    // taking the size and range in n and k respectively
    cin >> n >> k;
    char arr[n];
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    Solution obj;
    cout << obj.catchThieves(arr, n, k) << endl;
  }
  return 0;
}
/*
Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2
Explanation: Maximum 2 thieves can be
caught. First policeman catches first thief
and second police man can catch either second
or third thief.

Time  Complexity: O(N)
Space Complexity: O(N)
*/
