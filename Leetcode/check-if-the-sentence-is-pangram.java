<<<<<<< HEAD

import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(checkIfPangram(s));
    }
    public static boolean checkIfPangram(String sentence) {
=======
class Solution {
    public boolean checkIfPangram(String sentence) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
>>>>>>> 8ec712bcef7ddc6c25f3a66aa78d3854aeeb2a69
        String alph = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0 ; i < alph.length(); i++){
            if(!sentence.contains(alph.substring(i,i+1))){
                return false;
            }
        }
        return true;
<<<<<<< HEAD
=======

>>>>>>> 8ec712bcef7ddc6c25f3a66aa78d3854aeeb2a69
    }
}


<<<<<<< HEAD

=======
>>>>>>> 8ec712bcef7ddc6c25f3a66aa78d3854aeeb2a69
// Example test cases
//
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
//
// Input: sentence = "leetcode"
// Output: false
