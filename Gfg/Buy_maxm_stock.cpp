// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the maximum number of stocks a customer can buy.


// For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.


// Examples:

// Input : price[] = { 10, 7, 19 }, 
//               k = 45.
// Output : 4
// A customer purchases 1 stock on day 1, 
// 2 stocks on day 2 and 1 stock on day 3 for 
// 10, 7 * 2 = 14 and 19 respectively. Hence, 
// total amount is 10 + 14 + 19 = 43 and number 
// of stocks purchased is 4.

// Input  : price[] = { 7, 10, 4 }, 
//                k = 100.
// Output : 6

// The idea is to use greedy approach, where we should start buying product from the day when the stock price is least and so on.
// So, we will sort the pair of two values i.e { stock price, day } according to the stock price, and if stock prices are same, then we sort according to the day.
// Now, we will traverse along the sorted list of pairs, and start buying as follows:
// Let say, we have R rs remaining till now, and the cost of product on this day be C, and we can buy atmost L products on this day then,
// total purchase on this day (P) = min(L, R/C)
// Now, add this value to the answer.
// total purchase on this day (P) = min(L, R/C)
// Now, add this value to the answer
// total_purchase = total_purchase + P, where P =min(L, R/C)
// Now, subtract the cost of buying P items from remaining money, R = R – P*C.
// Total number of products that we can buy is equal to total_purchase.

// Below is C++ implementation of this approach:





#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
  int totalPrice, no_stocks, each_stockPrice;

  cin >> totalPrice >> no_stocks;
  vector<pair<int, int>> price;
  for (int i = 0; i < no_stocks; i++)
  {
    cin >> each_stockPrice;
    price.push_back(make_pair(each_stockPrice,i + 1));
  }
 
  

  sort(price.begin(), price.end());
for (int i = 0; i < no_stocks; i++)
  {
    cout<<price[i].first << " " << price[i].second<<endl;
  }
  int ans = 0;
 
  for (int i = 0; i < no_stocks; i++)
  {
    ans += min(price[i].second, totalPrice / price[i].first);
    totalPrice -= min(price[i].second, totalPrice / price[i].first) * price[i].first;
    cout<<ans<<endl;
  }
  cout << ans << endl;
  return 0;
}