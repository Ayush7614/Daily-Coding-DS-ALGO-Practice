/*
Link to the question-https://www.codechef.com/COOK130C/problems/XORFOLD/
*/
import java.util.*;
import java.lang.*;
import java.io.*;


class XORFOLD
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t--!=0)
		{
			int n=sc.nextInt();
			int m=sc.nextInt();
			String arr[]=new String[n];
			for(int i=0;i<n;i++)
			{
				 arr[i]=sc.next();//Taking input of each row
			}
			int result=solve(arr,n,m);//calling the function
		
			if(result==1)
			System.out.println("YES");
			else
			System.out.println("NO");
		}
}

 static int  solve(String[] arr,int len,int m) {
		
		 int res=0;
		 for(int i=0;i<len;i++)
		 {
			 for(int j=0;j<m;j++){
				 if(arr[i].charAt(j)=='0')//checking for 0 and 1
				 {
			      res=res^0;
				 }
			 else
			 {
			 res=res^1;}
			}

		 }
		 return res;
	}
}

/*
Input -
2
1 2
01
3 3
000
111
010
Output-
YES
NO
*/
