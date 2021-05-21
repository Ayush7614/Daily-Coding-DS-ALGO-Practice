// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int isleap(long long Y) {
    if (Y%4==0 && Y%100!=0 || Y%400==0)
        return 1;
    return 0;
}

int num(int m ,long long y) {
    int num[] = {31, 28+isleap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return num[m];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long Y1, Y2;
        int M1, M2, D1, D2, day=1, count = 0;
        cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
        for (int i=0; i<(Y1-1900)%400; i++)
            day = (day + 1 + isleap(i+1900))%7;;
        for (long long y=Y1; y<=Y2; y++) {
            for (int m=1; m<=12; m++) {
                if ((y==Y1 && m < M1) || (y==Y2 && m>M2)) {
                    day = (day + num(((m-1)+12)%12, y))%7;
                    continue;
                }
                if (y==Y1 && m==M1) {
                    if (D1==1 && day==0)
                        count++;
                    day = (day + num(((m-1)+12)%12, y))%7;
                    continue;
                }
                if (day==0)
                    count++;
                day = (day + num(((m-1)+12)%12, y))%7;                
            }
        }
        cout << count << endl;
    }
    return 0;
}
