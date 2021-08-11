public class Sort_012s {
    public static void main(String[] args) {
        int arr[] = {1, 1, 0, 0, 0, 0, 0, 2, 1, 2, 1, 1, 0, 0};
        sort(arr);
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }

    private static void sort(int[] arr) {
        int low = 0, mid = 0, high = arr.length - 1;
        while(mid <= high) {
            if(arr[mid] == 0){
                int temp = arr[mid];
                arr[mid] = arr[low];
                arr[low] = temp;
                mid++; low++;
            }else if(arr[mid] == 1) {
                mid++;
            }else{
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }
}