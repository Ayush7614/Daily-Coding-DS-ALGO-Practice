class xor 
{
  
    // Function to return the
    // maximum xor
    static int max_xor(int arr[], int n) 
    {
        int maxXor = 0;
  
        // Calculating xor of each pair
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++) 
            {
                maxXor = Math.max(maxXor,
                        arr[i] ^ arr[j]);
            }
        }
        return maxXor;
    }
  
    
    public static void main(String[] args) 
    {
        int arr[] = {25, 10, 2, 8, 5, 3};
        int n = arr.length;
  
        System.out.println(max_xor(arr, n));
    }
} 
/*test cases
Input: Arr = {25, 10, 2, 8, 5, 3} 
Output: 28 
The maximum result is 5 ^ 25 = 28 
Input: Arr = {1, 2, 3, 4, 5, 6, 7} 
Output: 7 
The maximum result is 1 ^ 6 = 7 */
  
