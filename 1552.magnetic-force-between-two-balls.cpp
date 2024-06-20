/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());

        int max_force = position[position.size() - 1] - position[0];

        // put balls in the front baskets and the end baskets
        if (m == 2)
            return max_force;

        // binary search        
        int left = 1, right = max_force / (m - 1);
        int ans = 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int pos = position[0], balls = 1;

            for (int i = 1; i < position.size(); ++i)
            {
                if (position[i] - pos >= mid)
                {
                    pos = position[i];
                    ++balls;
                }                
            }
            
            if (balls >= m)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};
// @lc code=end

