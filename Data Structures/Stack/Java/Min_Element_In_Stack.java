import java.util.Scanner;
import java.util.Stack;

class Min_Element_In_Stack{

  //s1 will act as primary stack and s2 as temporary stack  
  Stack<Integer> s1 = new Stack<Integer>();
  Stack<Integer> s2 = new Stack<Integer>();

  //Push data to the top of the stack
  void insertData(int data){
    //If both the stacks are empty add the item to both the stack
    if(s1.isEmpty() && s2.isEmpty()){
      s1.push(data);
      s2.push(data);
    }
    else{
      s1.push(data);
      if(s1.peek()<=s2.peek()){
        s2.push(data);
      }
    }

  }

  //Find the minimum from top of the stack
  int findMinimum(){
    return s2.peek();
  }

  public static void main(String args[]){
    Scanner inp = new Scanner(System.in);

    Min_Element_In_Stack mObj = new Min_Element_In_Stack();
    int n;
    System.out.print("Enter the no of Elements in the Stack: ");
    n = inp.nextInt();

    System.out.println("Enter the values of the stack:");
    for(int i = 0; i < n; i++){
      mObj.insertData(inp.nextInt());
    }

    //Find Minimun
    System.out.println("Minimum element in the above stack is : " + mObj.findMinimum());

  }
}

/*Test Cases-
Enter the no of Elements in the Stack: 4
Enter the values of the stack:
100     50      1       -100
Minimum element in the above stack is : -100
*/