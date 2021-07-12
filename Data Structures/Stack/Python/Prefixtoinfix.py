def prefixtoinfix(prefix):
    stack = []
    i = len(prefix) - 1    # read prefix expression in reverse order
    while i >= 0:
        if not isOperator(prefix[i]):    #  if symbol is operand push it to stack
            stack.append(prefix[i])
            i -= 1
        else:
            """if symbol is operator pop two operands from the stack and create a string
            by concatenating the two operands and the operator between them and push the resultant string 
            back to stack """
            str = "(" + stack.pop() + prefix[i] + stack.pop() +")"  
            stack.append(str)
            i -= 1
    return stack.pop()
def isOperator(p):
    if p == "+" or p == "-" or p == "*" or p == "/" or p == "^" or p == "(" or p == ")":
        return True
    else:
        return False
string=input("Enter string")
print("Infix expression is :",prefixtoinfix(string))
"""
Output: Enter string:"*+ab/ef"
Infix expression is : ((a+b)*(e/f)) 
"""