
// Question  https://www.hackerrank.com/challenges/larrys-array/problem

//Eaxmples
/**
 * Eaxmple 1
 * Test case 0:
 * Input: A={3,1,2} -> rotate(3,1,2) -> A1={1,2,3}
 * Output: YES
 * A is now sorted, so we print YES on a new line.
 * 
 * 
 * Input: A={1,3,4,2} -> rotate(3,4,2) -> A1={1,4,2,3}
 *        A1={1,4,2,3} -> rotate(4,2,3) -> A2={1,2,3,4}
 * Output: YES
 * A is now sorted, so we print YES on a new line.
 */

// SOlution 

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {
    public static String larrysArray(List<Integer> A) {
        int k = 1;
        for(int i = 0; i < A.size()-1; i++){
            for(int j = i+1; j < A.size(); j++){
                if(A.get(i) > A.get(j))
                    k^= 1;
                else
                    k^= 0;
            }
        }
        if(k == 1)
            return "YES";
        return "NO";
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int n = Integer.parseInt(bufferedReader.readLine().trim());

            String[] ATemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> A = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                int AItem = Integer.parseInt(ATemp[i]);
                A.add(AItem);
            }

            String result = Result.larrysArray(A);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
