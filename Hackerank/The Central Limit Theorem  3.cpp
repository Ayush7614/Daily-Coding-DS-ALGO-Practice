#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double normal_dist(double m, double sd, double x)
{   
    double p = 0.5*(1 + erf((x-m)/(sd*sqrt(2.0))));
    return p ; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double mean = 500;
    double std = 80;
    int n = 100;
    double zScore = 1.96;
    double marginOfError = zScore * std/sqrt(n);
    printf("%0.2f\n%0.2f", mean - marginOfError, mean + marginOfError);       
    return 0;
}
