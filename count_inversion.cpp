class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   /*  long long mergesort(long long arr[],int l,int r);
long long mrge(long long arr[],int l,int m,int h);*/
       
long long int inversionCount(long long arr[], long long n)
{
    long long rs;
    rs=mergesort(arr,0,n-1);
    
    return rs;
}

long long cnt=0;
long long mergesort(long long arr[],int lf,int rf)
{
    if(rf>lf)
    {
        long long f=0;
        int m=lf+(rf-lf)/2;
        f=mergesort(arr,lf,m);
        f=mergesort(arr,m+1,rf);
        f=mrge(arr,lf,m,rf);
        return f;
    }
}

long long  mrge(long long arr[],int l,int m,int h)
{
    
    int n1=m-l+1,n2=h-m;
    long long left[n1],right[n2];
    for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
    for(int j=0;j<n2;j++)
    right[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        { arr[k++]=left[i++];
        /*cnt++;*/}
        else {arr[k++]=right[j++];
       // cout<<i<<endl;
        cnt+=n1-i;}
       /* cout<<n1<<" "<<i<<" "<<left[i+1]<<" "<<right[j-1]<<" "<<cnt<<endl;*/
    }
    while(i<n1)
    {
    arr[k++]=left[i++];
    }
    while(j<n2)
    arr[k++]=right[j++];

    return cnt;
}
    

};
