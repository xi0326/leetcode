/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result = "";
        int result_length = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            // odd case
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if (right - left + 1 > result_length)
                {
                    result_length = right - left + 1;
                    result = s.substr(left, result_length);
                }
                --left;
                ++right;
            }
            // even case
            left = i, right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if (right - left + 1 > result_length)
                {
                    result_length = right - left + 1;
                    result = s.substr(left, result_length);
                }
                --left;
                ++right;
            }
        }

        return result;
        
    }
};
// @lc code=end

