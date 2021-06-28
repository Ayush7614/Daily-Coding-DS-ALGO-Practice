/*   
 
Question description : 
 
 You are a game designer and want to make an obstacle course. The player will walk
 from left to right. You have 𝑛 heights of mountains already selected and want to
 arrange them so that the absolute difference of the heights of the first and last
 mountains is as small as possible.
 
 In addition, you want to make the game difficult, and since walking uphill or flat
 is harder than walking downhill, the difficulty of the level will be the number of
 mountains 𝑖 (1≤i<n) such that ℎ𝑖≤ℎ𝑖+1  , ℎ𝑖 is the height of the 𝑖-th mountain. You
 don't want to waste any of the mountains you modelled, so you have to use all of
 them.
 
 From all the arrangements that minimize |ℎ1−ℎ𝑛| find one that is the most
 difficult. If there are multiple orders that satisfy these requirements, you may
 find any.
  
 Input
 
 The first line will contain a single integer 𝑡(1≤𝑡≤100) — the number of test
 cases. Then 𝑡 test cases follow.
 
 The first line of each test case contains a single integer
 𝑛(2≤𝑛≤2⋅10^5) the number of mountains.
 
 The second line of each test case contains 𝑛 integers ℎ1,…,ℎ𝑛 (1≤ℎ𝑖≤10^9) where ℎ𝑖
 is the height of the 𝑖th mountain. It is guaranteed that the sum of 𝑛 over all
 test cases does not exceed 2⋅10^5
  
 Output
 
 For each test case, output 𝑛 integers — the given heights in an order that
 maximizes the difficulty score among all orders that minimize |ℎ1−ℎ𝑛| If there are
 multiple orders that satisfy these requirements, you may output any.
  
 Example
 input:
 2
 4
 4 2 1 2
 2
 3 1
  
 output :
 2 4 1 2
 1 3
  
 Note
 In the first test case:
 
 The player begins at height 2, next going up to height 4 increasing the difficulty
 by 1. After that he will go down to height 1 and the difficulty doesn't change
 because he is going downhill. Finally the player will go up to height 2 and the
 difficulty will increase by 1. The absolute difference between the starting height
 and the end height is equal to 0 and it's minimal. The difficulty is maximal.
 
 In the second test case:
 
 The player begins at height 1, next going up to height 3 increasing the difficulty
 by 1. The absolute difference between the starting height and the end height is
 equal to 2 and it's minimal as they are the only heights. The difficulty is
 maximal.

 */

#include <iostream>
#include <iterator>
#include <set>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
typedef unsigned long long ull;


int main(int argc, const char * argv[]){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n = 0;
    
    while(T--){
        
        cin>>n;
        
        long long hills[n];
        for(int i=0; i<n; i++){
            cin>>hills[i];
        }
        
        sort(hills, hills+n);
        long long min = LONG_MAX;
        int store[2] = {0};
        
        if(n==2){
            cout<<hills[0]<<" "<<hills[1]<<"\n";
            continue;
        }
        
        for(int i=1; i<n; i++){
            if(hills[i]==hills[i-1]){
                store[0]=i-1;
                store[1]=i;
                break;
            }
            if(min>hills[i]-hills[i-1]){
                store[0]=i-1;
                store[1]=i;
                min = hills[i]-hills[i-1];
            }
        }

            cout<<hills[store[1]]<<" ";
            for(int i=store[1]+1; i<n; i++){
                cout<<hills[i]<<" ";
            }
            for(int i=0; i<store[0]; i++){
                cout<<hills[i]<<" ";
            }
            cout<<hills[store[0]]<<"\n";
        
    }
    
    return 0;
}
