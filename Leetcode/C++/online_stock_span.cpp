/* Problem Statement :
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.
The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.
For example,
        Input:  [ 100 , 80 , 60 , 70 , 60 , 75 , 85 ]
        Output: [   1 ,  1 ,  1 ,  2 ,  1 , 4  , 6 ]
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;                   // pair of price and its sum of greater or equal elements before currrent element
    
public:    
    int next(int price) {
        int sum = 1;
        
        while(!st.empty() and st.top().first <= price){
            sum += st.top().second;             
            st.pop();                           // element removed till we get greater element than the current element
        }

        st.push(make_pair(price, sum));
        return sum;  
    }
};


int main(){
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    
    StockSpanner span;
    
    for(int i = 0 ; i < a.size(); i++){
        cout<< span.next(a[i])<<" ";
    }

    return 0;
}
