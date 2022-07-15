    
    /*

    Given a binary matrix.
    The problem is to find the largest area rectangular sub-matrix with equal number of 1’s and 0’s.

    IDEA : Change all 0s to -1;
           Then, the question reduces to Largest Sub-Matrix, wheres sum of elements is 0.

    */


    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    bool sumZero(int temp[],int n,int* bottom,int* top)  {

            int max_length=0;
            int sum=0;
            map<int,int> presum;

            for(int i=0;i<n;i++) {

                sum+=temp[i];      //taking sum of all traversed elements

                if(temp[i]==0&&max_length==0) {  //if an element is 0
                    *top=i;
                    *bottom=i;
                    max_length=1;
                }


                if(sum==0) {        //if sum==0
                    if(max_length<i+1) {    //allocating parameters, to top and bottom
                        *top=0;                // sum was initialised from starting as 0, hence the *top=0;
                        *bottom=i;
                    }
                    max_length=i+1; //increasing max_length of sub-array sum=0;
                }

                if(presum.find(sum)!=presum.end()) {

                    int old=max_length;

                    max_length = max(max_length,i-presum[sum]);

                    if(old<max_length) {
                        *bottom=i;
                        *top=presum[sum]+1;
                    }

                }

                else {
                    presum[sum]=i;
                }

            }


        return (max_length!=0);

    }

    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        std::ios::sync_with_stdio(false);
        int T=1;
        //cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n,m;

            cin>>n>>m;
            //cout<<n<<m;

            int a[n][m];

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cin>>a[i][j];
                    if(a[i][j]==0) {
                        a[i][j]--;
                    }
                 //cout<<a[i][j]<<" ";
                }
                //cout<<endl;
            }


            int res=INT_MIN;

            int fleft,fright,ftop,fbottom;

            int temp[n];

            for(int i=0;i<m;i++) {                
                memset(temp,0,sizeof(temp));
                for(int j=i;j<m;j++) {

                    int area=1;

                    int left=i,right=j,bottom=0,top=0;

                    for(int k=0;k<n;k++) {
                        temp[k]+=a[k][j];
                    }

                    int y = sumZero(temp,n,&bottom,&top);

                    area = (bottom-top+1)*(right-left+1);
                    
                   // cout<<area<<endl;

                  if(res<area&&y) {
                        res=area;
                        fleft=left;
                        fright=right;
                        fbottom=bottom;
                        ftop=top;
                    }

                }
            }

            cout<<res<<endl;

           // cout<<ftop<<" "<<fbottom<<" "<<fright<<" "<<fleft<<endl;


        }
        return 0;
    }