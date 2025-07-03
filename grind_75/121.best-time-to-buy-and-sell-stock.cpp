/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int buy_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            // update the bid price
            if (prices[i] < buy_price)
                buy_price = prices[i];
            // get the ask price and update the max_profit
            else if (prices[i] - buy_price > max_profit)
                max_profit = prices[i] - buy_price;
        }

        return max_profit;
    }
};
// @lc code=end

