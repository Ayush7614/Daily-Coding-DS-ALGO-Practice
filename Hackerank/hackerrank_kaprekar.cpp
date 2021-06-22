#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    int m=0;
    for(int i =p;i<=q;i++){
        int j=i, count=0;
        while(j>0){
            count++;
            j/=10;            
        }
        long long   a=pow(i,2);
       long    d=pow(10,count);
        long long int  r=a%d;
        long long int  qr=a/d;
         // std::cout<<r<<" "<<qr<<" "<<a<<" "<<d<<" "<<count<<" ";
        if((r+qr)==i){
            std::cout<<i<<" ";
                  

            m++;
        }
        
    }
    if(m==0){
        std::cout<<"INVALID RANGE\n";
    }
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
