#include<bits/stdc++.h>
using namespace std;




ostream &operator<<(ostream &os, vector<int> arr){
    for (int i = 0; i < arr.size(); ++i){
        os << arr[i] << " ";
    }
    os<<endl;
    return os;
}


void countSortForRadix(vector<int> &vec,int n){

    vector<int> count(10);
    for(int i = 0;i<vec.size();++i){
        count[(vec[i]/n)%10]++;
    }

    for(int i=1;i<count.size();++i){
        count[i] += count.at(i-1);
    }
   


    vector<int> ne(vec.size()+1);
    for(int i=vec.size()-1;i>=0;i--){
        count[(vec.at(i)/n)%10]--;
        ne[count[(vec.at(i)/n)%10]] = vec.at(i);
    }

    for(int i=0;i<vec.size();i++){
        vec[i] = ne[i];
    }

}


void radixsort(vector<int> &vec){
    int ma = *max_element(vec.begin(),vec.end());
    for(int pos = 1;ma/pos >0; pos*=10){
        countSortForRadix(vec,pos);
    }
}



int main(){
    vector<int> vec { 32,112,12,2,49,789,15,152,148,100,120};
    cout<<vec;
    radixsort(vec);
    cout<<vec;
    return 0;
}
