#include <iostream>
#include <unordered_set>
using namespace std;
 
// Data structure to store a pair (or use `std::pair`)
struct Pair {
    int x, y;
};
 
// Function to find all pairs that are a mirror of each other.
// Here, we are creating a template that deduces the array size
// from its declared type
template<typename T, size_t n>
void findPairs(T const(& pair)[n])
{
    // create an empty set of strings
    unordered_set<string> set;
 
    // do for each pair
    for (int i = 0; i < n; i++)
    {
        // construct a pair `(x, y)` from `pair[i]`
        string p = "{" + to_string(pair[i].x) + ", " +
                        to_string(pair[i].y) + "}";
 
        // insert the current pair into the set
        set.insert(p);
 
        // construct a mirror pair `(y, x)` of `pair[i]`
        string reverse_pair = "{" + to_string(pair[i].y) + ", " +
                                    to_string(pair[i].x) + "}";
 
        // if the mirror pair is seen before, print the pairs
        if (set.find(reverse_pair) != set.end()) {
            cout << p << " | " << reverse_pair << endl;
        }
    }
}
 
int main()
{
    Pair pair[] = { {3, 4}, {1, 2}, {5, 2}, {7, 10}, {4, 3}, {2, 5} };
    findPairs(pair);
 
    return 0;
}