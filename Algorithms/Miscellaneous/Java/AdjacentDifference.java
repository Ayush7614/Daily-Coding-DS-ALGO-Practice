//The adjacent_difference algorithm produces a new sequence in which each element is difference between adjacent elements in original sequence.
import java.util.Scanner;
public class AdjacentDifference{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(); //number of elements in an array in contiguous locations
        int a[] = new int[n]; //declaration and memory allocation
        for(int i = 0; i < n; i++)
        {
            a[i] = s.nextInt();  //initialisation
        }
       
        int b[] = new int[n];  //new array for storing result
        b[0] = a[0]; 
        for(int i = 1;i<n;i++)
        {
            
           b[i] = a[i] - a[i-1];  //difference between adjacent elements
           
        }
        for(int i=0;i<n;i++)
        {
        System.out.println(b[i]);  //new resultant array
        }


    }
}
