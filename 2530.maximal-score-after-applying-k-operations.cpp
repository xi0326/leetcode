/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
class Solution
{
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int> queue(nums.begin(), nums.end());
        long long score = 0;

        for (int i = 0; i < k; ++i)
        {
            int x = queue.top();
            score += x;

            // early stop
            if (x == 1)
            {
                // add remaining 1
                score += (k - i - 1);
                break;
            }
            queue.pop();
            // ceil (x/3)
            queue.push((x + 2) / 3);
        }

        return score;
    }
};
// @lc code=end

