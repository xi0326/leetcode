/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        vector<int> row_minimums;
        vector<int> col_maximums(matrix[0].size());
        vector<int> lucky_numbers;

        for (vector<int>& row : matrix)
        {
            // get the min value in the row
            row_minimums.emplace_back(*min_element(row.begin(), row.end()));
            // update the max value in the column
            for (int n = 0; n < row.size(); ++n)
                col_maximums[n] = max(col_maximums[n], row[n]);
        }

        // find the same elements in the both vectors
        for (int m : row_minimums)
        {
            if (find(col_maximums.begin(), col_maximums.end(), m) != col_maximums.end())
                lucky_numbers.emplace_back(m);
        }

        return lucky_numbers;
    }
};
// @lc code=end

