import java.util.*;
import java.lang.*;
import java.io.*;
class Main
{
  public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while(true){
            if(word1[i1].charAt(j1) != word2[i2].charAt(j2)) return false;
            if(j1 == word1[i1].length()-1){i1++; j1 = 0;}
            else j1++;
            if(j2 == word2[i2].length()-1){i2++; j2 = 0;}
            else j2++;
            if(i1 == word1.length && i2 == word2.length)
                return true;
            else if(i1 == word1.length || i2 == word2.length)
                return false;
        }
    }
  public static void main (String[] args) throws java.lang.Exception
  {
    String[] word1 = {"ab", "c"};
    String[] word2 = {"a", "bc"};
    System.out.print((arrayStringsAreEqual(word1, word2) ? "true" : "false"));
    return 0;
  }
}

/*Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.*/

