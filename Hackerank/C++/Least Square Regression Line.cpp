#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double reg(vector<int>x, vector<int>y)
{
    // mean
    long sum1 = 0;
    for(int i=0; i<x.size(); i++)
        sum1 += x[i];
    double mean1 = (double)sum1/x.size();
    
    long sum2 = 0;
    for(int i=0; i<y.size(); i++)
        sum2 += y[i];
    double mean2 = (double)sum2/y.size();
    
    // sqre sum
    long xsq = 0;
    for(int i=0; i<x.size(); i++)
        xsq += (x[i]*x[i]);
    
    // sum: xy
    long xy = 0;
    for(int i=0; i<x.size(); i++)
        xy += (x[i]*y[i]);
    
    // finding a & b;
    double b = (5.0*xy - sum1*sum2)/(5.0*xsq - sum1*sum1);
    double a = mean2 - b*mean1;
    
    return a + b*80;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    vector<int> x,y;
    
    for(auto i=0; i<5; i++)
    {
        int p, q;
        cin>>p;
        x.push_back(p);
        cin>>q;
        y.push_back(q);
    }
    
    double res = reg(x, y);
    
    printf("%0.3f", res);
    
    return 0;
}
