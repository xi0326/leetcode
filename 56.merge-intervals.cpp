/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
                merged.emplace_back(interval);

            // there is overlap, adjust the merge the current and previous interval
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);

        }

        return merged;
        
    }
};
// @lc code=end

