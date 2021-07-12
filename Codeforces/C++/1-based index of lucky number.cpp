/*
You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

If we sort all lucky numbers in increasing order, what's the 1-based index of n?

Tavas is not as smart as SaDDas, so he asked you to do him a favor and solve this problem so he can have his headphones back.

Input
The first and only line of input contains a lucky number n (1≤n≤10^9).

Output
Print the index of n among all lucky numbers.

Examples
input
4
output
1
input
7
output
2
input
77
output
6
*/


#include<string>
#include<iostream>
using namespace std;
int main(){
	string num;
	cin >> num;
	int index = 0;
	index = (1 << num.length()) - 2; // no of len-1 digits numbers
	for(int i = num.length() - 1; i >= 0; i--){
		if(num[i] == '7'){
			index += (1 << (num.length() - 1 - i));
		}
	}
	cout << index + 1;
	return 0;
}
