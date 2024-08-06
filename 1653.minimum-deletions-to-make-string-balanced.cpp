/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        vector<int> min_del(s.size() + 1, 0);
        int b = 0;

        // greedy
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'b')
            {
                min_del[i + 1] = min_del[i];
                ++b;
            }
            else    // a
                min_del[i + 1] = min(min_del[i] + 1, b);
        }

        return min_del.back();
    }
};
// @lc code=end

