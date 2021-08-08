//Problem link : https://www.codechef.com/problems/HORSES



import java.util.*;
import java.lang.*;
import java.io.*;


class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 0 ; t < test ; t++){
		    int n = sc.nextInt();
		    ArrayList<Integer> list = new ArrayList<Integer>();
		    for (int i = 0 ; i < n ; i++){
		        list.add(sc.nextInt());
		    }
		    Collections.sort(list);
		    int min = list.get(1) - list.get(0);
		    for(int j =0 ; j < list.size()-1;j++){
		        if(list.get(j+1)-list.get(j) < min){
		            min = list.get(j+1)-list.get(j);
		        }
		    }
		    System.out.println(min);
		}
	}
}


// Example test case
// Input
// 1
// 5
// 4 9 1 32 13
//
// output
// 3
