/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        addParenthesis(result, n, 0, "");

        return result;
    }

    void addParenthesis(vector<string> &res, int left, int right, string str)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(str); //parenthesis is generated
            return;
        }
        if (left > 0)
            addParenthesis(res, left - 1, right + 1, str + "(");
        
        if (right > 0)
            addParenthesis(res, left, right - 1, str + ")");
    }
};
// @lc code=end

