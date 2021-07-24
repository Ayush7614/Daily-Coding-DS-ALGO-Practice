//Link to the problem
/*
   https://leetcode.com/problems/fruit-into-baskets/
 */

//According to the problem:

//Given the integer array fruits

//AIM: Return the maximum number of fruits you can pick.

//NOTE: You only have two baskets, and each basket can only hold a single type of fruit. No limit on amount of fruit each basket can hold,you must pick exactly one fruit from every tree while moving to the right.

/*Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
*/

class Solution {
public:
   int totalFruit(vector<int>& fruits) {
        set<int>s;
        //to keep track of total diffrent types of fruits available
        for(int i : fruits) s.insert(i);
        //inserting into set
        if(s.size()<=2) return fruits.size();
        //if size is less than 2 we can add all the types
        fruits.push_back(100001);
        int n=fruits.size();
        int j=0;
        int total=0;
        vector<int>f(100005);
        //to fit under given range
        int maxi=0;
        for(int i=0;i<n;i++){
            if(f[fruits[i]]==0 && total==2)//if we got new fruit but tot number of baskets are already used
            {
                maxi=max(maxi,i-j);
                //saving max
                // moving the left pointer
                while(j<i){
                    if(f[fruits[j]]>1) f[fruits[j]]-- , j++;
                    else if(f[fruits[j]]==1){
                        f[fruits[j]]--;
                        j++;
                        break;
                    }
                }
                f[fruits[i]]++; //increasing freq of the fruit
            }
            else if(f[fruits[i]]==0) //new fruit found
            {
                total++;
                f[fruits[i]]++;
            }
            else f[fruits[i]]++; //tot<2 more fruits can be added
        }
        return maxi;//returning max number of fruits you can pick.
    }
};