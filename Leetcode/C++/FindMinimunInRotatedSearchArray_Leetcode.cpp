# include<bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums)
{
    int n=nums.size();

    if(n==1)
    {
        return nums[0];
    }
    else if(n==2)
    {
        return min(nums[0],nums[1]);
    }
    else if(n==3)
    {
        int m=min(nums[0],nums[1]);
        return min(m,nums[2]);
    }
    else
    {
        int l=0, r=n-1, res;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] && mid>0 && mid<(n-1))
            {
                res=mid+1;
                break;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1] && mid>0 && mid<(n-1))
            {
                res=mid;
                break;
            }
            else if(nums[mid]<nums[l])
            {
                r=mid;
            }
            else if(nums[mid]>nums[r])
            {
                l=mid;
            }
            else
            {
                res=-1;
                break;
            }
        }
        if(res==-1)
        {
            return nums[0];
        }
        else
        {
            return nums[res];
        }
    }

}
int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int result = findMin(v);
    cout<<result<<endl;
    
}

