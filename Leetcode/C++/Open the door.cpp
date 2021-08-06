//Link to the problem
/*
  https://leetcode.com/problems/open-the-lock/
 */

//According to the problem:
//You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.

//AIM: Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

/*Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> mp(deadends.begin(),deadends.end());
        //storing the visited and deadends
        queue<string> q;
        q.push("0000");
        if(mp.count("0000") == 1)
            return -1;//base case
        
        int level = 0;
        while(!q.empty())//bfs traversal
        {
            int n = q.size();
            for(int i=0;i<n;++i)
            {
                string s = q.front();
                if(s == target)
                    return level;
                q.pop();
                vector<string> v = generate_neighbours(s);
                for(string str:v)
                {
                    if(mp.count(str) == 0)
                    {
                        q.push(str);
                        mp.insert(str);
                    }
                }
            }
            level += 1;//counting levels
        }
        return -1;
    }
    vector<string> generate_neighbours(string s)
    {
        vector<string> v;
        for(int i=0;i<4;++i)
        {
            string str1 = s,str2 = s;
            str1[i] = (s[i] == '9')?'0':s[i]+1;//moving clockwise
            str2[i] = (s[i] == '0')?'9':s[i]-1;//moving anticlockwise
            v.push_back(str1);
            v.push_back(str2);
        }
        return v;//returning the minimum total number of turns required to open the lock
    }
};