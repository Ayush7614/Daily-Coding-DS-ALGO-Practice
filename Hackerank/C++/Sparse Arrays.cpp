#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;
int readline(char *str) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

map<string, int> m;
int main(int argc, char *argv[]) {
    int n, q;
    string str(24, 0);
    scanf("%d", &n);
    while(n--) {
        cin >> str;
        m[str]++;
    }

    scanf("%d", &q);
    while(q--) {
        cin >> str;
        cout << m[str] << endl;
    }

    return 0;
}
