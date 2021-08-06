/*
Problem Link:
https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

Ques.
When a contiguous block of text is selected in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, each word is highlighted independently.
There is a list of 26 character heights aligned by index to their letters. For example, 'a' is at index 0 and 'z' is at index 25. There will also be a string. Using the letter heights given, determine the area of the rectangle highlight in mm^2 assuming all letters are 1mm wide.

Sample Input:
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc

Sample Output 0:
9

Explanation 0:
We are highlighting the word abc:

Letter heights are a=1, b=3 and c=1. The tallest letter, b, is 3mm high. The selection area for this word is 3.1.3mm= 9mm^3.
Note: Recall that the width of each character is 1mm.

*/

#include <bits/stdc++.h>
#include<string.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */

int designerPdfViewer(vector<int> h, string word) {
    int size=word.size(),i;
    vector<int> data;
    data.resize(size);

    for(i=0;i<size;i++){      //filling the contents of vector data to find the index of alphabets
      data[i] = word[i]-'a';
    } 
    
    int max= h[data[0]];     //setting max to the height of first element present in data
    
    //finding max height from all the alphabets present in string word
    for(i=1;i<size;i++){                
        if(h[data[i]]>max) max=h[data[i]];
    }

    //area is given as max height of word * the breadth (which is given by size of word)
    int area = max*size;

    return area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

