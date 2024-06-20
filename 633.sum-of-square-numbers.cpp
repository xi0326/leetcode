/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a <= sqrt(c); ++a)
        {
            double b = sqrt(c - a * a);
            if (b == int(b))
                return true;
        }
        
        return false;
    }
};
// @lc code=end

