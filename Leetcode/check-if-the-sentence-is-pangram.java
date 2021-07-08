
import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(checkIfPangram(s));
    }
    public static boolean checkIfPangram(String sentence) {
        String alph = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0 ; i < alph.length(); i++){
            if(!sentence.contains(alph.substring(i,i+1))){
                return false;
            }
        }
        return true;
    }
}



// Example test cases
//
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
//
// Input: sentence = "leetcode"
// Output: false
