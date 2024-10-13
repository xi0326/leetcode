/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        int count = 0;
        for (char c : s)
        {
            // [ needs a ] to match
            if (c == '[')
                ++count;
            // if c == ] && there is a [ to match
            else if (count > 0)
                --count;
        }

        return (count + 1) / 2;

    }
};
// @lc code=end

