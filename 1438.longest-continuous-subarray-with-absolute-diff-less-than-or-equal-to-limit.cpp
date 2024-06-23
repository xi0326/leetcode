/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int max_length = 1, left = 0;
        deque<int> decrease;
        deque<int> increase;

        for (int right = 0; right < nums.size(); ++right)
        {
            // keep the back is the biggest
            while (!increase.empty() && nums[right] < increase.back())
                increase.pop_back();
            increase.push_back(nums[right]);

            // keep the front is the biggest
            while (!decrease.empty() && nums[right] > decrease.back())
                decrease.pop_back();
            decrease.push_back(nums[right]);

            // adjust the window until < limit
            while (decrease.front() - increase.front() > limit)
            {
                if (decrease.front() == nums[left])
                    decrease.pop_front();
                if (increase.front() == nums[left])
                    increase.pop_front();

                ++left;
            }
            // update the max length
            max_length = max(max_length, right - left + 1);
        }
         
        return max_length;
    }
};
// @lc code=end

