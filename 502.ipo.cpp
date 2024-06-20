/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        vector<pair<int, int>> projects;
        priority_queue<int> available_profits;

        // bind the captials and the profits
        for (int i = 0; i < capital.size(); ++i)
            projects.emplace_back(capital[i], profits[i]);

        sort(projects.begin(), projects.end());

        int index = 0;

        for (int i = 0; i < k; ++i)
        {
            // The issue with using static int j in the for loop is that static makes j retain its value between different calls to the function.
            // for (static int j = 0; j < projects.size() && projects[j].first <= w; ++j)
            //     available_profits.push(projects[j].second);

            while (index < projects.size() && projects[index].first <= w)
            {
                available_profits.push(projects[index].second);
                ++index;
            }
            
            // if there is no available project
            if (available_profits.empty())
                break;

            // get the highest available profit
            w += available_profits.top();
            available_profits.pop();
        }
        return w;
    }
};