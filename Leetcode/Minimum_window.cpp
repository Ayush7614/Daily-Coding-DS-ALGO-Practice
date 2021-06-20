// Minimum Window Substring
// Given two lowercase alphabet strings a and b, return the length of a minimum substring in a that contains all the characters of b.
// If no such substring exists, return -1.
// Input
// a = "qthequickbrownfox"
// b = "qown"
// Output
// 10

int solve(string a, string b) {
    // Variables to keep track of the sliding window
    // and the matched state
    int start = 0, minLen = numeric_limits<int>::max();
    int fullyMatched = 0, n = a.size();

    // Hashmap to cache the character counts in "b"
    unordered_map<char, int> alphas;

    // 1. Cache the character counts in the string "b"
    for (auto &ch : b) {
        alphas[ch]++;
    }

    // 2. start is the beginning of the sliding window
    // and end is the end of the window
    for (int end = 0; end < n; ++end) {
        // 3. Process the current character
        char current = a[end];

        // 4. Is it a part of the string "b" ?
        if (alphas.find(current) != alphas.end()) {
            // 4a. If so, decrement the count
            // in the hash map since we have
            // a partial match
            alphas[current]--;

            // 4b. Have we fully matched all
            // the occurences of the character
            // in the substring "b" ?
            if (alphas[current] == 0) {
                // If so increment the
                // number of fully matched
                // characters
                fullyMatched++;
            }
        }

        // 5. If we have found all the characters
        // of the string "b" in the current window
        // Update the result and shrink the window
        // as much as possible since we want the
        // minimum window length
        while (fullyMatched == alphas.size()) {
            // 5a. Update the result before shrinking
            minLen = min(minLen, end - start + 1);

            // 5b. Shrink the window
            char previous = a[start];
            start++;

            // 5c. Is the character we removed from
            // the window a matching character?
            if (alphas.find(previous) != alphas.end()) {
                // First check if it was a fully matched
                // character
                if (alphas[previous] == 0) {
                    // If so, that character can no longer
                    // be fully matched in the window
                    fullyMatched--;
                }

                // Increase the count of the character in
                // the hashmap
                alphas[previous]++;
            }
        }
    }

    // 6. Return the appropriate result
    return minLen == numeric_limits<int>::max() ? -1 : minLen;
}
// Driver code
int main()
{
    string a = "qthequickbrownfox";
    string pat = "qown";
 
    cout << "Smallest window is : \n"
         << solve(a, b);
    return 0;
}
