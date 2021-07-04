/*Test-case-1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Test-case-2:
Input: heights = [2,4]
Output: 4
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          stack<int>st;
        heights.push_back(0);
        int ret=0;
            for(int i = 0; i < heights.size(); i++)
            {
                while(st.size() > 0 && heights[st.top()] >= heights[i])
                {
                    int vertical = heights[st.top()];
                    st.pop();

                    int right_upper_bound = st.size() > 0 ? st.top() : -1;
                    int horizontal=(i-right_upper_bound-1);
                    if(vertical * horizontal  > ret)
                        ret = vertical * horizontal;
                }
                st.push(i);
            }

            return ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		int n;
		cin>>n;
		int i,x;
    vector<int>a;
		for(i=0;i<n;i++)
		{
			cin>>x;
      a.push_back(x);

		}

    Solution obj;
    int ans=obj.largestRectangleArea(a);
    cout<<ans<<endl;
    return 0;
}
