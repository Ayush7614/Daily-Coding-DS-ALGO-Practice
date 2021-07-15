import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the encryption function below.
    static String encryption(String s) {
        String s2 = "";
        for (int i = 1; i <= s.length() ; i++){
            String temp = s.substring(i-1,i);
            if(!temp.equals(" ")){
                s2 = s2 + temp;
            }
        }
        double a = Math.sqrt(s2.length());
        int b = (int)a+1;
        if(a%1 == 0){
            b = (int)a;
        }
        if (a*b < s2.length()){
            a++;
        }

        String ans = "";
        for (int i = 0 ; i < b ; i++){
            for (int j = i ; j < s2.length();j+=b){
                ans = ans + s2.substring(j,j+1);
            }
            ans = ans + " ";
        }



        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = encryption(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
