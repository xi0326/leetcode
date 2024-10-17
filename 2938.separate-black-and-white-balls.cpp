/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long swaps = 0;
        int black_count = 0;    // 1's count
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0')    // white ball
                // an ecnountered white ball needs to swap "black_count" times
                swaps += black_count;
            else
                ++black_count;
        }

        return swaps;
    }
};
// @lc code=end

