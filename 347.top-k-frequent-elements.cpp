/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
        vector<int> top_freq;
        vector<pair<int,int>> p;

        for (int n : nums)
            ++freq[n];

        for (auto f : freq)
            p.emplace_back(f.second, f.first);  // frequency, num
        
        // sort in ascending order
        sort(p.begin(), p.end());

        for (int i = p.size() - 1; i >= 0 && k > 0; --i)
        {
            top_freq.emplace_back(p[i].second);
            --k;
        }

        return top_freq;
    }
};
// @lc code=end

