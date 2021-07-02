import java.util.*;
public class CountOfSmallerNumbersAfterSelf{
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] ar = new int[n];
        for (int i = 0; i < n; i++){
            ar[i] = s.nextInt();
        }
        List<Integer> l = countSmaller(ar);
        System.out.println(l);
    }

    public static List<Integer> countSmaller(int[] nums){
        List<Integer> res = new ArrayList<>(nums.length);
        List<Integer> sortedList = new ArrayList<>();
        if (nums == null || nums.length == 0){
            return res;
        }
        res.add(0);
        sortedList.add(nums[nums.length-1]);
        for (int i = nums.length-2; i >= 0; i--){
            int idx = Collections.binarySearch(sortedList, nums[i]);
            if (idx >= 0){
                while (idx > 0 && sortedList.get(idx-1) == nums[i]){
                    idx--;
                }
            } else {
                idx = -1-idx;
            }
            res.add(0, idx);
            sortedList.add(idx, nums[i]);
        }
        return res;
    }
}