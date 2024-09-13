/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution
{
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        vector<int> results;
        vector<int> prefixXOR(arr.size() + 1, 0);

        // build prefix XOR array
        for (int i = 0; i < arr.size(); ++i)
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];

        for (vector<int>& query : queries)
        {
            // int xor_value = 0; // x xor 0 = x
            // for (int i = query[0]; i <= query[1]; ++i)
            // {
            //     xor_value = xor_value ^ arr[i]; 
            // }
            // prefixXOR 0~query[1] XOR prefixXOR 0~query[0]-1
            results.emplace_back(prefixXOR[query[1] + 1] ^ prefixXOR[query[0]]);
        }

        return results;
    }
};
// @lc code=end

