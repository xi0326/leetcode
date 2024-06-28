/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        long long max_importance = 0;
        vector<int> degree(n, 0);

        // create degree vector
        for (const vector<int>& road : roads)
        {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        sort(degree.begin(), degree.end());

        // calc importance
        for (long i = n; i > 0; --i)
            max_importance += i * degree[i - 1];
        
        return max_importance;
    }
};
// @lc code=end

