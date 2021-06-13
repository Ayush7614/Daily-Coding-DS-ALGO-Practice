#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
 
void MaxSubArray(int A[], int aux[], int i, int j, int difference) {
    int max_as_yet = A[i];
    int max_end = A[i];
    aux[i] = A[i];
 
    for (int k = i + difference; k != j; k += difference) {
        max_end = max(A[k], max_end + A[k]);
        max_as_yet = max(max_as_yet, max_end);
        aux[k] = max_as_yet;
    }
}
 
void fillArray(int A[], int max_left[], int max_right[], int min_left[], int min_right[], int n) {
    MaxSubArray(A, max_left, 0, n - 1, 1);
    MaxSubArray(A, max_right, n - 1, 0, -1);
 
    transform(A, A + n, A, negate<int>());
 
    MaxSubArray(A, min_left, 0, n - 1, 1);
    MaxSubArray(A, min_right, n - 1, 0, -1);
    
    transform(min_left, min_left + n, min_left, negate<int>());
    transform(min_right, min_right + n, min_right, negate<int>());
    transform(A, A + n, A, negate<int>());
}

int CalcAbsDiff(int A[], int n) {
    int max_left[n], max_right[n], min_left[n], min_right[n];
    fillArray(A, max_left, max_right, min_left, min_right, n);
    
    int abs_diff = INT_MIN;
    
    for (int i = 0; i < n - 1; i++) {
        abs_diff = max(abs_diff, max(abs(max_left[i] - min_right[i+1]), abs(min_left[i] - max_right[i+1])));
    }
    
    return abs_diff;
}
 
int main() {
    int A[] = { -3, -2, 6, -3, 5, -9, 3, 4, -1, -8, 2 };
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "The Maximum Absolute difference is " << CalcAbsDiff(A, n);
    
    return 0;
}
