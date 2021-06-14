public class LargestSmallestNumber {
 
     public static void main(String[] args) {
 
     //array of 10 numbers
     int arr[] = new int[]{132,516,276,189,100,343,219,234};
     
     //assign first element of an array to largest and smallest
     int smallest = arr[0];
     int largest = arr[0];
     
     for(int i=1; i< arr.length; i++){
         if(arr[i] > largest)
            largest = arr[i];
         else if (arr[i] < smallest)
            smallest = arr[i];
     }
     
     System.out.println("Smallest Number is : " + smallest);
     System.out.println("Largest Number is : " + largest); 
     }
}
