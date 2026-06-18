/*
Problem: You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: To maximize the profit, we need to buy at the lowest price before 
selling at a higher price. While traversing the array, keep track of the minimum 
price seen so far and calculate the profit that would be obtained by selling
on the current day. The maximum of all such profits is the answer.

Approach:
1. Initialize the minimum price as the first day's price.
2. Traverse the array from left to right.
3. Update the minimum price seen so far.
4. Calculate the profit if we sell on the current day:
    currentProfit = currentPrice - minimumPrice
5. Update the maximum profit if the current profit is larger.
6. Return the maximum profit obtained.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i]-mini);
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
    vector<int> prices2 = {7,6,4,3,1};
    vector<int> prices3 = {5,10,1,8};

    cout << obj.maxProfit(prices1) << endl; // 5
    cout << obj.maxProfit(prices2) << endl; // 0
    cout << obj.maxProfit(prices3) << endl; // 7

    return 0;
}