/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        int consecutive = 0;

        for (int num : arr)
        {
            if (num & 1 == 1) // odd
                ++consecutive;
            else    // even
            {
                consecutive = 0;
                continue;
            }

            if (consecutive == 3)
                return true;
        }
        return false;
        
    }
};
// @lc code=end

