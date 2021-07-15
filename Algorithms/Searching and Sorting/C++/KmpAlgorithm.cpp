/*CODE DESCRIPTION
KMP Algorithm Implementation in C++

KMP (Knuth Morris Pratt) is an algorithm that prints all occurrences of a pattern from particular text.
When a pattern has a sub-pattern appears more than one in the sub-pattern,
it uses that property to improve the time complexity, also for in the worst case.*/

#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

// create pat[] that tells us the count of characters to be skipped in pattern
void computePatArray(char* pattern, int size_p, int* pat)
{
	// length of the previous longest prefix/suffix
	int len = 0;
	// pat[0] is always 0
	pat[0] = 0;

	// the loop calculates pat[i] for i = 1 to size_p-1
	int i;
	for(i=1;i<size_p;i++)
	{
			if (pattern[i] == pattern[len]) {
				len++;
				pat[i] = len;
			}
			// if pattern[i]!=pattern[len]
			else
			{
				//if len is not equal to 0
				if (len != 0) {
					len = pat[len - 1];
				}
				//if len == 0
				else {
					pat[i] = 0;
					i++;
				}
			}
	}
}

// Prints occurrences of text[] in pattern[]
void KMPSearch(char* pattern, char* text)
{
	int size_p = strlen(pattern); //contain length of pattern array
	int size_t = strlen(text); //contain length of text array

	// create pat[] of same size as of pattern array
	int pat[size_p];

	//calculate pat[] array
	computePatArray(pattern, size_p, pat);

 	// index for text[]
	int i = 0;
	// index for pattern[]
	int j = 0;

	//loop from i = 0 to length of text
	while (i < size_t)
	{
			//if both characters match increment i and j by 1
			if (pattern[j] == text[i]) {
				j++;
				i++;
			}
	    //if we found the complete print the first index(i-j) of it from text array
			if (j == size_p) {
	      printf("Found pattern at index %d\n", i - j);
				j = pat[j - 1];
			}
			// mismatch after j matches
			else if (i < size_t && pattern[j] != text[i]) {
				if (j != 0)
					j = pat[j - 1];
				else
					i++;
			}
	}
}

//MAIN FUNCTION
int main()
{
    int l1,l2,i;

    //user input for text
    char text[l1];
    cout<< "Enter length of text: "; //ask for text length
    cin>>l1;
    cout<< "Enter the text: "; //ask for text input
    for(i=0;i<l1;i++){
        cin>>text[i];
    }

    //user input for pattern
    cout<< "\nEnter length of pattern to be found: "; //ask for pattern length
    cin>>l2;
	char pattern[l2];
    cout<< "Enter the pattern: "; //ask for pattern input
    for(i=0;i<l2;i++){
        cin>>pattern[i];
    }
    cout<<endl;

	// calling function
	KMPSearch(pattern, text);
	return 0;
}

/*
COMPLEXITY:
The time complexity of KMP is O(n)
The space complexity of KMP is O(n)

OUTPUT:
Enter length of text: 16
Enter the text: AABAACAADAABAABA

Enter length of pattern to be found: 4
Enter the pattern: AABA

Found pattern at index 0
Found pattern at index 9
Found pattern at index 12*/
