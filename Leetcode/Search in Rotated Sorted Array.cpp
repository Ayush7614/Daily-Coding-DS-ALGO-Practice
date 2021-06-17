// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
    int search(vector<int> nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h){
            int m = l + (h - l)/2;
            if(nums[m] > target){
                if(nums[m] >= nums[l]){
                    // left half is sorted and acoding to upper condition target is smaller then mid and according to this target is larger then low so target must be in left half
                    if(target >= nums[l]){
                        h = m-1;
                    }else{
                        // left half is sorted but target is not in the left one so we will move to right half.
                        l = m+1;
                    }
                }else{ 
                    // right half is sorted but target is smaller than mid so it can not be founded in right half
                    h = m - 1;
                }
            }else if(target > nums[m]){
                // left half is sorted but target is greater then mid so target can not be in left half
                if(nums[m] >= nums[l]){
                    l = m + 1;
                }else{
                    // right half is sorted and acoding to upper condition target is greater then mid and according to this target is less or equal to hi so target must be in right half
                    if(target <= nums[h]){
                    // right half is sorted and acoding to upper condition target is greater then mid and according to this target is less or equal to hi so target must be in right half
                    l = m + 1;
                    }else{
                    // right half is sorted but target is not in the right one so we will move to left half.
                        h = m - 1;
                    }
                }
            }else{
                // when we got the desired element we will return index of that
                return m;
            }
        }
        return -1;
    }

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n,target;
        
        //size of array
        cin >> n >> target;
        
        vector<int> arr(n);
        
        for(int i =0;i<n;i++){
            cin >> arr[i];            
        }
      
        cout << search(arr, target) << endl;
        
    }
    
    return 0;
}
