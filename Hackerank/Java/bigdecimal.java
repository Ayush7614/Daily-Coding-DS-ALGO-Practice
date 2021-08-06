/*
Link to the problem- https://www.hackerrank.com/challenges/java-bigdecimal/problem
*/
import java.math.BigDecimal;
import java.util.*;
class decimal{
    public static void main(String []args){
        //Taking input from user
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
        sc.close();
Arrays.sort(s, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
        if (o1 == null || o2 == null) {
            return 0;
        }
        BigDecimal o1bd = new BigDecimal(o1);//creating objects for bigdecimal
        BigDecimal o2bd = new BigDecimal(o2);
        return o2bd.compareTo(o1bd);
        }
    });
        //Printing the output
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }
}

/* 
Input-
9
-100
50
0
56.6
90
0.12
.12
02.34
000.000
Output-
90
56.6
50
02.34
0.12
.12
0
000.000
-100
*/
