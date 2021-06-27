#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int a , b ,x;
	    cin >> a >> b >> x;
	    int l = b -a;
	    cout << l/x << endl;
	}
	return 0;
}