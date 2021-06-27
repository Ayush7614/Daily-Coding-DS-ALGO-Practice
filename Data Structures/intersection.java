/**
 * Java code to find intersection when
 * elements may not be distinct
*/

/*i am doing this using by using the best method which reduces the time complexity that is HASHMAP*/
import java.util.*;
import java.util.HashMap;
 
class intersectionoftwoarrays
{
	public static printintersection(int[] arr1,int[] arr2)
	{
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		for(int i=0;i<arr1.length;i++)
		{
			if(map.containsKey(arr1[i])
			   {
				   int old=map.get(arr[i]);//getting the old frequency of that particular number
				   int newf=old+1;
				   map.put(arr[i],newf);//updating to the new frequency
			   }
			   else
			   {
				   map.put(arr[i],1);
			   }
		}
		for(int i=0;i<arr2.length;i++)
	         {
			 if(map.containsKey(arr2[i])
			    {
				    //we have to reduce the frequency by one
				    int freq=map.get(arr2[i]);
				    freq--;
				    if (freq == 0) {
                                      map.remove(arr2[i]);
                                     } else {
                                        map.put(arr2[i], freq);
                                         }
			//now we have to print the element
				    System.out.println(arr2[i]+" ");
			    }
	       }		    
			    
	 System.out.println();
			    
			    
	public static void main(String[] args) {
        // Example 1
        int arr1[] = new int[] {1, 2, 2, 1};
        int arr2[] = new int[] {2, 2};
        printintersection(arr1, arr2);
	}
}			    
	
