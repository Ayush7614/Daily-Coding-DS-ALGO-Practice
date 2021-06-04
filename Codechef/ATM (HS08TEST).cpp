#include<iostream>
using namespace std;

int main(){
    float balance;
    int amount;
    

    cin>>amount>>balance;


    if(amount%5==0 && amount<=balance-0.50){
    balance=balance-(amount+0.50);
        cout<<balance<<endl;
    }
    else{
        cout<< balance<<endl;
    }
    return 0;
}