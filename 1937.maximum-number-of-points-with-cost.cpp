/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution
{
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int row = points.size();
        int col = points[0].size();
        vector<long long> dp(col, 0);

        for (int r = 0; r < row; ++r)
        {
            // update the matrix
            for (int c = 0; c < col; ++c)
                dp[c] += points[r][c];
            
            // left to right pass
            for (int c = 1; c < col; ++c)
                dp[c] = max(dp[c], dp[c - 1] - 1);  // 1 is the cost

            // right to left pass
            for (int c = col - 2; c >= 0; --c)
                dp[c] = max(dp[c], dp[c + 1] - 1);  // 1 is the cost
        }
        

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end