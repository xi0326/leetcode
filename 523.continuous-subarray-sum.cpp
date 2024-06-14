/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> reminder_map;

        int sum = 0;

        // initialize the reminder_map
        reminder_map[0] = -1;

        // iterate the list
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int reminder;

            if (k == 0)
                return false;
            else
                reminder = sum % k;

            if (reminder_map.count(reminder))
            {
                // length at least 2
                if (i - reminder_map[reminder] > 1)
                {
                    return true;
                }
            }
            else
            {
                reminder_map[reminder] = i;
            }
        }

        return false;
    }
};
// @lc code=end

