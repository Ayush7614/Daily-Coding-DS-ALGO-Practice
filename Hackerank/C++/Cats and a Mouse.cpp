/* Problem Link:
   Ques.
   Two cats and a mouse are at various positions on a line. You will be given their starting positions. Your task is to determine which cat will reach the mouse first, assuming the mouse does not move and the cats travel at equal speed. If the cats arrive at the same time, the mouse will be allowed to move and it will escape while they fight.

   Details:
   You are given q queries in the form of x, y, and z representing the respective positions for cats A and B, and for mouse C. Complete the function to return the appropriate answer to each query, which will be printed on a new line.

   If cat A catches the mouse first, print Cat A.
   If cat B catches the mouse first, print Cat B.
   If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.

   Sample Input 0:
   2
   1 2 3
   1 3 2

   Sample Output 0:
   Cat B
   Mouse C
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    
//finding which cat is nearer to the mouse by taking mod of the difference

if(abs(x-z)>abs(y-z)){      //when distance of cat B from mouse is smaller than cat A   
    return "Cat B";
}

else if(abs(x-z)<abs(y-z)){   //when distance of cat A from mouse is smaller from cat B
    return "Cat A";
}

//if the distance of cat A and cat b from mouse is equal, it escapes
else return "Mouse C";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xyz_temp;
        getline(cin, xyz_temp);

        vector<string> xyz = split_string(xyz_temp);

        int x = stoi(xyz[0]);

        int y = stoi(xyz[1]);

        int z = stoi(xyz[2]);

        string result = catAndMouse(x, y, z);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
