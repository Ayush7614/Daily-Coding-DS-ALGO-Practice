
// Lapindrome
// Check if both halves of the string have same set of characters

#include <stdio.h>
using namespace std;

int main(void)
{
	int n;
	// Taking input n for string size
	printf("Enter the size of string : ");
	scanf("%d",&n);
	
	char str[n];

	// Taking string input
	printf("Enter the string : ");
	scanf("%s",&str);

	// Creating two arrays that will count the frequency of characters of both halves
	int count1[26] = {0} ,count2[26] = {0};

	// Using hashing to store the number of times character have been found
	for(int i=0;i<n/2;i++){
		count1[str[i]-'a']++;
		count2[str[n-i-1]-'a']++;
	}

	// Checking whether the number of characters and their frequency in both halves is same or not.
	// If different then output "NO" and if same output "YES".
	for(int i=0;i<26;i++){
		if(count1[i]!=count2[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
