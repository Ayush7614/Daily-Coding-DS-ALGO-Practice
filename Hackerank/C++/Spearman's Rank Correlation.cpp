#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


/*
    rank = 1 - (6*summation(x[i]-y[i])^2)/n*(n^2-1);
*/

vector<double> build_rank(double x[], int n)
{
    map<double, int> m1;
    vector<double> x1(n);
    
    for(auto i=0; i<n; i++) 
    {
        m1.insert(make_pair(x[i], i));
    }
    
    int rank = 0;
    for(auto it : m1)
    {
        x1[it.second] = rank++;
    }
    
    return x1;
}
double supermans_rank(double x[], double y[], int n)
{       
    double num = 0;
    
    auto rank_x = build_rank(x, n);
    auto rank_y = build_rank(y, n);
    
    for(auto i=0; i<n; i++)
    {
        num += ((rank_x[i]-rank_y[i])*(rank_x[i]-rank_y[i]));
    }
    num *= 6.0;
    
    double den = (n*(n*n - 1));
    
    double res = num/den;
    
    res = 1 - res;
    
    return res;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n; cin>>n; double x[n+4], y[n+4];
    
    for(auto i=0; i<n; i++)
    {
        cin>>x[i];
        //sum1 += x[i];
    }
    
    for(auto i=0; i<n; i++)
    {
        cin>>y[i];
        //sum3 += y[i];
    }
    
    double supermans_rank_coeff = supermans_rank(x, y, n);
    
    printf("%0.3f", supermans_rank_coeff);

    
    return 0;
}
