//Problem Link : https://www.codechef.com/problems/TLG


import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		int lead = 0;
		int leader = 1;
		int a = 0;
		int b = 0;
		for (int i = 0 ; i < test ; i++){
		a = a + sc.nextInt();
		b = b +  sc.nextInt();
		if(Math.abs(a-b) > lead){
		    lead = Math.abs(a-b);
		    if ( a > b){
		        leader = 1;
		    }
		    else{
		        leader = 2;
		    }
		}


		}
		System.out.println(leader+" "+lead);

	}
}


// Example test case
// Input:
// 5
// 140 82
// 89 134
// 90 110
// 112 106
// 88 90
//
// Output: 1 58
