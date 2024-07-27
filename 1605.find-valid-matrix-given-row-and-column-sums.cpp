/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
    {
        // init
        vector<vector<int>> result(rowSum.size(), vector<int>(colSum.size(), 0));
        int i = 0, j = 0;

        while (i < rowSum.size() && j < colSum.size())
        {
            int value = min(rowSum[i], colSum[j]);
            result[i][j] = value;
            rowSum[i] -= value;
            colSum[j] -= value;

            if (rowSum[i] == 0) // shift to next row
                ++i;
            if (colSum[j] == 0) // shift to next column
                ++j;
        }
        
        return result;
    }
};
// @lc code=end

