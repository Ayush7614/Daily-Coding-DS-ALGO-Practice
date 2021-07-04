/* 
        Time Complexity: O(n)
        Space Complexity: O(1) 
*/

/*
Here for Finding sum of Taylor Series of e^x, we Create 2 functions, one for
calculating factorial [factorial(x)] with help of recursion to make good time & Space Complexity. */


package taylor;
import java.util.Scanner;
public class taylor {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("type the value of q :");
        int q = scan.nextInt();
        System.out.println("type the value of r :");
        int r = scan.nextInt();
        int ans = ex(q,r);
      
        System.out.println("the ans for Taylor Series of e^x is : "+ans);
    
    }
    public static int ex(int q, int r){
        
      int ans = 1;
      
        for (int i = 1;i<=(n-1);i++)
        {
            ans += (q/factorial(i));
        }
        return ans;
    }
    public static int factorial(int q){
        if (q == 0){
            return 1;
        }
      
     else
     {
            return (q*factorial(q-1));
        }
    }
}
/*
    Test Cases:

        Input: 3 25
        Output: 5

 */
