/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        vector<int> copied_arr = arr;
        unordered_map<int, int> value_to_rank;

        // remove duplicates and sort
        sort(copied_arr.begin(), copied_arr.end());
        auto u = unique(copied_arr.begin(), copied_arr.end());
        copied_arr.erase(u, copied_arr.end());

        // assign the ranks to sorted unique elements
        for (int i = 1; i <= copied_arr.size(); ++i)
            value_to_rank[copied_arr[i - 1]] = i;
            
        // replace the rank to the original array
        for (int i = 0; i < arr.size(); ++i)
            arr[i] = value_to_rank[arr[i]];

        return arr;
    }
};
// @lc code=end

