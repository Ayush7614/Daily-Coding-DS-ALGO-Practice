#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double normal_dist(double m, double sd, double x)
{
    //return (1/(s*(sqrt(2*3.14))))*(pow(2.17, (-((x-m)*(x-m))/(2*s*s))));
    
    /*
        p = 1/2*(1 + erf((x - m)/(sd*sqrt(2))));
    */
    
    double p = 0.5*(1 + erf((x-m)/(sd*sqrt(2.0))));
    return p*100; // for percentage
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    double m = 70, sd = 10;
    
    double p1 = double(100) - normal_dist(m, sd, 80);
    double p2 = double(100) - normal_dist(m, sd, 60);
    double p3 = normal_dist(m, sd, 60);
    
    printf("%0.2f\n%0.2f\n%0.2f", p1, p2, p3);
    
    return 0;
}
