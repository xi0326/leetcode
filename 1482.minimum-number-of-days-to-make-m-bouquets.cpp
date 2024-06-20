/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution
{
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        // if (bloomDay.size() < long(m) * long(k))
        //     return -1;

        // binary search
        int left = 0, right = 1e9, ans = -1;
        int mid = left + (right - left) / 2;

        while (left <= right)
        {
            int continus_day = 0, bouquet = 0;
            for (int i = 0; i < bloomDay.size(); ++i)
            {
                if (bloomDay[i] <= mid)
                {
                    ++continus_day;
                    if (continus_day >= k)
                    {
                        ++bouquet;
                        continus_day = 0;
                    }
                    
                }
                else
                    continus_day = 0;
                
            }
            if (bouquet >= m)
            {
                ans = mid;  // record the ans
                right = mid - 1;
            }
            else
                left = mid + 1;
            
            mid = left + (right - left) / 2;
            
        }
        
        return ans;        
    }
};
// @lc code=end

