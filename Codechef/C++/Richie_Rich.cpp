#include <iostream>
using namespace std;

int main()
{
	// your code goes here
	int T, A, B, X;
	int W = 0;
	int Ans = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B >> X;
		W = B - A;
		Ans = W / X;
		cout << Ans << endl;
	}
	return 0;
}