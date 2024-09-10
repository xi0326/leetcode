/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int sum = (rolls.size() + n) * mean;
        int difference = sum - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> missings(n);

        // rest rolls can not be in the range 1-6
        if (float(difference) / n > 6.0 || difference / n <= 0)
            return {};
        else
        {
            for (int i = 0; i < n; ++i)
                missings[i] = difference / n;
            
            difference -= difference / n * n;

            for (int i = 0; i < n; ++i)
            {
                if (difference == 0)
                    break;
                while (missings[i] < 6 && difference > 0)
                {
                    ++missings[i];
                    --difference;
                }
            }
        }
        return missings;
    }
};
// @lc code=end

