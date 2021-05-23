#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double l1 = 0.88, l2 = 1.55;
    
    double p1 = 160 + 40*(l1 + (l1*l1));
    double p2 = 128 + 40*(l2 + (l2*l2));
    
    printf("%0.3f\n%0.3f", p1, p2);
    
    return 0;
}
