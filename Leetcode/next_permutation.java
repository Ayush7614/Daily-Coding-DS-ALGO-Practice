//function in java which accepts array and return the next possible permutation
class Solution {
    public void nextPermutation(int[] array) {
        int n=array.length;
        int k=0;
        int j;
        for( j=n-1;j>0;j--)
        {
            if(array[j]>array[j-1])
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
            for(int i=0;i<n/2;i++)
            {
                int temp=array[i];
                array[i]=array[n-1-i];
                array[n-i-1]=temp;
            }
        }
        else
        {
            int x=j-1;
            for( k=n-1;k>x;k--)
            {
                if(array[k]>array[x])
                {
                    break;
                }                
            }
            int temp =array[x];
            array[x]=array[k];
            array[k]=temp;
            Arrays.sort(array, j, n);
        }
     
        for(int s=0;s<n;s++)
        {
            System.out.print(array[s]+" ");
        }   
    }
}