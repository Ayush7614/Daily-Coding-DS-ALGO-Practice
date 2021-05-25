class NthNatural {
    long findNth(long N)
    {
        //code here
       long m=1;
       long sum=0;
       while(N!=0)
       {
           long d=N%9;
           N=N/9;
           sum+=d*m;
           m*=10;
       }
       return sum;
    }
}