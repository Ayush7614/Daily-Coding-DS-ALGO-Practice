#include <iostream>
using namespace std;
int main() 
{
    int t;
    cin>>t;         //taking input for test cases 
    while(t--)
    {
        int s=1,n,i; 
        cin>>n;        // n denotes the number of cars
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];      // array hold the maximum speed of the cars in the order they entered the long straight segment
        for(i=0;i<(n-1);i++)
        {
            if(a[i]>a[i+1])
            s++;            // comparing adjacents cars if the speed of the car is more than the speed of car before it then s is incremented 
            else
            a[i+1]=a[i];
        }
        cout<<s<<endl;      // output answer 
    }
	return 0;
}
/*
Sample input/output

Input:
3
1
10
3
8 3 6
5
4 5 1 2 3

Output:
1
2
2
*/
