import java.util.*;
import java.lang.*;
import java.io.*;
 
public class Main
{     public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	int test=sc.nextInt();
	while(test-->0){
		int n=sc.nextInt();
		for (int j = 0; j < n; j++) {
		String s="";
		String m="";
		for (int i = 0; i <=j; i++) {
			m+=")";
			s+="(";
		}
		System.out.print(s+m);
		for(int k=j;k<n-1;k++){
          System.out.print("()");
		}
		System.out.println();
	}
	}}}
