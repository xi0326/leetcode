/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        int moves = 0;

        // sort the array
        sort(nums.begin(), nums.end());

        // traverse the input vector
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums.at(i) <= nums.at(i - 1))
            {
                moves += nums.at(i - 1) - nums.at(i) + 1;
                nums[i] = nums.at(i - 1) + 1;   // update nums[i]
            }
        }

        return moves;
    }
};
// @lc code=end

