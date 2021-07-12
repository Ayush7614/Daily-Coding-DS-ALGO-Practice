#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    double p = 0.333;
    double q = 1 - p;
    
    double g_prob = 0.0;
    
    for(auto i=1; i<=5; i++)
    {
        g_prob += pow(q, i-1)*p;
    }
    
    printf("%0.3f", g_prob);
    
    return 0;
}
