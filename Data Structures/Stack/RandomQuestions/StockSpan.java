package RandomQuestions;

import java.util.Stack;

public class StockSpan {

	public static void main(String[] args) {
	
		Stack<Integer> st=new Stack<>();
		int arr[]= {2,4,8,3,2,9,8,3,9,1,1,9,3};
		int[] span=new int[arr.length];
		st.push(0);
		span[0]=1;
		
		for(int i=2;i<arr.length;i++)
		{
			while(st.size()>0&&arr[i]>=arr[st.peek()])
			{
				st.pop();
			}
			if(st.size()==0)
			{
				span[i]=i+1;
			}
			else
			{
				span[i]=i-st.peek();
			}
			st.push(i);
		}
	
}
}
