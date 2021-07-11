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
