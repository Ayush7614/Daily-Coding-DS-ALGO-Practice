//Attempt this problem at -
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Given an expression string x.
// Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example,
// the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

// Example 1 : 
// Input: {([])}
// Output: true

// Example 2 : 
// Input : ([]
// Output: false

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 32000

import java.util.*;

public class Parenthesis_Checker
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        //Reading total number of testcases
        int t= sc.nextInt();
        
        while(t-- >0)
        {
            //reading the string
            String st = sc.next();
            
            //calling ispar method of Paranthesis class 
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(new Parenthesis().ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");
        
        }
        sc.close();
    }
}// } Driver Code Ends

class Parenthesis
{
    //Function to check if brackets are balanced or not.
    boolean ispar(String x)
    {
        Stack<Character> s = new Stack<>();
        for(char ch : x.toCharArray()){
            if(leftBracket(ch)){
                s.push(ch);
            }else{
                if(s.isEmpty())
                    return false;
                char top = s.pop();
                if(bracketMatch(ch, top))
                    return false;
            }
        }
        return s.isEmpty();
    }

    boolean leftBracket(char ch){
        return ch == '{' || ch == '(' || ch == '[';
    }

    boolean bracketMatch(char ch, char top){
        return ((ch == ']' && top != '[') || 
                (ch == '(' && top != ')') ||
                (ch == '}' && top != '{'));
    }
}
