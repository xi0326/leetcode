/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        vector<int> count(nums.size() + 1, 0);
        int ans = 0, index = 0;
        count[0] = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            index += nums[i] & 1;
            if (index - k >= 0)
                ans += count[index - k];
            
            ++count[index];
        }

        return ans;
        
    }
};
// @lc code=end

