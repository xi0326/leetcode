/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> currentResult;
        sort(candidates.begin(), candidates.end());
        getCombination(candidates, target, currentResult, 0);   // start index from 0

        return finalResult;
    }
    void getCombination(vector<int>& candidates, int target, vector<int>& currentResult, int currentIndex)
    {
        if (target == 0)
        {
            finalResult.push_back(currentResult);
            return;
        }

        for (int i = currentIndex; i < candidates.size(); i++)
        {
            // skip duplicates
            if (i > currentIndex && candidates[i] == candidates[i - 1])
                continue;

            // get new element into currentResult
            if (target - candidates[i] >= 0)
            {
                currentResult.push_back(candidates[i]);
                getCombination(candidates, target - candidates[i], currentResult, i + 1);
                currentResult.pop_back();
            }
        }

    }

    vector<vector<int>> finalResult;
};
// @lc code=end

