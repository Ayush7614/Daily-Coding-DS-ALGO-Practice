
==============================================================================================================================================================================
==============================================================================================================================================================================
    
given an array of non-negative integers, count the number of unordered pairs of array elements such that their bitwise AND(&) is a power of 2.
for ex: for array [10,7,2,8,3]; there are 6 unordered pairs;
explaination:
10&7=2
10&2=2;
10&8=2;
10&3=2;
7&2=2;
2&3=2;

Constraints:
1<=n<=2*10^5
0<=ar[i]<=2^12
This was asked in Hackerank intermediate certification Test.I failed to come up with linear time solution.
    
==============================================================================================================================================================================
==============================================================================================================================================================================



long countPairs(const vector<int> &arr)
{
    long ans = 0;
    int mx = 0;
    map<int, int> mp;
    for (int ai : arr)
    {
        mp[ai]++;
        mx = max(mx, ai);
    }
    for (int i = 0; i <= mx; ++i)
    {
        if (!mp.count(i))
            continue;
        for (int j = i; j <= mx; ++j)
        {
            if (!mp.count(j))
                continue;
            // cout<<i<<':'<<mp[i]<<','<<j<<':'<<mp[j]<<'\n';
            if (__builtin_popcountll(i & j) == 1)
            {
                if (i == j)
                    ans += ((long(mp[i]) * (mp[i] - 1)) / 2);
                else
                    ans += (long(mp[i]) * mp[j]);
            }
        }
    }
    return ans;
}
