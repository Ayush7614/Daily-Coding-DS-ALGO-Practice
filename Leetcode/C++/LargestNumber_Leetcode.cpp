# include<bits/stdc++.h>

using namespace std;

int cmp(string x, string y)
{
    string a=x.append(y);
    string b=y.append(x);

    if(a>b)
    {
        return 1;
    }
    return 0;
}
string largestNumber(vector<int>& A)
{
    int n=A.size(), c=0;
    vector<string> v, vv;
    for(int i=0;i<n; i++)
    {
        if(A[i]==0)
        {
            c++;
        }
        string x=to_string(A[i]);
        v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);
    string s="";
    for(int i=0;i<n; i++)
    {
        s+=v[i];
    }
    if(c==n)
        return "0";
    return s;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i < n; i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    string res = largestNumber(v);
    cout<<res<<endl;
    return 0;
}

