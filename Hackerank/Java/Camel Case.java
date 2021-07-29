// Question  https://www.hackerrank.com/challenges/camelcase/copy-from/210234653

// Examples
/**
 * Example 1
 * Input: saveChangesInTheEditor
 * Output: 5
 * 
 * Example 2
 * Input: oneTwoThree
 * Output: 3
 */

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {
    public static int camelcase(String s) {
        int count = 1;
        for(char c : s.toCharArray()) {
            if(Character.isUpperCase(c))
            count++;
        }
        return count;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        int result = Result.camelcase(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
