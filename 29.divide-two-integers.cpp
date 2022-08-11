/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == INT_MIN && divisor == -1)   //This is the only case that quoation larger than 2^32-1
            return INT_MAX;
        
        return dividend / divisor;
    }
};
// @lc code=end

