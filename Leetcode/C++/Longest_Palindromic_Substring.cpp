/*
Link to Leetcode problem : https://leetcode.com/problems/longest-palindromic-substring/

Problem: Statement : Given a string s, return the longest palindromic substring in s.

Example1
Input:s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example2
Input: s = "cbbd"
Output: "bb"
*/

/*--------------------------------------------------------------------------------------------------------
                                               Approach
                                      We can apply binary search
ps == Palindromic Substring
as we can always say that
if we find ps of length x then what we are sure is than we can make ps of lengths x-2,x-4,x-6... so we
will not check for lengths less than x but instead we will check for lengths x+2 , x+4 , x+6..

and we can also say that

if we can't find ps of length x then we will also not able to find ps with lengths x+2 ,x+4,x+6..
but we may find ps of lengths x-2,x-4,x-6..
so we will search for lengths less than x

lets see this for both even and odd length with small sample

odd
length 5= "abcba"
length 3= "bcb"
length 1 ="c"
even
length 6 = "abccba"
length 4 = "bccb"
length 2 = "cc"
So basically what we are doing is we are using the property of ps that if we remove first and last charater of ps then it will still be a ps.
NOTE :The property always hold only if we remove even lengths from string
and on basis of this we will apply binary seach seperatory for even lengths and odd lengths and return the ans which has greater length.

----------------------------------------------------------------------------------------------------------------------------------------------------
Time complexity analysis :
As we applying binary search total no of operation will be log(N) and for each operation we need O(N^2) to check wheather we can make ps or not

so final time complexity will be log(N)*(N^2)

----------------------------------------------------------------------------------------------------------------------------------------------------

Space complexity analysis :
The main advantage of the using this approach is unlike general dp which uses O(N^2) space
here space complexity of this approach will be O(N) that is becuase
we are only using constant number of integers,bools and string to store , manipulate data inputs and our algorithm.
Space complexity of integers , bool is O(1) and to store string it will be O(N).
so overall it will be O(N).
----------------------------------------------------------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    string FindAnsForOdd(string s){
    	int n = s.length();
    	int lo=1;
        int hi=n/2+(n%2)+1;
        int mid,len;
        string ans="";
        string str;
        string temp;
        bool FoundString;
        while(lo<hi){
        	mid = (lo+hi)/2;
        	len = 2*mid-1;  // making sure that I perform  binary search odd lengths
        	FoundString = false;
        	for(int i=0;i<n;i++){  // checking if we can form palindromic substring of length = len from string s
        		if(i+len<=n){
        			str="";
        			for(int j=i;j<i+len;j++){
        				str+=s[j];
        			}
        			temp = str;
        			reverse(temp.begin(),temp.end());
        			if(str==temp){   // checking if the substring is palindrome by reversing it and comparing it with its original form
        				ans = str;
        				FoundString = true;
        				break;
        			}
        		}
        		else{
        			break;
        		}
        	}
        	if(FoundString){
        		lo = mid+1;
        	}
        	else{
        		hi = mid;
        	}
        }
        return ans;
    }
    string FindAnsForEven(string s){
        int n = s.length();
    	int lo=1;
        int hi=n/2+1;
        int mid,len;
        string ans="";
        string str;
        string temp;
        bool FoundString;
        while(lo<hi){
        	mid = (lo+hi)/2;
        	len = 2*mid;   // making sure that I perform  binary search even lengths
        	FoundString = false;
        	for(int i=0;i<n;i++){  // checking if we can form palindromic substring of length = len from string s
        		if(i+len<=n){
        			str="";
        			for(int j=i;j<i+len;j++){
        				str+=s[j];
        			}
        			temp = str;
        			reverse(temp.begin(),temp.end());
                    if(str==temp){ // checking if the substring is palindrome by reversing it and comparing it with its original form
        				ans = str;
        				FoundString = true;
        				break;
        			}
        		}
        		else{
        			break;
        		}
        	}
        	if(FoundString){
        		lo = mid+1;
        	}
        	else{
        		hi = mid;
        	}
        }
        return ans;
    }
    string longestPalindrome(string s) {
        string ans1 = FindAnsForOdd(s);
        string ans2 = FindAnsForEven(s);
        return (ans1.length()>=ans2.length())?ans1:ans2;
    }
};

