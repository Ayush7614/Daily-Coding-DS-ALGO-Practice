// C program for Pascal’s Triangle
// A O(n^2) time and O(n^2) extra space
// method for Pascal's Triangle
void printPascal(int n)
{
// An auxiliary array to store
// generated pscal triangle values
int arr[n][n];

// Iterate through every line and print integer(s) in it
for (int line = 0; line < n; line++)
{
	// Every line has number of integers
	// equal to line number
	for (int i = 0; i <= line; i++)
	{
	// First and last values in every row are 1
	if (line == i || i == 0)
		arr[line][i] = 1;
	// Other values are sum of values just
	// above and left of above
	else
		arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
	printf("%d ", arr[line][i]);
	}
	printf("\n");
}
}
// Driver code
int main()
{
int n = 5;
	printPascal(n);
	return 0;
}


// in c language 