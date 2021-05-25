class  RearrangingArray
{ 
    void prank(long[] a, int n)  
    { 
        // code here
       long t[] = new long[n];
        for( int i=0;i<n;i++)
        {
           t[i] = a[i];
        }
        for(int i=0;i<n;i++)
        {
            a[i] = t[((int)a[i])];
        }
    }
} 
