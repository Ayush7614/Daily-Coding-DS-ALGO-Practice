// problem link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

void threeWayPartition(vector<int>& arr,int a, int b)
    {
        
        // following method is known as dnf sort
        // using three pointers
        int n=arr.size();
        int low=0, mid=0, high=n-1;
        while(mid <= high)
        {
            if(arr[mid] < a)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if(arr[mid] > b)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
            else
            {
                mid++;
            }
            
        }
    }
