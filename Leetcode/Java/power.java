class Solution {
    public double myPow(double x, int n) {
        
        double ans;
        if(x <= 0.00001 && x>0)
            return 0.0;
        if(x == 1)
            return 1.0;
        if(x == -1)
        {
            return (n%2 == 0) ? 1.0 : -1.0;
        }
        if(n < -100 )
            return 0.0;
        ans = (n >= 0 )?positive(x,n) : (double)1/positive(x,n*-1);
        return ans;
    }
    double positive(double x,int n)
    {
        if(n == 1)
            return x;
        if(n == 0)
            return 1.0;
        return x*positive(x,n-1);
    }
    
}

///

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
    ///
