package Java;

import java.util.Stack;

public class BalancedParenthesisCheckerProblem {
    static boolean ispar(String x)
    {
        Stack<Character> s = new Stack<>();

        for(int i=0;i<x.length();i++){
            char ch= x.charAt(i);
            if(ch== '{' || ch=='(' || ch == '['){
                s.push(ch);
                continue;

            }
            else if(s.isEmpty())
                return false;

            char check;
            switch (ch){

                case ')':
                    check= s.pop();
                    if(check == '[' || check =='{')
                        return false;
                    break;

                case ']':
                    check= s.pop();
                    if(check == '(' || check =='{')
                        return false;
                    break;
                case '}':
                    check= s.pop();
                    if(check == '[' || check =='(')
                        return false;
                    break;

            }

        }

        return (s.isEmpty());


    }
    public static void main(String[] args)
    {
        String expr = "([{}])";

        // Function call
        if (ispar(expr))
            System.out.println("Balanced ");
        else
            System.out.println("Not Balanced ");
    }

}
