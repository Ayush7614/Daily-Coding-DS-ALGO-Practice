#include <iostream>
using namespace std;
int lastIndex(int a[], int g, int x) {
	if (g == 0) {
		return -1;
	}
	int ans = lastIndex(a + 1, g - 1, x);
	if (ans == -1) {
		if (a[0] == x) {
			return 0;
		} else {
			return -1;
		}
	}

	return ans + 1;
}

int main() {
	int n, x, a[200];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	cout << lastIndex(a, n, x);
}

/*Example
Input:
5 
5 6 7 5 2
5
Output:
3
*/


