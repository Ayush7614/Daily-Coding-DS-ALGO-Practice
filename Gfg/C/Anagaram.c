/* 
Implementation of Anagram in C programming.
An anagram of a string is another string that contains the same characters, only the order of characters can be different.
This program takes two strings from the user and checks whether they are anagrams of each other or not.
*/
#include<stdio.h>
#include<string.h>
// Function for swapping character
char swap(char* p, char* q) {
	char t = *p;
	*p = *q;
	*q = t;
}

// Bubble sort for sorting  characters of string in ascending order
void bubble_sort(char b[], int n) {
	int i, j;
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - i - 1;j++)
			if (b[j] > b[j + 1])              // not in ascending order 
				swap(&b[j], &b[j + 1]);   //function call for swapping charaters
	}
}
int main(){
	char str1[100], str2[100];
	int l1 = 0, l2 = 0, status = 0, i;
	printf("Enter the first string:");
	gets(str1);
	printf("Enter the second string: ");
	gets(str2);
	// length of strings
	l1 = strlen(str1); 
	l2 = strlen(str2);
	// If strings of different length they're not anagrams
	if (l1 != l2) { 
		printf("Given strings are not anagram of each other\n");
		return 0;
	}
	// string sorting
	bubble_sort(str1, l1);
	bubble_sort(str2, l2);

	// checking for anagram
	for (i = 0; i < l1;i++) {
		if (str1[i] != str2[i]) {     // Not anagrams
			status = 1; 
			break;
		}
	}
	if (!status)
		printf("Given strings are Anagrams of each other\n");
	else
		printf("Given strings are Not Anagram of each other\n");
	return 0;
}

/*
Sample input1:
Hello
Holel
Output:
Given strings are Anagrams of  each other
-----------------------------------------------
Sample input2:
Hello
Hi
Output:
Given strings are Not Anagrams of  each other
-----------------------------------------------
Sample input3:
Hi
Hello
Output:
Given strings are Not Anagrams of  each other
*/
