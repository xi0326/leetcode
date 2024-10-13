/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int moves = 0;
        int opening_parenthesis_waiting = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                ++opening_parenthesis_waiting;
                ++moves;      
            }
            // c == ')'
            else
            {
                // closing and opening parenthesis is matched
                if (opening_parenthesis_waiting > 0)
                {
                    --moves;
                    --opening_parenthesis_waiting;
                }
                else
                    ++moves;
            }
        }

        return moves;
    }
};
// @lc code=end

