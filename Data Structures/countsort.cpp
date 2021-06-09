#include<bits/stdc++.h>
using namespace std;




ostream &operator<<(ostream &os, vector<int> arr){
    for (int i = 0; i < arr.size(); ++i){
        os << arr[i] << " ";
    }
    os<<endl;
    return os;
}

void countSort(vector<int> &vec){
    int ma = *max_element(vec.rbegin(),vec.rend());
    // cout<<ma<<endl;
    vector<int> count(ma+1);
    for(int i = 0;i<vec.size();++i){
        count[vec[i]]++;
    }
    // cout<<count<<endl;

    for(int i=1;i<count.size();++i){
        count[i] += count.at(i-1);
    }
   


    vector<int> ne(vec.size()+1);
    for(int i=vec.size()-1;i>=0;i--){
        count[vec.at(i)]--;
        ne[count[vec.at(i)]] = vec.at(i);
    }

    for(int i=0;i<vec.size();i++){
        vec[i] = ne[i];
    }

}


int main(){
    vector<int> vec { 9,1,1,1,0,2,1,3,5,2,3,4,2,8,5,6,3,4,5};
    cout<<vec;
    countSort(vec);
    cout<<vec;
    return 0;
}