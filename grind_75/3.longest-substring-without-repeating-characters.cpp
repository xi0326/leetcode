/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, left = 0;
        unordered_map<char, int> hashmap;

        for (int right = 0; right < s.length(); ++right)
        {
            if (hashmap.find(s[right]) == hashmap.end() || hashmap[s[right]] < left)
            {
                hashmap[s[right]] = right;
                ans = max(ans, right - left + 1);
            }
            else
            {
                left = hashmap[s[right]] + 1;
                hashmap[s[right]] = right;
            }
        }


        return ans;
    }
};
// @lc code=end

