// Problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// the code mentioned below uses sort function and solves the que with a complexity of O(nlogn) .
// but geeksforgeeks has mentioned an efficient O(n) solution(method 3) : https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/  

int *findTwoElement(int *arr, int n) {
        int *ans=new int[2]; // either use vector or if using array then dynamically allocate the memory because else the scope of ans array will be just till this function 
        ans[2]={0};          // even using static int arr[n] for array wont work since for multiple outputs it wont work as static variables can be initialized only once
        int index=0;
        sort(arr,arr+n);     
        for(int i=0; i<n-1; i++) // to check duplicates
        {
            if(arr[i] == arr[i+1])
            {
                ans[0]=arr[i];
                break;
            }
        }
        for(int j=0; j<n-1; j++)
        {
            if(arr[index] != j+1) 
            {
                ans[1]=arr[index]-1;
                break;
            }
            if(arr[j] == arr[j+1]) index+=2; // if we find a duplicate then index is incremented by 2 units  
            else index++;                    // 1 [2] 2 3 5 then index now needs to be shifted to 3 ie., to the 3rd index
        }
        if(ans[1] == 0) // if there's no missing element the last element of array + 1 is to be returned
        {
            ans[1]=arr[n-1]+1;
        }
        return ans;
        
    }
