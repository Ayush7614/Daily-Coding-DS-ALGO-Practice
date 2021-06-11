// count_occurrences of element can be solved using linear search in O(n) time .
// but better approach can be followed when sorted array is given i.e. BINARY SEARCH
// APPROACH
// using binary search we can find first index of element & last index of element & total number
// of occurences will be lastindexx-firstindex+1

#include<bits/stdc++.h>
using namespace std;
int first_occurrence(vector<int>v,int k){
    int s=0;
    int e=v.size()-1;
    int fo=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==k){
            // got one position of k
            // now inorder to find first occurrence search in left search space .
            fo=mid;
            e=mid-1;
        }
        else if(v[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return fo;
}
int last_occurrence(vector<int>v,int k){
    int s=0;
    int e=v.size()-1;
    int lo=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==k){
            // got one position of k
            // now inorder to find last occurrence search in right search space .
            lo=mid;
            s=mid+1;
        }
        else if(v[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return lo;
}


int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int input ;
        cin>>input;
        v.push_back(input);
    }
    // element whose occurrences is to be determined
    int k;
    cin>>k;
int first_index=first_occurrence(v,k);
int last_index=last_occurrence(v,k);
int total_no_of_occurences=last_index-first_index+1;
cout<<total_no_of_occurences<<endl;

}
