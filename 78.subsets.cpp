/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int subset = 1 << nums.size();  // number of subsets
        vector<vector<int>> subsets(subset);

        for (int i = 0; i < subset; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if ((i >> j) & 1)
                    subsets[i].emplace_back(nums[j]);
            }
        }
        
        return subsets;
    }
};
// @lc code=end

