/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        int count = 0;
        // set<char> set(allowed.begin(), allowed.end());
        int set[26] = {0};

        for (char c : allowed)
            set[c - 'a'] = 1;
        
        for (string word : words)
        {
            int flag = 0;
            for (char c : word)
            {
                // if the word contains a not allowed character
                // if (set.find(c) == set.end())
                if (set[c - 'a'] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                ++count;
        }

        return count; 
    }
};
// @lc code=end

