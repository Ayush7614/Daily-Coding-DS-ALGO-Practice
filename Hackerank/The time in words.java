import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the timeInWords function below.
    static String timeInWords(int h, int m) {
        String[] num = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
        if (m == 00){
            return num[h-1]+" o' clock";
        }
        else{
            if (m < 30 ){
                if (m == 15){
                    return "quarter past "+num[h-1];
                }
                else{
                    if (m < 10){
                        return num[m-1]+" minute past "+num[h-1];
                    }
                    int temp = m % 10;
                    int val = m - temp;
                    if (val == 10){
                        return num[m-1]+ " minutes past "+num[h-1];
                    }
                    else{
                    return num[val-1] +" "+num[temp-1]+" minutes past "+num[h-1];
                    }
                }
            }
            else if (m == 30){
                return "half past "+num[h-1];
            }
            else{
                if (m == 45){
                    return "quarter to "+num[h];
                }
                else{
                    m = 60-m;
                    if (m < 10){
                        return num[m-1]+" minutes to "+num[h];
                    }
                    int temp = m % 10;
                    int val = m - temp;
                    if (val == 10){
                        return num[m-1]+ " minutes to "+num[h];
                    }
                    else{
                    return num[val-1] +" "+num[temp-1]+" minutes to "+num[h];
                    }
                }
            }
        }
        //return " ";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
