class Convert:
  def __init__(self,n):
    self.top=-1
    self.n=n
    self.array=[]
    self.output=[]
    self.precedence={'+':1,'-':1,'*':2,'/':2,'^':3}
    
  def isEmpty(self):
    if self.top==-1:
      return True
    else:
      return False
  
  def peek(self):
    return self.array[-1]
  # Pop the element from the stack
  def pop(self):
    if not self.isEmpty():
      self.top =self.top-1
      return self.array.pop()
    else:
      return "$"
      
  # Push the element to the stack
  def push(self,op):
    self.top =self.top+1
    self.array.append(op)
  
  
  def isOperand(self,ch):
    return ch.isalpha()
  
  
  def notGreater(self,i):
    try:
      a=self.precedence[i]
      b=self.precedence[self.peek()]
      if a<=b:
        return True
      else:
        return False
    except KeyError:
      return False
  
  def infix_postfix(self,exp):
    for i in exp:
      if self.isOperand(i):
        self.output.append(i)
      elif i  == '(':
        self.push(i)
      elif i == ')':
        while( (not self.isEmpty()) and  self.peek() != '('):
          a = self.pop()
          self.output.append(a)
        if (not self.isEmpty() and self.peek() != '('):
          return -1
        else:
          self.pop()
        
      else:
        while(not self.isEmpty() and self.notGreater(i)):
          self.output.append(self.pop())
        self.push(i)
      
    while not self.isEmpty():
      self.output.append(self.pop())
    print( " ".join(self.output)) 


exp ="a+b*(c^d-e)"
obj =Convert(len(exp))
obj.infix_postfix(exp)





  










