import java.util.*;
public class Twins{
     public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long sum=0; //sum of the coins
        int mincoins=0;
        long mincoinssum=0;
        int coins[]=new int[n]; //these are indivisual coins
        for(int i=0;i<n;i++){
            coins[i]=sc.nextInt();
            sum=sum+coins[i];
        }
        Arrays.sort(coins);
        for(int j=n-1;j>=0;j--){
            mincoinssum=mincoinssum+coins[j];
            if(mincoinssum>(sum-mincoinssum)){
                mincoins++;
                break;
            }
            mincoins++;
        }
        System.out.println(mincoins);
     }
}
/* Input:
   3
   2 1 2
   Output: 2
*/