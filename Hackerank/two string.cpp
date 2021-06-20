#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



string twoStrings(string s1, string s2) {
    
    int arr[26]={0};
    int l1 = s1.length();
    int l2 =   s2.length() ;
    
    int var ;
   
    for (int i = 0 ; i< l1  ; i++){
         var = (s1[i])-97 ;
        arr[var]++ ;   
    }
    
     bool isEqual = true ;
    
    for (int i = 0 ; i<l2 ; i++){
         var = (s2[i])-97 ;
       if(arr[var]){
           isEqual= false;
           return "YES";
           break ;
       }  
    }
    
   
   return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

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
