/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> min_string;

        for (char c : s)
        {
            // if the stack is empty, the following check is not needed
            if (min_string.empty())
                min_string.push(c);
            
            else
            {
                if (c == 'B')
                {
                    if (min_string.top() == 'A')
                        min_string.pop();
                    else
                        min_string.push(c);
                }
                else if (c == 'D')
                {
                    if (min_string.top() == 'C')
                        min_string.pop();
                    else
                        min_string.push(c);
                }
                else
                    min_string.push(c);
            }
        }
        return min_string.size();
    }
};
// @lc code=end