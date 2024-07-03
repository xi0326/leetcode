/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution
{
public:
    int minDifference(vector<int>& nums)
    {
        // all values can be changed to the same value
        if (nums.size() <= 4)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        // change last 3 elements
        int min_value = nums[nums.size() - 4] - nums[0];
        // change first 1 and last 2 elements
        min_value = min(min_value, nums[nums.size() - 3] - nums[1]);
        // change first 2 and last 1 elements
        min_value = min(min_value, nums[nums.size() - 2] - nums[2]);
        // change the first 3 elements
        min_value = min(min_value, nums[nums.size() - 1] - nums[3]);

        return min_value;
    }
};
// @lc code=end

