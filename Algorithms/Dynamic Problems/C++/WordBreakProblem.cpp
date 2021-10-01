// A famous Dynamic Programming based question to check whether a given string can
// be segmented into space separated words in dictionary
#include <iostream>
#include <string.h>
using namespace std;

int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
						"icecream","and","go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

// Returns true if string can be segmented into space separated
// words, otherwise returns false
bool wordBreak(string str)
{
	int size1 = str.size();
	if (size1 == 0) return true;

	// Create the DP table to store results of subroblems. The value wb[i]
	// will be true if str[0..i-1] can be segmented into dictionary words,
	// otherwise false.
	bool wb[size1 +1];
	memset(wb, 0, sizeof(wb)); // Initialize all values as false.

	for (int i=1; i<=size1; i++)
	{
		
		if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
			wb[i] = true;

		
		if (wb[i] == true)
		{
			
			if (i == size1)
				return true;

			for (int j = i+1; j <= size1; j++)
			{
				
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
					wb[j] = true;

				
				if (j == size1 && wb[j] == true)
					return true;
			}
		}
	}

	
	return false;
}


int main()
{
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}
