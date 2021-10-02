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