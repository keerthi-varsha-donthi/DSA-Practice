/*
Problem: You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 
Constraints:
1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Since multiple transactions are allowed, every increase in price 
contributes to the total profit. Instead of finding a single buy-sell pair, 
we add all positive differences between consecutive days.

Approach:
1. Traverse the array from index 1.
2. Compute the difference between the current day's price and previous day's price.
3. If the difference is positive, add it to the profit.
4. Return the total profit.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            int currPro = prices[i]-prices[i-1];
            if(currPro > 0) profit += currPro;
        }

        return profit;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

     OptimalSolution obj;

    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {7,6,4,3,1};

    cout << obj.maxProfit(prices1) << endl; // 7
    cout << obj.maxProfit(prices2) << endl; // 4
    cout << obj.maxProfit(prices3) << endl; // 0
    
    return 0;
}