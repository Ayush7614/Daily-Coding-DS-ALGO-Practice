/*Maximum Length of Repeated Subarray*/
#include <iostream>
using namespace std;
int lengthArr(int array1[], int array2[])
{
    int output = 0;
    int val[6][6]= {0};
    for (int i = 4; i >= 0; --i)
    {
        for (int j = 4; j >= 0; --j)
        {
            if (array1[i] == array2[j])
            {
                val[i][j] = val[i+1][j+1] + 1;
                if(output < val[i][j])
                {
                    output = val[i][j];
                }
            }
        }
    }
    return output;
}
int main()
{
    int n,m,a[1000],b[1000];
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>b[i];
    }
    cout<<lengthArr(a,b);
    return 0;
}
/*
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
*/
