
import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Size of array : ");
        int n= sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0 ; i < n ; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(containsDuplicate(arr));
    }

    public static boolean containsDuplicate(int[] nums) {

        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for (int i = 0 ; i < nums.length ; i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],1);
            }
            else{
                return true;
            }
        }
        return false;
    }
}



// Example test case
// Input: Size = 4
// 1 2 3 1
// Output: true
