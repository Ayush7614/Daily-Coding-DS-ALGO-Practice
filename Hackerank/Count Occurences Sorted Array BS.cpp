// C++ program to count occurrences of an element in a sorted array.
# include <bits/stdc++.h>
using namespace std;


int count(int a[], int element, int n)
{
	int *low = lower_bound(a, a+n, element);
	if (low == (a + n) || *low != element)
		return 0;
	int *high = upper_bound(low, a+n, element);
	return high - low;
}


int main()
{
int a[] = {1, 1, 2, 2, 2, 3, 4, 5};
int element = 2; // Element to be counted in a[]
int n = sizeof(a)/sizeof(a[0]);
int c = count(a, element, n);
printf(" %d occurs %d times ", element, c);
return 0;
}
