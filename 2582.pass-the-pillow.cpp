/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int direction = time / (n - 1);
        int shift = time % (n - 1);

        // direction changes from right to left
        if (direction & 1 == 1)
            return n - shift;
        // direction are not changed
        else    // left to right
            return 1 + shift;
    }
};
// @lc code=end

