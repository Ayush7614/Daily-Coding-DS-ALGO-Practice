// Problem link : https://www.codechef.com/problems/ALPHABET

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int test = sc.nextInt();
		for (int t = 0 ; t < test ; t++){
		    String check = sc.next();
		    int flag = 0;
		    for (int i = 0 ; i < check.length(); i++){
		        if(!s.contains(check.substring(i,i+1))){
		            flag = 1;
		            System.out.println("No");
		            break;
		        }
		    }
		    if(flag == 0){
		        System.out.println("Yes");
		    }
		}
	}
}


// Example Test case
// Input:
// act
// 2
// cat
// dog
//
// Output:
// Yes
// No
