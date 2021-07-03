import java.util.*;
public class Sortarray{
    public static  void sort(int [] nums){
        int low=0;
        int high=nums.length-1;
        int mid=0;
        int temp;
        while(mid<=high){
            switch(nums[mid]){
                case 0:{
                    temp=nums[mid];
                    nums[low]=nums[mid];
                    nums[mid]=temp;
                    low++;
                    mid++;
                    break;
                }
                case 1:{
                    mid++;
                    break;
            }
            case 2:{
                temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
                break;
            }
        }
    }
    }
    public static void print(int nums[]){ //printing array elements
        
    int i;
    for(i=0;i<nums.length;i++){
        System.out.println(nums[i]+" ");
        System.out.println(" ");
    }
    }

     public static void main(String []args){
        int size;
        System.out.println("Enter size of array:");
        Scanner sc=new Scanner(System.in);
        size=sc.nextInt();
        int[] arr = new int[size];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<size; i++)  
         {  
         //reading array elements from the user   
         arr[i]=sc.nextInt();  
         }
         sort(arr);
         System.out.println("Array after sorting is:");
          for(int i=0;i<size;i++){
         System.out.printf("%d\t",arr[i]);
         }
}
}
/*
Test case1: 
Enter size of array: 4
Enter elements of the array : 1 0 0 2
Output: Array after sorting is : 0 0 1 2

Testcase 2:
Enter size of array: 5
Enter elements of the array : 1 0 1 0 2
Output: Array after sorting is : 0 0 1 1 2

Time Complexity: O(n)
Space Complexity:O(1)
*/
