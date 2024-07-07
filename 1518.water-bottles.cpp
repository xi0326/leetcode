/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int max_drink = numBottles;
        while (numBottles >= numExchange)
        {
            // the new bottles from the market
            int exchange_bottles = numBottles / numExchange;
            // update the count of empty bottles
            numBottles = exchange_bottles + numBottles % numExchange;
            max_drink += exchange_bottles;
        }
        
        return max_drink;
    }
};
// @lc code=end