//https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1/

//Let's give it a try!
//You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list.
//Your task is to use the class as shown in the comments in the code editor and
//complete the functions push() and pop() to implement a stack.

import java.util.EmptyStackException;

class Node <T>{
    Node<T> next;
    T data;
    Node(T data){
        this.data = data;
        next = null;
    }
}

public class Stack_Using_LinkedList <T>{

    private int size;
    private Node<T> head;

    public T pop(){
        if(head == null)
            throw new EmptyStackException();
        T temp = head.data;
        head = head.next;
        size--;
        return temp;
    }

    public int size(){
        return size;
    }

    public void push(T data){
        Node<T> newNode = new Node<>(data);
        newNode.next = head;
        head = newNode;
        size++;
    }

    public T peek(){
        if(head == null)
            throw new EmptyStackException();
        return head.data;
    }

    public boolean isEmpty(){
        return head == null;
    }

}

class MainClass {
    public static void main(String[] args) {
        Stack_Using_LinkedList<Character> stack = new Stack_Using_LinkedList<>();
        
        stack.push('a');
        stack.push('b');
        stack.push('c');
        stack.push('d');
        stack.push('e');

        System.out.println(stack.isEmpty());
        var peek = stack.peek();
        System.out.println(peek);
        System.out.println(stack.size());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
        stack.pop();
        stack.pop();
        System.out.println(stack.peek());
    }
}

//Test Cases
// Input: 
// push(2)
// push(3)
// pop()
// push(4) 
// pop()
// Output: 3 4
// Explanation: 
// push(2)    the stack will be {2}
// push(3)    the stack will be {2 3}
// pop()      poped element will be 3,
//            the stack will be {2}
// push(4)    the stack will be {2 4}
// pop()      poped element will be 4

// Expected Time Complexity: O(1) for all the operation.
// Expected Auxiliary Space: O(1) for all the operation.

// Constraints:
// 1 <= Q <= 100
// 1 <= x <= 100