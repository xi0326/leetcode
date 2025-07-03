/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution 
{
public:
    bool isValid(string str) 
    {
        stack<char> stack_;

        for (char c : str)
        {
            if (!stack_.empty())
            {
                char last = stack_.top();
                if ((last == '[' && c == ']') || (last == '(' && c == ')') || (last == '{' && c == '}'))
                {
                    stack_.pop();
                    continue;
                }
            }
            stack_.push(c);
        }

        return stack_.empty();
    }
};
// @lc code=end

