public class PermuteString {    
    //Function for swapping the characters at position I with character at position j    
    public static String swapString(String a, int i, int j) {    
        char[] b =a.toCharArray();    
        char ch;    
        ch = b[i];    
        b[i] = b[j];    
        b[j] = ch;    
        return String.valueOf(b);    
    }    
        
    public static void main(String[] args)    
    {    
        String str = "ABC";    
        int len = str.length();    
        System.out.println("All the permutations of the string are: ");    
        generatePermutation(str, 0, len);    
    }    
        
    //Function for generating different permutations of the string    
    public static void generatePermutation(String str, int start, int end)    
    {    
        //Prints the permutations    
        if (start == end-1)    
            System.out.println(str);    
        else    
        {    
            for (int i = start; i < end; i++)    
            {    
                //Swapping the string by fixing a character    
                str = swapString(str,start,i);    
                //Recursively calling function generatePermutation() for rest of the characters     
                generatePermutation(str,start+1,end);    
                //Backtracking and swapping the characters again.    
                str = swapString(str,start,i);    
            }    
        }    
    }    
}    

///
input
 ABC

All the permutations of the string are: 
ABC
ACB
BAC
BCA
CBA
CAB

///
