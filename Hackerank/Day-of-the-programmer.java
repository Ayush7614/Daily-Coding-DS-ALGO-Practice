import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the dayOfProgrammer function below.
    static String dayOfProgrammer(int year) {
        int sum = 31+31+30+31+30+31+31;
        int month = 7;
        int date = 0;
        String ans = "";
        if (year == 1918){
                sum = sum + 15;
                month++;

            date = 256-sum;
            month++;
            String dt = Integer.toString(date);
            String mt = Integer.toString(month);
            if (date < 10){
                dt = "0"+dt;
            }
            if(month < 10){
                mt = "0"+ mt;
            }
            ans = dt+"."+mt+"."+Integer.toString(year);

        }
        else{
            if(isLeap(year)){

                sum = sum + 29;
                month++;
            }
            else{

                sum = sum + 28;
                month++;
            }
            date = 256-sum;

            month++;
            String dt = Integer.toString(date);
            String mt = Integer.toString(month);
            if (date < 10){
                dt = "0"+dt;
            }
            if(month < 10){
                mt = "0"+ mt;
            }
           ans = dt+"."+mt+"."+Integer.toString(year);

        }
        return ans;
    }

    public static boolean isLeap(int year){
        if (year <= 1917){
            if (year%4 == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(year%400 == 0){
                    return true;
                }
            else{
                if(year%4 == 0){
                if(year%100 == 0){
                    return false;
                }
                else{
                    return true;
                }
            }

            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int year = Integer.parseInt(bufferedReader.readLine().trim());

        String result = dayOfProgrammer(year);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}



// Example test case
// Input - 2017
// Output - 13.09.2017

//Input - 2016
//Output - 12.09.2016
