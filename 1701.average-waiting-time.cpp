/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        double total_waiting_time = 0;

        // time of chef starts working
        int current = customers[0][0];

        for (vector<int>& customer : customers)
        {
            if (current > customer[0])  // the chef is cooking for other customer
                current += customer[1];

            else    // the chef cooks for the customer immediately
                current = customer[0] + customer[1];

            // current timestamp - the customer arrival time
            total_waiting_time += (current - customer[0]);
        }

        return total_waiting_time / customers.size();
    }
};
// @lc code=end

