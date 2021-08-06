/* 
Description : Variable Sized Arrays
Consider an n-element array, a , where each index i in the array contains a reference to an array of k(i) integers.
Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and j denotes an index in the array located at a[i] .
For each query, find and print the value of element j in the array at location a[i] on a new line.
Input Format :
The first line contains two space-separated integers denoting the respective values of n (the number of variable-length arrays) and q (the number of queries).
Each line i of the n subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i] .
Each of the q subsequent lines contains two space-separated integers describing the respective values of i (an index in array a) and j (an index in the array referenced by a[i]) 
for a query.
Constraints : 
1<= n <= 10^5
1<= q <= 10^5
1<= k <= 3* 10^5
n<= E k <= 3* 10^5
0<= i < n
0<= j < k
All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than 10^6
Output Format : 
For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located at index j of the array referenced by a[i]. 
There should be a total of q lines of output.
Sample Input : 
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
Sample Output : 
5
9
Explanation : 
We perform the following q=2 queries:
Find the array located at index i=0, which corresponds to a[0] = [1,5,4]. We must print the value at index j=1 of this array which, as you can see, is 5 .
Find the array located at index i=1, which corresponds to a[1] = [1,2,8,9,3] . We must print the value at index j=3 of this array which, as you can see, is 9 .
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j,n,q;
    cin>>n>>q;
    int** A = new int*[n];
    for(i=0;i<n;i++)
    { int k;
        cin>>k;
       A[i] = new int[k];
      for(j=0;j<k;j++)
      {cin>>A[i][j];}
    }
    int Arr[q];
    for(int a=0;a<q;a++)
    { cin>>i>>j;
      Arr[a]=A[i][j];
    }
    for(int a=0;a<q;a++)
    {cout<<Arr[a];
     cout<<endl;
    }
    return 0;
}

/*
Test Case-1 : 
Input:
10 10
3 916135 272188 794963
3 178997 502468 671251
1 122266
3 223511 996043 990104
3 319694 335208 200789
2 867809 273793
1 925358
1 71140
1 862238
1 994309
6 0
5 0
5 0
7 0
5 0
6 0
3 2
3 1
0 0
9 0
Output: 
925358
867809
867809
71140
867809
925358
990104
996043
916135
994309
*/
