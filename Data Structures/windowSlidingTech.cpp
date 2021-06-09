#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int windowSlidingMaxSUM(vector<int> arr,int size,int window){
    int sum (0);
    for (int i = 0; i < window; i++){
        sum+= arr[i];
    }
    int max = sum;
    for(int j = window;j<size;j++){
        sum = sum + arr.at(j) - arr.at(j-window);
        max = sum>max? sum:max;
    }
    return max;
    
}





bool windowSlidingStringMatching(string arr,string match){
    int k = match.length();
    for(int i = k;i<arr.length();++i){
        if(arr.substr(i-k,k) == match){
            return true;
        }
    }
    return false;
}




int main(){
    // vector<int> arr {10,20,32,24,51,19,1,23,12,21};

    // cout<<windowSlidingMaxSUM(arr,arr.size(),3);


    string s = "hellomynameisdivyanshu";
    string match = "isd";
    cout<<windowSlidingStringMatching(s,match);
    return 0;
}