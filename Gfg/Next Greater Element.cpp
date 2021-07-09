/**

Problem Link : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

Approach:

1. Push the first element to stack.
2. Pick rest of the elements one by one and follow the following steps in loop. 
3. Mark the current element as next.
4. If stack is not empty, compare top element of stack with next.
5. If next is greater than the top element, Pop element from stack. next is the next greater element for the popped element.
6. Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
7. Finally, push the next in the stack.
8. After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.


Time Complexity: O(N) 
Auxiliary Space: O(N)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Solution
{
    
    public:

    vector<long long> nextLargerElement(vector<long long> a, lli n)
    {
        long long i;
        vector<long long> b;
        unordered_map<long long,long long> c;
        stack<long long> s;
        
        //push the first element to stack
        s.push(a[0]);
        
        // iterate for rest of the elements
        for(i=1;i<n;i++)
        {
            if(s.empty())
            {
                s.push(a[i]);
                continue;
            }
            
            /* if stack is not empty, then
            pop an element from stack.
            If the popped element is smaller
            than next, then
            a) add the pair in the map
            b) keep popping while elements are
            smaller and stack is not empty */

            while(!s.empty() && s.top()<a[i])
            {
                c[s.top()]=a[i];
                s.pop();
            }
                
            // push next to stack so that we can find next greater for it     
            s.push(a[i]);
                
        }
        
         /* After iterating over the loop, the remaining
            elements in stack do not have the next greater
            element, so add -1 for them in the map*/
    
        while (!s.empty()) 
        {
            c[s.top()]=-1;
            s.pop();
        }

        //push the elements from the map in a vector in correct order
        for(i=0;i<n;i++)
        {
            b.push_back(c[a[i]]);
        }
        
        return b;
    }
    
};

//Driver Code
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,i,x;
        cin>>n;
        vector<long long> a(n);
        
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        Solution obj;
        vector<long long> res= obj.nextLargerElement(a,n);
        
        for(long long i : res)
            cout<<i<<" ";
        
        cout<<"\n";
        
    }
    
    return 0;
}

/**

Sample Case

Input:

2
4 
1 3 2 4
5
6 8 0 1 3

Output:

3 4 4 -1
8 -1 1 3 -1

Test Case 1: In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.

Test Case 2: In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1 , for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.

*/

