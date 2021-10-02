// https://www.interviewbit.com/problems/excel-column-title/
// O(logN) Time

string convertToTitle(int n) {
    string ans;
    while (n) {
        ans = char ((n - 1) % 26 + 'A') + ans;
        n = (n - 1) / 26;
    }
    return ans;
}
