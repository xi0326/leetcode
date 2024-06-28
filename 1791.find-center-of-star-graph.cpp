/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution
{
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int u = edges[0][0], v = edges[0][1];
        if (u == edges[1][0])
            return u;
        else if (u == edges[1][1])
            return u;
        else if (v == edges[1][0])
            return v;
        else    // v == edges[1][1]
            return v;
        
    }
};
// @lc code=end

