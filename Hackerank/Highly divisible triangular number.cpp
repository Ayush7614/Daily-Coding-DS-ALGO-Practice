// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem

#include <iostream>
#include <vector>
using namespace std;

int no_of_divisiors(int n) {
    int count = 0;
    for (int i = 1; i*i <= n; i++) {
        if (i*i == n)
            count++;
        else if (n%i == 0) {
            count += 2;
        }
    }
    return count;
}

int main() {
    int div[1001];
    int temp = 0, box = 0;
    for (int i = 1; i <= 1000; i++) {
        while (temp <= i) {
            box++;
            temp = no_of_divisiors(box*(box + 1) / 2);
        }
        div[i] = box * (box + 1) / 2;
    }
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << div[N] << endl;
    }
    return 0;
}
