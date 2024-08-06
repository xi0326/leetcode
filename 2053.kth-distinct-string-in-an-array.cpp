/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
class Solution
{
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> counter;
        for (string& s : arr)
            ++counter[s];
        for (string& s : arr)
        {
            // distinct string
            if (counter[s] == 1)
                --k;
            // means kth
            if (k == 0)
                return s;
        }

        return "";
    }
};
// @lc code=end

