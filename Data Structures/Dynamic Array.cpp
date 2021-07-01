/*
Question
    * Declare a 2-dimensional array, arr, of n empty arrays. All arrays are zero indexed.
    * Declare an integer, lastAnswer, and initialize it to 0.
    * There are 2 types of queries, given as an array of strings for you to parse
        1. Querry 1 x y
            1. let idx = ((x(xor)lastAnswer)%n).
            2. Append the integer y to arr[idx].
        2. Querry 2 x y
            1. let idx = ((x(xor)lastAnswer)%n).
            2. Assign the value
                arr[idx][y%size(arr[idx])] to lastAnswer
            3. Store the new value of lastAnswer to an Answer Array
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int qt, x, y;
    int idx, lastAnswer = 0;
    vector<int> la, arr[n];
    for(int i=0; i<queries.size(); i++)
    {
        qt = queries[i][0];
        x = queries[i][1];
        y = queries[i][2];
        idx = (x^lastAnswer)%n;
        if(qt == 1)
            arr[idx].push_back(y);
        else if(qt == 2)
        {
            lastAnswer = arr[idx][y%arr[idx].size()];
            la.push_back(lastAnswer);
        }
    }
    return la;
}


int main(int argc, char *argv[]) 
{
    int n, t, lastAns = 0;
    //Here n is number of elements in vector array
    //t is number of test cases
    cin>>n;
    cin>>t;
    vector<int> *v;
    vector<vector<int>> vec;
    while(t--) {
        v = new vector<int>;
        int a, x, y;
        scanf(" %d %d %d", &a, &x, &y);
        v->push_back(a);
        v->push_back(x);
        v->push_back(y);
        vec.push_back(*v);
    }
    vector<int> answer;
    answer = dynamicArray(n, vec);
    for(int i=0; i<answer.size(); i++)
        std::cout<<answer[i]<<'\n';
    return 0;
}
