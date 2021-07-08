/*

===========================================================================================
   
   The following code has been implemented using unordered map and priority queue 
  

===========================================================================================
*/
#include <iostream>

#include <vector>

#include <queue>

#include <unordered_map>

using namespace std;

vector<int> top(vector<int>& nums, int k) 
{
  
    vector <int> result;
    unordered_map<int, int> freq_map;

    for(size_t a = 0; a < nums.size(); ++a)
    {
        freq_map[nums[a]]++;    
        //increasing the stored frequency of the element by 1 
    }

    queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minimum_heap;

    for(auto it = freq_map.begin(); it != freq_map.end(); ++it)
    {
        min_heap.push({it->second, it->first});     
      
      //pushing the frequency and the element in pairs respectively then 
      
      if(min_heap.size() > k)
        {
            min_heap.pop();    
        
        }
    }

    for(size_t a = 0; a < k; a++)
    {
      
     // The unordered map is used for storing the frequency of each element
    
        int x = min_heap.top().second;    
       
      //getting the element from the top 
      
      result.push_back(x);    
      
      //let us now push the element into the new vector
      
      min_heap.pop();
    }
    return result;
}


int main()
{
    int k, n;
  
    cout << "Enter the size of array: ";
    cin >> n;
  
    cout << "Enter k: ";
  
    cin >> k;
  
    vector<int> nums(n);
    
  cout << "Enter elements in the array: ";
  
  for(size_t a = 0;a < n; ++a)
    
   // Time Complexity : O(k log d + d)
   // Space Complexity : O(d)
  {
  
    cin>>nums[a;
    
  }

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top "<< k << " Frequent elements: ";

    for(size_t a = 0;a < k; ++a)
    {
        cout << ans[a] << " ";
    }
    cout << "\n";
    return 0;
}

/*
===============================================================
output 
===============================================================

        Enter the size of array : 6
        Enter k : 2
        
        Enter elements in the array: 1 1 1 3 3 2
        Top 2 Frequent elements: 3 1
        
===============================================================

*/          
