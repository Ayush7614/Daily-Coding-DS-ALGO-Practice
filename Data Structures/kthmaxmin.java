import java.util.*;
public class kthmaxmin{
    public static int kthlargest(int [] arr,int k){
        if(arr.length<k){
            System.out.println("Invalid");
            return -1;
        }
        PriorityQueue<Integer> minheap=new PriorityQueue<>();
        for(int i=0;i<k;i++){
            minheap.add(arr[i]);
        }
        for(int i=k;i<arr.length;i++){
            if(arr[i]>minheap.peek()){
                minheap.poll();
                minheap.add(arr[i]);
            }
        }
        return minheap.peek();
    }
    public static int kthsmallest(int [] arr,int k){
        if(arr.length<k){
            System.out.println("Invalid");
            return -1;
        }
        PriorityQueue<Integer> maxheap=new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<k;i++){
            maxheap.add(arr[i]);
        }
        for(int i=k;i<arr.length;i++){
            if(arr[i]<maxheap.peek()){
                maxheap.poll();
                maxheap.add(arr[i]);
            }
        }
        return maxheap.peek();
    }
    public static void main(String []args){
         int n;
         Scanner sc=new Scanner(System.in);
         System.out.println("Enter size of array");
         n=sc.nextInt();
         System.out.println("Enter elements of array");
         int array[]=new int[n];
         for(int i=0;i<n;i++){
             array[i]=sc.nextInt();
         }
         int k=sc.nextInt();
         System.out.println("kth maximum and minimum elements of array are");
         System.out.println(kthmaxmin.kthlargest(array,k));
         System.out.println(kthmaxmin.kthsmallest(array,k));
        
     }
}