/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int, int>> projects;
        int max_profit = 0;

        // bind the difficulty and profit
        for (int i = 0; i < difficulty.size(); ++i)
            projects.emplace_back(difficulty[i], profit[i]);

        sort(projects.begin(), projects.end());
        sort(worker.begin(), worker.end());

        int index = 0, max_available_profit = 0;

        for (int i = 0; i < worker.size(); ++i)
        {
            while (index < projects.size() && projects[index].first <= worker[i])
            {   
                // update the max available profit
                max_available_profit = max(max_available_profit, projects[index].second);
                ++index;
            }
            max_profit += max_available_profit;
        }

        return max_profit;
    }
};
// @lc code=end