/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        // combine two sentences
        string s = s1 + " " + s2;
        stringstream ss(s);
        unordered_map<string, int> map;
        string temp;

        while (ss >> temp)
            ++map[temp];

        // check if the word only appears once
        vector<string> uncommon;
        for (auto& word : map)
        {
            // appears only once
            if (word.second == 1)
                uncommon.emplace_back(word.first);
        }

        return uncommon;
    }
};
// @lc code=end

