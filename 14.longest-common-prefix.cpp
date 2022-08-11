/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int minStringLength = strs.at(0).length();
        string commonPrefix ="";
        int count = 0;

        for (string str : strs) //find the minimum length of strings
        {
            if (str.length() < minStringLength)
                minStringLength = str.length();
        }
        for (int i = 0; i < minStringLength; i++)   //find the minimum common prefix
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs.at(j).at(i) != strs.at(j + 1).at(i))
                    return commonPrefix;    //return the longest common prefix, since the characters are not all same
            }
            commonPrefix += strs.at(0).at(i);
        }

        return commonPrefix;
    }
};
// @lc code=end

