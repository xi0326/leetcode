/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
        vector<int> freq(k, 0);

        for (int num : arr)
        {
            int rem = num % k;
            if (rem < 0)
                rem += k;
            ++freq[rem];
        }

        // if the amount of the numbers in the array which can be divided by k is not even
        if (freq[0] % 2 != 0)
            return false;

        for (int i = 1; i <= k / 2; ++i)
        {
            if (freq[i] != freq[k - i])
                return false;
        }

        return true;
    }
};
// @lc code=end

