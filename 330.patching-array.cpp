/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        int index = 0, patch = 0;
        long missing = 1;

        while (missing <= n)
        {
            if (index < nums.size() && nums[index] <= missing)
            {
                missing += nums[index];
                ++index;
            }
            else
            {
                ++patch;
                // add itself
                missing += missing;
            }
        }

        return patch;
    }
};
// @lc code=end