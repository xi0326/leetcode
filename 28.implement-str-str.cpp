/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0)
            return 0;

        if (haystack.length() < needle.length())
            return -1;
        
        if (haystack.length() == needle.length())
        {
            if (haystack == needle)
                return 0;
            if (haystack != needle)
                return -1;
        }

        return haystack.find(needle);
    }
};
// @lc code=end

