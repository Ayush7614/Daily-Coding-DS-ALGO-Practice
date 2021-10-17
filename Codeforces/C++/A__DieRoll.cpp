/*
Yakko, Wakko and Dot, world-famous animaniacs, decided to rest from acting in cartoons, and take a leave to travel a bit. Yakko dreamt to go to Pennsylvania, his Motherland and the Motherland of his ancestors. Wakko thought about Tasmania, its beaches, sun and sea. Dot chose Transylvania as the most mysterious and unpredictable place.

But to their great regret, the leave turned to be very short, so it will be enough to visit one of the three above named places. That's why Yakko, as the cleverest, came up with a truly genius idea: let each of the three roll an ordinary six-sided die, and the one with the highest amount of points will be the winner, and will take the other two to the place of his/her dreams.

Yakko thrown a die and got Y points, Wakko — W points. It was Dot's turn. But she didn't hurry. Dot wanted to know for sure what were her chances to visit Transylvania.

It is known that Yakko and Wakko are true gentlemen, that's why if they have the same amount of points with Dot, they will let Dot win.

Input
The only line of the input file contains two natural numbers Y and W — the results of Yakko's and Wakko's die rolls.

Output
Output the required probability in the form of irreducible fraction in format «A/B», where A — the numerator, and B — the denominator. If the required probability equals to zero, output «0/1». If the required probability equals to 1, output «1/1».

Examples
inputCopy
4 2
outputCopy
1/2
Note
Dot will go to Transylvania, if she is lucky to roll 4, 5 or 6 points.

*/
#include <iostream>
using namespace std;

int main() {
	int a,b,gcd,den,m,s,i;
	cin>>a;
	cin>>b;
	if(a>b)
	m=a;
	else
	m=b;
	s=6-m+1;
	for(i=1;i<=6;i++)
	{
	    if(s%i==0 && 6%i==0)
	    gcd=i;
	}
	s=s/gcd;
	den=6/gcd;
	cout<<s<<"/"<<den;
	return 0;
}