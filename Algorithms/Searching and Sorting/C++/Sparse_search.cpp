// Approach 
// given  sorted array of string & key to be searched
// here since array is sorted we ll be using binary search along with linear search for selective cases.

#include<bits/stdc++.h>
using namespace std;

int Sparse_search(vector<string>v,int n, string to_be_searched){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int left_of_mid=mid-1;
        int right_of_mid=mid+1;
        // if at mid index blank string is given how we ll know whether to go left or right?
         if(v[mid]==""){
            // we will do linear search to both sides of mid till we find any non-empty string
            
            while(1){
                // if any either left or right crossed to limit of search space 
                if(left_of_mid<s && right_of_mid>e){
                    return -1;
                }
                // if to left of mid we find a non empty string we will update our mid
                else if(left_of_mid>=s && v[left_of_mid]!=""){
                    mid=left_of_mid;
                    break;
                }
                 // if to right of mid we find a non empty string we will update our mid
                else if(right_of_mid<=e && v[right_of_mid]!=""){
                    mid=right_of_mid;
                    break;
                }

                left_of_mid--;
                right_of_mid++;
            }

        }
        // normal binary search operations.
        if(v[mid]==to_be_searched){
            return mid;
        }
        else if(v[mid]<to_be_searched){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int main(){
    // given sorted vector of string
    vector<string>str={"apple","","","cherry","date","mango","","","watermelon"};
    
    int n=str.size();
    // key is the value to be searched
    string key;
    cin>>key;
    int position=Sparse_search(str,n,key);
    cout<<position<<endl;
}

// if key ==apple
// s=0 , e=8 =>mid=4
// str[4]!=key
// key<str[4]
// search to left of mid ==>e=mid-1;
// e=3

// mid=1
// since str[1]==""empty string
// do linear search to left & right of string ==>l=0 && r=2;
// we have found a now empty string at 0th index so mid now=0;
// now str[mid]==key hence mid is our ans.
// TIME COMPLEXITY
// mostly time complexity of this code is better than linear search
// except in worst case when it approaches O(n);