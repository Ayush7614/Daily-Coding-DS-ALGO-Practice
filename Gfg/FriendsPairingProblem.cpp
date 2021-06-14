/*Problem : FRIENDS PAIRING PROBLEM*/

/*Explanation of problem : Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.We have to find out the total number of ways in which friends can remain single or can be paired up.*/

/*The problem is simplified version of how many ways we can divide n elements into mutiple groups.
    (here group size will be max of 2 elements because a pair consists of two entities).

    Assume n = 3, we have only 2 ways to make a group: 
     a> all elements are individual(1,1,1)
     b> a pair and individual (2,1)
    Likewise, In case of n = 4, we have 3 ways to form a group:
     a> all elements are individual (1,1,1,1)
     b> 2 individuals and one pair (2,1,1)
     c> 2 separate pairs (2,2)
*/

#include <iostream>
using namespace std;

/* Function countfp Returns count of ways entered number of people can remain single or paired up.*/
int countfp(int n)
{
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        /*   For i-th person there are two choices:
      a> i-th person remains single, we recur 
     For f(i - 1)
      b> i-th person pairs up with any of the 
     remaining i - 1 persons. We get (i - 1) * f(i - 2)

    Therefore we can recursively write f(i) as:

         f(i) = f(i - 1) + (i - 1) * f(i - 2)
        where,f(i) = ways i people can remain single or pair up         
*/
        if (i <= 2)
            arr[i] = i;
        else
            arr[i] = arr[i - 1] + (i - 1) * arr[i - 2];
        /* Filling arr[] in bottom-up manner using recursive formula explained above.*/
    }

    return arr[n];
    /*returns element stored at nth position in array arr as the number of ways n people can be paired is stored at nth address in the lieu of OVERLAPPING PROBLEMS PROPERTY OF DYNAMIC PROGRAMMING */
}

/* Main function*/
int main()
{
    int n;                                          /*No. of persons*/
    cout << "Enter the total number of Persons : "; /*Asking user to inout value of n*/
    cin >> n;                                       /*Taking Input from User*/
    cout << "Total number of ways " << n << " persons can be paired up : " << countfp(n) << endl;
    /*Displaying the number of ways n people can be paired up*/
    return 0;
}
/*
   Time Complexity : O(n) 
   Space Complexity : O(n)

   OUTPUT :
   Enter the total number of Persons : 5
   Total number of ways 5 persons can be paired up : 26 
*/