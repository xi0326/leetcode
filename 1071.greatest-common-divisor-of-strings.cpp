/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // str1 + str2 == str2 + str1 iff str1 and str2 have a gcd
        if (str1 + str2 != str2 + str1)
            return "";
        else
            return str1.substr(0, gcd(str1.length(), str2.length()));
    }
};
// @lc code=end

