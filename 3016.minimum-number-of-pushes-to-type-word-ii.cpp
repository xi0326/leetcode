/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> frequencies(26, 0);
        int pushes = 0;
        int multipiler = 1;

        for (char c : word)
            ++frequencies[c - 'a'];
        
        sort(frequencies.begin(), frequencies.end());

        for (int i = 25; i >= 0; --i)
        {
            // all characters in the word are mapped
            if (frequencies[i] == 0)
                break;
            // shift the character to next position
            if (i != 25 && (25 - i) % 8 == 0)
                ++ multipiler;

            pushes += frequencies[i] * multipiler;
        }

        return pushes;
    }
};
// @lc code=end

