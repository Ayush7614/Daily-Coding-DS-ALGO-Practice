#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double pearson(double x[], double y[], int n, double mean1, double std1, double mean2, double std2)
{
    double num = 0;
    for(auto i=0; i<n; i++)
    {
        num += ((x[i]-mean1)*(y[i]-mean2));
    }
    double den = (n*std1*std2);
    double res = num/den;
    return res;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin>>n; double x[n+4], y[n+4]; double sum1=0, sum2=0, sum3=0, sum4=0;
    for(auto i=0; i<n; i++)
    {
        cin>>x[i];
        sum1 += x[i];
    }
    double mean1 = (double)(sum1/n);   
    for(auto i=0; i<n; i++)
    {
        sum2 += (((double)x[i]-mean1)*((double)x[i]-mean1));
    }   
    double std1 = (double)sqrt(sum2/n);
    for(auto i=0; i<n; i++)
    {
        cin>>y[i];
        sum3 += y[i];
    }
    double mean2 = (double)(sum3/n);   
    for(auto i=0; i<n; i++)
    {
        sum4 += (((double)y[i]-mean2)*((double)y[i]-mean2));
    }   
    double std2 = (double)sqrt(sum4/n);
    double pearson_coeff = pearson(x, y, n, mean1, std1, mean2, std2);
    printf("%0.3f", pearson_coeff);    
    return 0;
}
