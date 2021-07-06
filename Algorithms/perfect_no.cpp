/*

CODE DESCRIPTION: 
A number is a perfect number if is equal to sum of its proper divisors i.e., 
sum of its positive divisors excluding the number itself.

We need to find maximum number of Perfect Numbers present in a subarray of size K

EXAMPLE:
Input: arr[ ] = {28, 2, 3, 6, 496, 99, 8128, 24}, K = 4
Output: 3
Explanation: The sub-array {6, 496, 99, 8128} has 3 perfect numbers which is maximum.


APPROACH:
i) We traverse a loop for array and maintain a subarray counter upto size k(given size of subarray)
ii) For each element we check whether it is perfect no. or not
iii) If element is Perfect no. we increment the counter by 1
iv) If subarray counter become equal to k ->
    - we update maxCount value if it is less than count
    - now, we apply sliding window concept i.e, 
        if element at index i-(x-1) is Perfect decrement the value of count by 1
        else value of count remain unchange 
v) At last we print the value of maxCount which indicates maximum number of Perfect Numbers present in a subarray of size K

*/

#include<iostream>
using namespace std;

/* function which returns true if particular element is Perfect number */
bool isPerfect(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
            sum+=i;
    }
    if(n==sum)
    return true;
    else
    return false;
}

int maxPer(int a[],int n,int k){
    /* max is maximum number of count, count is no. of perfect number elements & x is subarray counter */
    int maxCount=0,count=0,x=1; 

    /* loop from i=0 to i=(size of array - 1) */
    for(int i=0;i<n;i++){

        /* if a[i] is Perfect increment count by 1 */    
        if(isPerfect(a[i]))
            count++;
            
        /* if subarray counter become equal to size of subarray */
        if(x==k){

            /* if value of max is less than count update max */
            if(maxCount<count)
                maxCount=count;
            
            /* here we use sliding window concept ->
                if element at index i-(x-1) is Perfect decrement the value of count by 1 */ 
            if(isPerfect(a[i-(x-1)]))
                count--;
            
            /* update value of subarray counter agin by 1 */
            x=1;
        }
        x++;    
    }
    cout<<"Total perfect numbers: "<<maxCount;
}

int main(){

    int i,n,k;

    /* ask user input */
    cout<<"Enter no. of elemnts in array: ";
    cin>>n;

    /* intialize an array of size n */
    int a[n];

    /* ask user input */
    cout<<"Enter array elements: ";
    for(i=0;i<n;i++)
    cin>>a[i];

    /* ask user input */
    cout<<"Enter subarray size: ";
    cin>>k;

    /* calling maxPer function */
    maxPer(a,n,k);
    return 0;
}

/*

Testcase 1:
Enter no. of elemnts in array: 8
Enter array elements: 28 2 3 6 496 99 8128 24
Enter subarray size: 4
Total perfect numbers: 3

Testcase 2:
Enter no. of elemnts in array: 4
Enter array elements: 1 2 3 6
Enter subarray size: 2
Total perfect numbers: 1

*/
