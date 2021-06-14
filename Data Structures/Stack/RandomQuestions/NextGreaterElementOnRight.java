package RandomQuestions;

import java.util.Stack;

public class NextGreaterElementOnRight {

	public static void main(String[] args) {
		
		int[]arr= {2,5,9,3,1,12,6,8,7};
		Stack<Integer> st=new Stack<>();
		st.push(arr[arr.length-1]);
		
		int[] ans=new int[arr.length];
		ans[arr.length-1]=-1;
		
		for(int i=arr.length-2;i>=0;i--)
		{
			while(st.size()>0 && arr[i]>=st.peek())
			{
				st.pop();
			}
			if(st.size()==0)
			{
				ans[i]=-1;
			}
			else
			{
				ans[i]=st.peek();
			}
			st.push(arr[i]);
		}
		for(int t=0;t<ans.length;t++)
		{
			System.out.println(ans[t]+" ");
		}
		}

	}
