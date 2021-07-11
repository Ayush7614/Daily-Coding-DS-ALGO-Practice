#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void convert(string s, int numRows) {
        char arr[numRows][2*numRows];
        int j=0,i=0,k=0;
        while(k<s.size()){
            for(i=0;i<numRows;i++){
                arr[i][j]=s[k];
               // std::cout<<arr[i][j]<<endl;
             //  std::cout<<i;
               k++;
            }

           
            //std::cout<<k<<" "<<i<<endl;
            
            j=j+1;
            
            for(;j<numRows;j++){
                arr[i-j-1][j]=s[k++];
            }
            //k=k-1;
            j=j-1;
            
        }
        for(int r=0;r<numRows;r++){
            for(int u=0;u<j;u++){
                std::cout<<arr[r][u]<<" ";
            }
            std::cout<<endl;
        }
        //std::cout<<j;
        string m;
        int a=0;
        for(int av =0;av<numRows;av++){
            for(int ja=0;ja<j;ja++){
                m[a++]=arr[av][ja];
                //std::cout<<arr[av][ja];
            }
        }
        
        
    }

int main(){
    
    string s;
    getline(cin,s);
    int n;
    std::cin>>n;
    convert(s,n);
    return 0;

}
