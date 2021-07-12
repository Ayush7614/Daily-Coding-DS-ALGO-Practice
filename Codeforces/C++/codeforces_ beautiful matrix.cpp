#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int arr[5][5],b,c;
    for( int i=0;i<5;i++){
        for( int j=0;j<5;j++){
            std::cin>>arr[i][j];
            if(arr[i][j]==1){
                    b=i;
                    c=j;
            }
        }
    }
    int count = abs(b-2)+abs(c-2);
    std::cout<<count<<endl;
    return 0 ;
}