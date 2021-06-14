package RandomQuestions;
import java.util.Scanner;
import java.util.Stack;
public class LargestAreaHistogram {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int[] arr= {6,2,5,4,5,1,6};
		
		
		int[] rightBound=new int[arr.length];
		int[] leftBound=new int[arr.length];
		
		//(right index-left index)-1 gives the width.
		
		Stack<Integer> st=new Stack<>();
		st.push(arr.length-1);
		rightBound[arr.length-1]=arr.length;
		sc.close();
		for(int i=arr.length-2;i>=0;i--)
		{
			while(st.size()>0 && arr[i]<arr[st.peek()])
			{
				st.pop();
			}
			
			if(st.size()==0)
			{
				rightBound[i]=arr.length;
			}
			else
			{
				rightBound[i]=st.peek();
			}
		}
		
		int maxArea=0;
		for(int i=0;i<arr.length;i++)
		{
			int width=rightBound[i]-leftBound[i]-1;
			int area=arr[i]*width;
			if(area>maxArea)
			{
				maxArea=area;
			}
		}
		System.out.println(maxArea);
	}

}
