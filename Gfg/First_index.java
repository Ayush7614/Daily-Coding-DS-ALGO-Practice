import java.util.*;
import java.lang.*;
public class First_index {

    static int first_index(int[] a,int i,int s,int y){
        if(s==0) // if size of array is 0
            return -1;
        if(a[i]==y && i<s)
            return i;
        else{
           int v= first_index(a,i+1,s,y); //recursive function
           if(v==-1)
               return -1;
           else
              return v;
    }
    }
    public static void main(String []args){

        System.out.println("enter the size of array");
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++) {
        arr[i]=sc.nextInt();
        }
        System.out.println("enter the element to be searched");
        int x;
        x=sc.nextInt();
        int index=first_index(arr,0,n,x);
        System.out.println(index);
    }
}

/*
INPUT
6
4
3
2
2
1
5
2
OUTPUT 2

 */