/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s2 = "";

        for (char c : s)
        {
            if (islower(c))
                s2 += c;
            else if (isupper(c))
                s2 += tolower(c);
            else if (isdigit(c))
                s2 += c;           
        }

        for (int i = 0, j = s2.length() - 1; i < j; ++i, --j)
        {
            if (s2[i] != s2[j])
                return false;
        }
        
        return true;
        
    }
};
// @lc code=end

