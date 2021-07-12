/*
    issue: #1079
    Question:
    Starting with a 1-indexed array of zeros and a list of
    operations, for each operation add a value to each the
    array element between two given indices, inclusive. 
    Once all operations have been performed, return the 
    maximum value in the array.
    Example:
    n = 10
    queries = [[1, 5, 3], [4, 8, 7], [6, 9, 1]]
    Queries are interpreted as follows:
    a   b   k
    1   5   3
    4   8   7
    6   9   1
    add the values k between the indices a and b inclusive:
    index-> 1   2   3   4   5   6   7   8   9   10
           [0,  0,  0,  0,  0,  0,  0,  0,  0,  0]
    after
        Q1 [3,  3,  3,  3,  3,  0,  0,  0,  0,  0]
        Q2 [3,  3,  3,  10, 10, 7,  7,  7,  0,  0]
        Q3 [3,  3,  3,  10, 10, 8,  8,  8,  1, 0]
    * Function Description
    Complete the function arrayManipulation.
    arrayManipulation has the following parameters:

        * int n - the number of elements in the array
        * int queries[q][3] - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
    * Returns
        * int - the maximum value in the resultant array
*/
#include <bits/stdc++.h>

using namespace std;

long arrayManipulation(int n, int **queries, int qSize) {
    int a, b, k;
    long max = LONG_MIN, sum=0;
    long *arr = new long[n+1];
    for(int i=0; i<n+1; i++)
        arr[i] = 0;
    for(int i=0; i<qSize; i++)
    {
        a = queries[i][0];
        b = queries[i][1];
        k = queries[i][2];
        a--,b--;
        arr[a] += k;
        arr[b+1] -= k;
    }
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        max = (sum > max)? sum:max;
    }
    return max;
}

int main()
{
    int n, operations;
    cin>>n>>operations;
    int qSize = operations;
    int **queries;
    queries = new int*[qSize];
    for(int i=0; i<qSize; i++)
        queries[i] = new int[3];        
    int a, b, val;
    for(int i=0; i<qSize; i++)
    {
        cin>>a>>b>>val;
        queries[i][0] = a;
        queries[i][1] = b;
        queries[i][2] = val;
    }
    cout<<arrayManipulation(n, queries, qSize)<<'\n';
    return 0;
}