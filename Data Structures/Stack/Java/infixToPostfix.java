/**
 * Algorithm to follow:
 * Iterate over the given string.
 * If current character is an operand, add it to output string.
 * Else if current character is ‘(‘, push it to the stack.
 * Else if current character is ‘)’, pop the elements from stack and add to output string until ‘(‘ is encountered in stack.
 * Else current character is an operator so while precedence of current character is less than or equal to precedence of top of stack pop the top element and add it to the output string. Push the current character in the stack.
 * After iteration, pop all the remaining elements from the stack and add them to output string.
 * Return the output string.
 */

class InfixToPostfix
{
    //Function to convert an infix expression to a postfix expression.
    public static String infixToPostfix(String exp)
    {

        Stack<Character> stack = new Stack<>(); //We use stack to keep track of operator
        //Map is used here to get the precedence of Operator in O(1) time.
        Map<Character, Integer> precedenceMap = Map.ofEntries(
                Map.entry('+', 0), Map.entry('-', 0),
                Map.entry('*', 1), Map.entry('/', 1),
                Map.entry('^', 2)
        );

        StringBuilder postFixExpression = new StringBuilder(); //The ouput Expression will be built here

        for(int i=0; i<exp.length(); i++)
        {
            if(exp.charAt(i)=='(') //if character at index i is '(' we push it to the stack
                stack.push('(');
            else if(exp.charAt(i)==')') //if character at index i is ')' we pop all element from stack till we encounter '('
            {
                while (!stack.isEmpty() && stack.peek()!='(')
                    postFixExpression.append(stack.pop()); //we append operator to the resulting string

                if(!stack.isEmpty()) //if stack is not empty then stack top contains '(', which we need to remove.
                    stack.pop();
            }
            else if(precedenceMap.containsKey(exp.charAt(i))) // if character at index i is present at precendecne map then it is a operator
            {
                if(stack.isEmpty() || stack.peek()=='(') // we push to stack in both the cases
                    stack.push(exp.charAt(i));
                else
                {
                    int currentPrecedence = precedenceMap.get(exp.charAt(i));

                    int stackTopPrecedence = precedenceMap.get(stack.peek());

                    if(currentPrecedence>stackTopPrecedence) // we push in this case
                        stack.push(exp.charAt(i));
                    else
                    {
                        while (!stack.isEmpty() && stack.peek()!='(')
                        {
                            if(currentPrecedence>stackTopPrecedence) // we break when this condition is satisfied
                                break;
                            else {
                                stackTopPrecedence = precedenceMap.get(stack.peek());
                                postFixExpression.append(stack.pop()); //we remove the current operator from the stack
                            }

                        }

                        stack.push(exp.charAt(i)); //we push the current operator to the stack
                    }

                }
            }
            else
                postFixExpression.append(exp.charAt(i)); //if character is operand we add it to the resulting string
        }

        while (!stack.isEmpty())
            postFixExpression.append(stack.pop());  //We append all the operator stored in the stack at the end

        return postFixExpression.toString();  //Return the resulting string
    }
}