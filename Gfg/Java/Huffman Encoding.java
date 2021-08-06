import java.lang.*;
import java.io.*;
class GFG
 {
	public static void main (String[] args)
	 {
	 //code
	 Scanner s=new Scanner(System.in);
	 int T=s.nextInt();
	 for(int i=0;i<T;i++)
	 {
	     String str=s.next();
	     int[] arr=new int[str.length()];
	     for(int j=0;j<arr.length;j++)
	     {
	         arr[j]=s.nextInt();
	     }
	     encode(str,arr);
	     System.out.println();
	 }
	 }
	 
	 public static void encode(String str,int[] arr)
	{
		        PriorityQueue<Node> queue=new PriorityQueue<>(new Comparator<Node>()
				{
				@Override
				public int compare(Node n1,Node n2)
				{
				    if(n1.freq==n2.freq)
				    return 1;
					return n1.freq-n2.freq;
				}
				}
		);
		for(int i=0;i<str.length();i++)
		{
			Node node=new Node(""+str.charAt(i),arr[i],null,null);
			queue.add(node);
		}
		while(queue.size()>1)
		{
			Node node1=queue.remove();
			Node node2=queue.remove();
			Node node=new Node(node1.name+node2.name,node1.freq+node2.freq,node1,node2);
			queue.add(node);
		}
		huffmanencode(queue.peek(),"");
	}
	
	public static void huffmanencode(Node root,String res)
	{
		if(root.left==null&&root.right==null)
		{
			System.out.print(res+" ");
			return;
		}
		huffmanencode(root.left,res+"0");
		huffmanencode(root.right,res+"1");
	}
	public static class Node
	{
		String name;
		int freq;
		Node left;
		Node right;
		
		Node(String name,int freq,Node left,Node right)
		{
			this.name=name;
			this.freq=freq;
			this.left=left;
			this.right=right;
		}
	}
}
