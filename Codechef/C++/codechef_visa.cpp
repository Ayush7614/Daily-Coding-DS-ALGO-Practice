#include<iostream>
using namespace std;
void visa(int a,int b,int c,int d, int e, int f){
    string s="NO";
    if(b>=a){
        if(d>=c){
            if(f<=e){
                s="YES";
            }
        }
    }
    std::cout<<s<<endl;

}
int main(){
    int t;
    std::cin>>t;
    while(t--){
        int a,b,c,d,e,f;
        std::cin>>a>>b>>c>>d>>e>>f;
        visa(a,b,c,d,e,f);
        
    }
    return 0;
}