#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
    given,
        mean = 20 hrs
        std_d = 2 hrs
*/

double normal_dist(double m, double sd, double x)
{
    //return (1/(s*(sqrt(2*3.14))))*(pow(2.17, (-((x-m)*(x-m))/(2*s*s))));
    
    /*
        p = 1/2*(1 + erf((x - m)/(sd*sqrt(2))));
    */
    
    double p = 0.5*(1 + erf((x-m)/(sd*sqrt(2.0))));
    return p;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    double m = 20, sd = 2, x = 19.5, a = 20, b = 22;
    
    double p1 = normal_dist(m, sd, x);
    double p2 = normal_dist(m, sd, b) - normal_dist(m, sd, a);
    
    printf("%0.3f\n%0.3f", p1, p2);
    
    return 0;
}
