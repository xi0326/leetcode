/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        // only one person in the town
        if (n == 1 && trust.size() == 0)
            return 1;

        vector<int> in_degree(n + 1, 0);
        vector<int> out_degree(n + 1, 0);

        int max_trust = 0;
        int max_pos = 0;

        for (auto t : trust)
        {
            ++in_degree[t[1]];
            ++out_degree[t[0]];
            if (in_degree[t[1]] > max_trust)
            {
                max_trust = in_degree[t[1]];
                max_pos = t[1];
            }
        }

        if (max_trust == n - 1 && out_degree[max_pos] == 0)
            return max_pos;
        else
            return -1;


    }
};
// @lc code=end

