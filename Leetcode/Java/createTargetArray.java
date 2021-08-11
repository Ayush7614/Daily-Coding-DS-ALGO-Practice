//Problem Link : https://leetcode.com/problems/create-target-array-in-the-given-order/
import java.util.*;

class targetArray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        int[] index = new int[n];
        for (int i = 0 ; i < n ; i++){
            nums[i] = sc.nextInt();
        }

        for (int i = 0 ; i < n ; i++){
            index[i] = sc.nextInt();
        }

        int[] ans = createTargetArray(nums,index);
        for (int i : ans){
            System.out.printf(i+ " ");
        }
        sc.close();
    }

    private static int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0 ; i < nums.length ; i++){
            list.add(index[i],nums[i]);
        }
        int[] target = new int[nums.length];
        for (int i = 0 ; i < nums.length ; i++){
            target[i] = list.get(i);
        }
        return target;
    }
}

// Example test case
// Input :
// 5
// 0 1 2 3 4
// 0 1 2 2 1

// Output : 0 4 1 3 2
