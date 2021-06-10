//Problem Link : https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    int trappingWater(int arr[], int n){
        // Code here
        int water = 0;
        
        int* max_height_left = new int[n];//In this we will store maximum height on left from current index
        int* max_height_right = new int[n];//In this we will store maximum height on right from current index
        
        max_height_left[0] = arr[0];
        max_height_right[n-1] = arr[n-1];
        //Filling max_height_left array
        for(int i = 1; i < n; i++){
            max_height_left[i] = max(max_height_left[i-1],arr[i]);
        }
        //Filling max_height_left array
        for(int i = n-2; i >= 0; i--){
            max_height_right[i] = max(max_height_right[i+1],arr[i]);
        }
        // We can not store any water at the 1st and last wall because it has not any type of support so we will run loop for 2nd element to 2nd last element
        for(int i = 1; i < n-1; i++){
            //water stored at any index will be minimum of max_height_left and mex_height_right and we will substract height of current index
            water += (min(max_height_left[i],max_height_right[i]) - arr[i]);
        }
        return water;
    }
