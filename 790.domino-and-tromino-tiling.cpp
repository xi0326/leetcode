/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
    int numTilings(int n)
    {
        int mod_num = 1e9 + 7;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        
        vector<long> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; ++i)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= mod_num;
        }

        return dp.back();

        /*
            dp[1] = 1
            dp[2] = 2
            dp[3] = 5

            dp[n] = dp[n - 1] + dp[n - 2] + 2(dp[n - 3] + dp[n - 4] + ... + dp[0])
                  = dp[n - 1] + dp[n - 3] + dp[n - 2] + dp[n - 3] + 2(dp[n - 4] + ... + dp[0])
                  = dp[n - 1] + dp[n - 3] + dp[n - 1]
                  = 2 * dp[n - 1] + dp[n - 3]
        */
    }
};
// @lc code=end

