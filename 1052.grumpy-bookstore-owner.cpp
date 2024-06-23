/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int max_satisfied = 0;
        // int max_extra_satisfied = 0;
        // vector<int> extra_satisfied_consecutive;


        for (int i = 0; i < customers.size(); ++i)
        {
            if (grumpy[i] == 0)
                max_satisfied += customers[i];
        }
        // for (int i = 0; i < customers.size() - minutes + 1; ++i)
        // {
        //     int extra_satisfied = 0;
        //     for (int j = i; j < i + minutes; ++j)
        //     {
        //         if (grumpy[j] == 1)
        //             extra_satisfied += customers[j];
        //     }
        //     // extra_satisfied_consecutive.emplace_back(extra_satisfied);
        //     max_extra_satisfied = max(extra_satisfied, max_extra_satisfied);
        // }

        // initialize slide window
        int extra_satisfied = 0;
        for (int i = 0;i < minutes; ++i)
        {
            if (grumpy[i] == 1)
                extra_satisfied += customers[i];
        }

        // slide window
        int max_extra_satisfied = extra_satisfied;
        for (int i = minutes;i < customers.size(); ++i)
        {
            if (grumpy[i - minutes] == 1)
                extra_satisfied -= customers[i - minutes];
            
            if (grumpy[i] == 1)
                extra_satisfied += customers[i];

            max_extra_satisfied = max(max_extra_satisfied, extra_satisfied);
        }
        
        // auto extra_satisfied = max_element(extra_satisfied_consecutive.begin(), extra_satisfied_consecutive.end());
        
        // max_satisfied += *extra_satisfied;

        
        max_satisfied += max_extra_satisfied;

        return max_satisfied;
    }
};
// @lc code=end