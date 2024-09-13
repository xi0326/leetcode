/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string merged = "";
        int it = 0;

        while (it < word1.length() && it < word2.length())
        {
            merged = merged + word1[it] + word2[it];
            ++it;
        }

        if (it == word1.length())
            merged += word2.substr(it, word2.length());
        else if (it == word2.length())
            merged += word1.substr(it, word1.length());

        return merged;
    }
};
// @lc code=end

