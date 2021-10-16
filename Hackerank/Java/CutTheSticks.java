/* 
Problem name: Cut the sticks
Problem Statement: You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks, discarding the shortest 
pieces until there are none left. At each iteration you will determine the length of the shortest stick remaining, cut that 
length from each of the longer sticks and then discard all the pieces of that shortest length. When all the remaining sticks 
are the same length, they cannot be shortened so discard them.
Given the lengths of  sticks, print the number of sticks that are left before each iteration until there are none left.

Example

The shortest stick length is 1, so cut that length from the longer two and discard the pieces of length 1. 
Now the lengths are arr=[1,2] . Again, the shortest stick is of length 1, so cut that amount from the longer stick and discard those pieces. 
There is only one stick left,arr=[1] , so discard that stick. The number of sticks at each iteration are answer=[3,2,1].

*/

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

class Result {

    public static List<Integer> cutTheSticks(List<Integer> list) {
        ArrayList<Integer> sizes = new ArrayList<>();
         while(list.size() != 0){
         sizes.add(list.size());
         int min = Collections.min(list);
         list.removeAll(Collections.singleton(min));
         for(int i=0; i<list.size();i++){
             list.set(i,list.get(i)-min);
         }
     }
     return sizes;
    }

}

public class CutTheSticks {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.cutTheSticks(arr);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
