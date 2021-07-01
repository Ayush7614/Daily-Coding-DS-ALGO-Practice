
/*Algorithm: We will use Sliding window technique(i and j pointers). We will keep storing the negative numbers in a queue and 
when we will arrive to the condition such that size of window (j-i+1) is equal to k then we will check that whether queue is empty or not.
If queue will be empty means there is no negative number in that window( store  0 in answer vector)
If the first element of queue is also the first element of that window then we will dequeue that element (store that element in answer vector)
else will directly store the first element of queue in answer and increment i and j for next window.
*/

#include<bits/stdc++.h>

using namespace std;

vector<long long>printFirstNegativeInteger(long long a[],long long n, long long k);

int main()
{
    long long n,k,i;
    cin>>n;
    long long a[n];

    for(i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    vector<long long>ans=printFirstNegativeInteger(a,n,k);

    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}




// Function to return solution
vector<long long>printFirstNegativeInteger(long long a[],long long n, long long k)
{
    queue<long long>q;
    vector<long long>v;
    
    long long i=0,j=0;
                                                 
    while(j<n)
    {
        if(a[j]<0)
            q.push(a[j]); // pushing negative number in queue
                                                        
        if(j-i+1<k)
            j++; // Current size is not the size of window
        else
        {
            if(j-i+1==k)
            {
                if(q.size()==0) // Queue is empty
                    v.push_back(0);
                                                                     
                else
                {
                    if(q.front()==a[i]) // Front element of queue and current window is same
                    {
                        v.push_back(q.front());
                        q.pop(); // Dequeue the first element
                                                                
                    }
                    else
                        v.push_back(q.front()); // Front element of queue and current window is not same
                                                                 
                                                                    
                                                                    
                }
                                                              
            }
                                                             
            i++;
            j++;
        }   
                                                            
                                                    
    }  

    return v; 

}
                                    
/*

Input :
n= 5
a[]= 3,6,7,-45,-8
k=3

Output :
0, -45, -45

*/                                
                                               
                                                