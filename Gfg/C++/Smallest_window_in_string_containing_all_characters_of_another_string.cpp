#include<bits/stdc++.h>
using namespace std;
class solution{
    public:

string smallest_window(string s,string pat){
    // m is unordered_map for storing chars of bigger string
    // while p is unordered_map for  chars of small string
    unordered_map<char,int>m;
    unordered_map<char,int>p;
    if(s.length()<pat.length()){
        return "-1";
    }
// stored occurences of elements of pattern in for_pattern map!
    for(int i=0;i<pat.length();i++){
        p[pat[i]]++;
    }

    int start=0;
    int window_size;
    int count=0;
    int ans=INT_MAX;
    int start_index_of_required_window=-1;
    // similarly stored elements of given long string + checking some conditions
    for(int i=0;i<s.length();i++){
        
        // occurrence of element stored in for_long_string map;
        m[s[i]]++;
        // now if for any given element occurrence in long_string map is less than or equal to occurences in pattern
        // => we got one match 
        // for ex: For_pattern have a 4 times but our long_string map have 1 a its means our one char is matched
        // bravo
        // so count++ that takes care of no. of matched characters
            if(m[s[i]]<=p[s[i]] && p.find(s[i])!=p.end()){
                count++;
            }

            //  if number of matched characters are equal to pattern length ==>we got one candidate for ans
            if(count==pat.length()){
                // now contraction starts from  left here initially start==0
                // if any element from left is not present in pattern or is extra i.e. count in long string map
                // is greater than required occurrences in pattern we can simply delete it that is shift our start to next position.
                // side by side we decrease count of extra element from for_long_string map
                while(p.find(s[start])==p.end() || m[s[start]]>p[s[start]]){
                    m[s[start]]--;
                    start++;
                    
                }
               // after contractions from left we got one candidate for ans
                // but we need to minimize it so we keep track of minimum till now
            window_size=i-start+1;
            if(ans>window_size){
                ans=window_size;
                start_index_of_required_window=start; 

            }
            
            }

    }
    return s.substr(start_index_of_required_window,ans);
}
};
int main(){
    
      string main_str;
      string pattern_to_be_searched;
      cin>>main_str>>pattern_to_be_searched;
       
       solution obj;
     string ptr=obj.smallest_window(main_str,pattern_to_be_searched);
     for(int i=0;i<ptr.length();i++){
         cout<<ptr[i];
         
     }
      
      return 0;
}


// example:
// input 
// main_str: perseverance
// pattern_to_be_searched: reva
// output: vera

// How?
// flow of algo
// initially count=0;
// p unordered_map--->  r->1 | e->1 |v->1| a->1
// m unordered_map
// i==0; --> p->1  
// i=1 -->e->1  since e lies in p and its count in m== p ==> count=1;
// i=2 -->r-->1  since r lies in p and its count in m == p ==> count=2;
// i=3 -->s->1  since s lies does not lies in p; ==>count==2 only;
// i=4 -->e->2 since e lies in p  but its count in m >  p ==> count=2 (no change);
// i=5 --> v->1 since v lies in p and its count in m ==  p ==> count=3;
// i=6 --> e-->3 since e lies in p  but its count in m >  p ==> count=3 (no change);
// i=7-->r-->2  since r lies in p but its count in m > p ==> count=3 (no change);
// i=8 --> a-->1 since a lies in p and its count in m== p ==> count=4;
// here count==reva.length()==4;
// got one candidate for ans 
// contractions starts from left of array 
// initially start=0;
// for start==0  i.e. p since 'p' doesnot lies in p unordered_map so we can skip it start=1;
// start==1 i.e. e since count of e in m is greater than required we can skip it   & decrement its count in m start =2; e-->2
// start==2 i.e. r since count of r in m is greater than required we can skip it   & decrement its count in m start =2; r-->1;
// start==3 i.e. s since 's' doesnot lies in p unordered_map so we can skip it start=4;
// start==4 i.e. e since count of e in m is greater than required we can skip it   & decrement its count in m start =5; e-->1;
// start==5 i.e. v since count of v in m & p are same so we can't skip it 
// our window_size==8-5+1==4 & start_index ==start==5 i.e. (vera)
// now from i=9 onwards u can repeat the same alogorithm to get smallest string 

// time-complexity =O(n); 