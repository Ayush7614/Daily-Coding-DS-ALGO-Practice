#include <bits/stdc++.h>
using namespace std;

int check(string n){
    int size = n.size();
    int flag = 0;
    if(n[0] != '<'){
        return 0;
    }
    else if(n[1] != '/'){
        return 0;
    }
    else if(size <= 3){
        return 0;
    }
    else if(n[size-1] != '>'){
        return 0;
    }
    else{
        for(int i =2 ;i < size-1;i++){
            if(!((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= '0' && n[i] <= '9'))){
                return 0;
            }
        }
    }
    return 1;
}


int main() {
	int t;
	cin >> t;
	while(t--){
	    string n ;
	    cin >> n;
	    if(check(n)){
	        cout << "success" << endl;
	    }
	    else {
	        cout << "error" << endl;
	    }
	}
	return 0;
}
